// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MainPlayerController.generated.h"


/**
 * 
 */
UCLASS()
class GAMEPROJECT_API AMainPlayerController : public APlayerController
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;
	virtual void Tick(float deltaTime) override;
	
	UPROPERTY(BlueprintReadWrite) bool attacking;

private:
	void OnAttack();
	void OnTimerEnd();
};
