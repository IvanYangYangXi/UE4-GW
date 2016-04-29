// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "UMGPrivatePCH.h"

#define LOCTEXT_NAMESPACE "UMG"

/////////////////////////////////////////////////////
// UScaleBox

UScaleBox::UScaleBox(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bIsVariable = false;
	Visibility = ESlateVisibility::SelfHitTestInvisible;

	StretchDirection = EStretchDirection::Both;
	Stretch = EStretch::ScaleToFit;
	UserSpecifiedScale = 1.0f;
	IgnoreInheritedScale = false;
}

void UScaleBox::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);

	MyScaleBox.Reset();
}

TSharedRef<SWidget> UScaleBox::RebuildWidget()
{
	MyScaleBox = SNew(SScaleBox);
	
	if ( GetChildrenCount() > 0 )
	{
		Cast<UScaleBoxSlot>(GetContentSlot())->BuildSlot(MyScaleBox.ToSharedRef());
	}

	return BuildDesignTimeWidget( MyScaleBox.ToSharedRef() );
}

void UScaleBox::SetStretch(EStretch::Type InStretch)
{
	Stretch = InStretch;
	if(MyScaleBox.IsValid())
	{
		MyScaleBox->SetStretch(InStretch);
	}
}

void UScaleBox::SetStretchDirection(EStretchDirection::Type InStretchDirection)
{
	StretchDirection = InStretchDirection;
	if (MyScaleBox.IsValid())
	{
		MyScaleBox->SetStretchDirection(InStretchDirection);
	}
}

void UScaleBox::SetUserSpecifiedScale(float InUserSpecifiedScale)
{
	UserSpecifiedScale = InUserSpecifiedScale;
	if (MyScaleBox.IsValid())
	{
		MyScaleBox->SetUserSpecifiedScale(InUserSpecifiedScale);
	}
}

void UScaleBox::SetIgnoreInheritedScale(bool bInIgnoreInheritedScale)
{
	IgnoreInheritedScale = bInIgnoreInheritedScale;
	if (MyScaleBox.IsValid())
	{
		MyScaleBox->SetIgnoreInheritedScale(bInIgnoreInheritedScale);
	}
}

void UScaleBox::SynchronizeProperties()
{
	Super::SynchronizeProperties();

	MyScaleBox->SetStretchDirection(StretchDirection);
	MyScaleBox->SetStretch(Stretch);
	MyScaleBox->SetUserSpecifiedScale(UserSpecifiedScale);
	MyScaleBox->SetIgnoreInheritedScale(IgnoreInheritedScale);
}

UClass* UScaleBox::GetSlotClass() const
{
	return UScaleBoxSlot::StaticClass();
}

void UScaleBox::OnSlotAdded(UPanelSlot* Slot)
{
	// Add the child to the live slot if it already exists
	if ( MyScaleBox.IsValid() )
	{
		Cast<UScaleBoxSlot>(Slot)->BuildSlot(MyScaleBox.ToSharedRef());
	}
}

void UScaleBox::OnSlotRemoved(UPanelSlot* Slot)
{
	// Remove the widget from the live slot if it exists.
	if ( MyScaleBox.IsValid() )
	{
		MyScaleBox->SetContent(SNullWidget::NullWidget);
	}
}

#if WITH_EDITOR

const FText UScaleBox::GetPaletteCategory()
{
	return LOCTEXT("Panel", "Panel");
}

#endif

/////////////////////////////////////////////////////

#undef LOCTEXT_NAMESPACE
