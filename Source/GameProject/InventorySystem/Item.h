// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventoryComponent.h"
#include "UObject/NoExportTypes.h"

#include "Item.generated.h"

/**
 * 
 */
UCLASS(Abstract, BlueprintType, Blueprintable, EditInlineNew, DefaultToInstanced)
class GAMEPROJECT_API UItem : public UObject
{
	GENERATED_BODY()
public:
	UItem();

	//ItemData Properties;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
	FString Name;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item", meta = (MultiLine = true))
	FString Description;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
	UTexture2D* Icon;

	UPROPERTY()
	UInventoryComponent* OwningInventory;

	UFUNCTION(BlueprintImplementableEvent)
	void OnUse(AActor* Character);
};
