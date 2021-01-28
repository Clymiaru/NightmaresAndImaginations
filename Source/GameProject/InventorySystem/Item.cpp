// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"

AItem::AItem()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AItem::BeginPlay()
{
	Super::BeginPlay();

	PickupVolume = FindComponentByClass<UBoxComponent>();


	if (PickupVolume == nullptr)
	{
		UE_LOG(LogTemp, Display, TEXT("NO PICKUP"));
	}
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (PickupVolume->IsOverlappingActor(Player))
	{
		UE_LOG(LogTemp, Display, TEXT("IN RANGE"));
		Disappear();
	}
}

void AItem::Disappear()
{
	Destroy();
}

