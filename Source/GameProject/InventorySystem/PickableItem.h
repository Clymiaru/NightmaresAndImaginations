// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickableItem.generated.h"

UCLASS()
class GAMEPROJECT_API APickableItem : public AActor
{
private:
	GENERATED_BODY()

public:
	APickableItem();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float deltaTime) override;

	UFUNCTION(BlueprintImplementableEvent)
	void OnPickup();

	UFUNCTION(BlueprintCallable)
	void Pickup();
};
