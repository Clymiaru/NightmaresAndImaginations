// Fill out your copyright notice in the Description page of Project Settings.


#include "EquippableItem.h"

AEquippableItem::AEquippableItem()
{
	PrimaryActorTick.bCanEverTick = false;

	hasStatsBeenProcessed = false;
}

void AEquippableItem::BeginPlay()
{
	Super::BeginPlay();
}

void AEquippableItem::Equip(UInventoryComponent* inventory)
{
	// Set reference to the player / pawn that can equip that will equip the item
	// TODO: Stat modification

	if (!hasStatsBeenProcessed)
	{
		OnEquip();
		hasStatsBeenProcessed = true;
	}
}

void AEquippableItem::Unequip(UInventoryComponent* inventory)
{
	OnUnequip();
	hasStatsBeenProcessed = false;
}

