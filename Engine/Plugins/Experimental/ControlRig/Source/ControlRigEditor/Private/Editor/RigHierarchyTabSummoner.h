// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "WorkflowOrientedApp/WorkflowTabFactory.h"

class FControlRigEditor;

struct FRigHierarchyTabSummoner : public FWorkflowTabFactory
{
public:
	static const FName TabID;
	
public:
	FRigHierarchyTabSummoner(const TSharedRef<FControlRigEditor>& InControlRigEditor);
	
	virtual TSharedRef<SWidget> CreateTabBody(const FWorkflowTabSpawnInfo& Info) const override;
	
protected:
	TWeakPtr<FControlRigEditor> ControlRigEditor;
};
