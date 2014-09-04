// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "WidgetTransform.generated.h"

/**
 * Describes the standard transformation of a widget
 */
USTRUCT(BlueprintType)
struct FWidgetTransform
{
	GENERATED_USTRUCT_BODY()

	/** The scale to apply to the widget */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Transform, meta=( UIMin = "-5", UIMax = "5", Delta = "0.05" ))
	FVector2D Scale;

	/** The amount to shear the widget in slate units */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Transform, meta=( UIMin = "-89", ClampMin = "-89", UIMax = "89", ClampMax = "89", Delta = "1" ))
	FVector2D Shear;
	
	/** The angle in degrees to rotate */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Transform, meta=( UIMin = "-180", UIMax = "180", Delta = "1" ))
	float Angle;
	
	/** The amount to translate the widget in slate units */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Transform, meta=( Delta = "1" ))
	FVector2D Translation;

	FWidgetTransform()
		: Scale(1, 1)
		, Shear(0, 0)
		, Angle(0)
		, Translation(0, 0)
	{
	}
};
