// Fill out your copyright notice in the Description page of Project Settings.


#include "PickableItem.h"

APickableItem::APickableItem()
{
	PrimaryActorTick.bCanEverTick = true;
}

void APickableItem::BeginPlay()
{
	Super::BeginPlay();
}

void APickableItem::Tick(float deltaTime)
{
	Super::Tick(deltaTime);
}

void APickableItem::Pickup()
{
	OnPickup();
	Destroy();
}

