// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "NPC_AI.generated.h"

/**
 * 
 */
UCLASS()
class ASSIGNMENT_API ANPC_AI : public AAIController
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		bool isFriendly = true;
		
public:
	ANPC_AI();
	
private:
	FGenericTeamId TeamId;
public:
	virtual FGenericTeamId GetGenericTeamId() const override { return TeamId; }
	virtual ETeamAttitude::Type GetTeamAttitudeTowards(AActor& Other);
	
};

