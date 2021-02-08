// Fill out your copyright notice in the Description page of Project Settings.

#include "InventoryComponent.h"

#include "EquippableItem.h"
#include "Item.h"

UInventoryComponent::UInventoryComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	WeaponStorage.Reserve(WeaponCapacity);
	for (int i = 0; i < WeaponCapacity; i++)
	{
		WeaponStorage[i] = nullptr;
	}

	ArmorStorage.Reserve(ArmorCapacity);
	for (int i = 0; i < ArmorCapacity; i++)
	{
		ArmorStorage[i] = nullptr;
	}
}

 bool UInventoryComponent::AddItem(AEquippableItem *item, int slot)
 {
	if (item == nullptr)
	{
		return false;
	}

 	switch (item->Type)
 	{
 		case EquipmentType::Weapon:
 			AddWeapon(item, slot);
 			break;
 		case EquipmentType::Armor:
 			AddArmor(item, slot);
 			break;
 		default:
 			UE_LOG(LogActorComponent, Warning, TEXT("Item type undefined!"));
 			break;
 	}

	item->Equip(this);

 	OnInventoryUpdated.Broadcast();

 	return true;
}

bool UInventoryComponent::AddWeapon(AEquippableItem* item, int slot)
{
	if (slot >= WeaponCapacity ||
		slot < 0 ||
		item == nullptr)
	{
		return false;
	}

	if (WeaponStorage[slot] != nullptr)
	{
		RemoveItem(item, slot);
	}

	WeaponStorage[slot] = item;
	return true;
}

bool UInventoryComponent::AddArmor(AEquippableItem* item, int slot)
{
	if (slot >= ArmorCapacity ||
        slot < 0 ||
        item == nullptr)
	{
		return false;
	}

	if (ArmorStorage[slot] != nullptr)
	{
		RemoveItem(item, slot);
	}

	ArmorStorage.Add(item);
	return true;
}

bool UInventoryComponent::RemoveWeapon(AEquippableItem* item, int slot)
{
	if (item == nullptr)
	{
		return false;
	}

	return true;
}

bool UInventoryComponent::RemoveArmor(AEquippableItem* item, int slot)
{
	if (item == nullptr)
	{
		return false;
	}

	return true;
}

bool UInventoryComponent::RemoveItem(AEquippableItem *item, int slot)
 {
 	if (item == nullptr)
 	{
 		return false;
 	}

	switch (item->Type)
	{
 	case EquipmentType::Weapon:
 		RemoveWeapon(item, slot);
		break;
 	case EquipmentType::Armor:
 		RemoveArmor(item, slot);
		break;
 	default:
 		UE_LOG(LogActorComponent, Warning, TEXT("Item type undefined!"));
		break;
	}

 	// item->storedInInventory = nullptr;
 	// Items.RemoveSingle(item);
 	OnInventoryUpdated.Broadcast();
    return true;
}
