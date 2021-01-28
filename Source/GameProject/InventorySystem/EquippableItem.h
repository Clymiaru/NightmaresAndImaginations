// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InventoryComponent.h"

#include "EquippableItem.generated.h"

UCLASS()
class GAMEPROJECT_API AEquippableItem : public AActor
{
	GENERATED_BODY()

public:
	AEquippableItem();

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
	FText Name;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item", meta = (MultiLine = true))
	FText Description;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
	UTexture2D* Icon;

	UFUNCTION(BlueprintImplementableEvent)
	void OnEquip();

	UFUNCTION(BlueprintCallable)
    void Equip(UInventoryComponent* inventory);

	virtual void Tick(float deltaTime) override;

};
