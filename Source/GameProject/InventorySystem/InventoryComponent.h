// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

class AEquippableItem;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInventoryUpdated);

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class GAMEPROJECT_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UInventoryComponent();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable)
	bool AddItem(AEquippableItem* item, int slot);

	UFUNCTION(BlueprintCallable)
	bool RemoveItem(AEquippableItem* item, int slot);

	UPROPERTY(BlueprintAssignable, Category = "Inventory")
	FOnInventoryUpdated OnInventoryUpdated;

	UPROPERTY(EditDefaultsOnly, Category = "Inventory")
	int32 WeaponCapacity;

	UPROPERTY(EditDefaultsOnly, Category = "Inventory")
	int32 ArmorCapacity;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Items")
	TArray<AEquippableItem*> WeaponStorage;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Items")
	TArray<AEquippableItem*> ArmorStorage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Items")
	TArray<AEquippableItem*> DefaultItems;

private:
	bool AddWeapon(AEquippableItem *item, int slot);
	bool AddArmor(AEquippableItem *item, int slot);

	bool RemoveWeapon(AEquippableItem *item, int slot);
	bool RemoveArmor(AEquippableItem *item, int slot);
};
