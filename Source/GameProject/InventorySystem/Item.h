// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include <Components/BoxComponent.h>

#include "GameFramework/Actor.h"
#include "Engine/TriggerBox.h"
#include "Item.generated.h"

UCLASS()
class GAMEPROJECT_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
	FText UseActionText;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
	FText Name;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item", meta = (MultiLine = true))
	FText Description;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
	UTexture2D* Icon;

	UPROPERTY(EditAnywhere)
	AActor* Player;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UBoxComponent* PickupVolume;

	
};
