// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"

// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
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

