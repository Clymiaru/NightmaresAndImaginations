// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InventoryComponent.h"

#include "EquippableItem.generated.h"

UENUM()
enum class EquipmentType
{
	Weapon,
    Armor
};

UCLASS()
class GAMEPROJECT_API AEquippableItem : public AActor
{
	GENERATED_BODY()

public:
	AEquippableItem();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnEquip();

	UFUNCTION(BlueprintImplementableEvent)
    void OnUnequip();

	UFUNCTION(BlueprintCallable)
    void Equip(UInventoryComponent* inventory);

	UFUNCTION(BlueprintCallable)
    void Unequip(UInventoryComponent* inventory);

	inline bool HasStatsProcessed() { return hasStatsBeenProcessed; }

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
	UTexture2D* Icon;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
	FText Name;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item", meta = (MultiLine = true))
	FText Description;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
	EquipmentType Type;

private:
	bool hasStatsBeenProcessed;
};
