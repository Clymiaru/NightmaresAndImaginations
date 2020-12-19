// Fill out your copyright notice in the Description page of Project Settings.

#include "InventoryComponent.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	// for (auto& item : DefaultItems)
	// {
	// 	AddItem(item);
	// }
}

// bool UInventoryComponent::AddItem(UItem *item)
// {
// 	if (Items.Num() >= Capacity || item == nullptr)
// 	{
// 		return false;
// 	}

// 	Items.Add(item);

// 	item->OwningInventory = this;

// 	OnInventoryUpdated.Broadcast();

// 	return true;
// }

// bool UInventoryComponent::RemoveItem(UItem *item)
// {
// 	if (item == nullptr)
// 	{
// 		return false;
// 	}

// 	item->OwningInventory = nullptr;
// 	Items.RemoveSingle(item);
// 	OnInventoryUpdated.Broadcast();
// 	return true;
// }
