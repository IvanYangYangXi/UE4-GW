// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "UMGPrivatePCH.h"

#define LOCTEXT_NAMESPACE "UMG"

/////////////////////////////////////////////////////
// UButton

FName UButton::StyleName(TEXT("Style"));

UButton::UButton(const FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	ButtonStyle = PCIP.CreateDefaultSubobject<UButtonWidgetStyle>(this, StyleName);

	SButton::FArguments ButtonDefaults;
	ButtonStyle->ButtonStyle = *ButtonDefaults._ButtonStyle;

	ColorAndOpacity = FLinearColor::White;
	BackgroundColor = FLinearColor::White;

	ClickMethod = EButtonClickMethod::DownAndUp;
	TouchMethod = EButtonTouchMethod::DownAndUp;

	IsFocusable = true;
}

void UButton::ReleaseNativeWidget()
{
	Super::ReleaseNativeWidget();

	MyButton.Reset();
}

TSharedRef<SWidget> UButton::RebuildWidget()
{
	const FButtonStyle* StylePtr = ( Style != nullptr ) ? Style->GetStyle<FButtonStyle>() : nullptr;
	if ( StylePtr != nullptr )
	{
		ButtonStyle->ButtonStyle = *StylePtr;
	}

	MyButton = SNew(SButton)
		.ButtonStyle(&ButtonStyle->ButtonStyle)
		.ClickMethod(ClickMethod)
		.TouchMethod(TouchMethod)
		.IsFocusable(IsFocusable);

	if ( GetChildrenCount() > 0 )
	{
		Cast<UButtonSlot>(GetContentSlot())->BuildSlot(MyButton.ToSharedRef());
	}
	
	return MyButton.ToSharedRef();
}

void UButton::SynchronizeProperties()
{
	Super::SynchronizeProperties();

	MyButton->SetColorAndOpacity( ColorAndOpacity );
	MyButton->SetBorderBackgroundColor( BackgroundColor );
	
	MyButton->SetOnClicked(BIND_UOBJECT_DELEGATE(FOnClicked, SlateHandleClicked));
}

UClass* UButton::GetSlotClass() const
{
	return UButtonSlot::StaticClass();
}

void UButton::OnSlotAdded(UPanelSlot* Slot)
{
	// Add the child to the live slot if it already exists
	if ( MyButton.IsValid() )
	{
		Cast<UButtonSlot>(Slot)->BuildSlot(MyButton.ToSharedRef());
	}
}

void UButton::OnSlotRemoved(UPanelSlot* Slot)
{
	// Remove the widget from the live slot if it exists.
	if ( MyButton.IsValid() )
	{
		MyButton->SetContent(SNullWidget::NullWidget);
	}
}

void UButton::SetButtonStyle(FButtonStyle InButtonStyle)
{
	ButtonStyle->ButtonStyle = InButtonStyle;
}

FButtonStyle UButton::GetButtonStyle()
{
	return ButtonStyle->ButtonStyle;
}

void UButton::SetColorAndOpacity(FLinearColor Color)
{
	ColorAndOpacity = Color;
	if ( MyButton.IsValid() )
	{
		MyButton->SetColorAndOpacity(Color);
	}
}

void UButton::SetBackgroundColor(FLinearColor Color)
{
	BackgroundColor = Color;
	if ( MyButton.IsValid() )
	{
		MyButton->SetBorderBackgroundColor(Color);
	}
}

bool UButton::IsPressed() const
{
	return MyButton->IsPressed();
}

void UButton::PostLoad()
{
	Super::PostLoad();

	if ( GetChildrenCount() > 0 )
	{
		//TODO UMG Pre-Release Upgrade, now buttons have slots of their own.  Convert existing slot to new slot.
		if ( UPanelSlot* PanelSlot = GetContentSlot() )
		{
			UButtonSlot* ButtonSlot = Cast<UButtonSlot>(PanelSlot);
			if ( ButtonSlot == NULL )
			{
				ButtonSlot = ConstructObject<UButtonSlot>(UButtonSlot::StaticClass(), this);
				ButtonSlot->Content = GetContentSlot()->Content;
				ButtonSlot->Content->Slot = ButtonSlot;
				Slots[0] = ButtonSlot;
			}
		}
	}
}

FReply UButton::SlateHandleClicked()
{
	OnClicked.Broadcast();

	return FReply::Handled();
}

#if WITH_EDITOR

const FSlateBrush* UButton::GetEditorIcon()
{
	return FUMGStyle::Get().GetBrush("Widget.Button");
}

const FText UButton::GetToolboxCategory()
{
	return LOCTEXT("Common", "Common");
}

#endif

/////////////////////////////////////////////////////

#undef LOCTEXT_NAMESPACE
