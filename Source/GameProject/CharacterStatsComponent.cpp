// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterStatsComponent.h"

// Sets default values for this component's properties
UCharacterStatsComponent::UCharacterStatsComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCharacterStatsComponent::BeginPlay()
{
	Super::BeginPlay();

	
	if (this->GetOwner() != nullptr)
	{
		this->GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UCharacterStatsComponent::TakeDamage);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("(Class UCharacterStatsComponent) 'owner' is not initialized!"));
	}
	
	
	if (this->hitBox != nullptr)
	{
		this->hitBox->OnComponentBeginOverlap.AddDynamic(this, &UCharacterStatsComponent::OnOverlapBegin);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("(Class UCharacterStatsComponent) 'hitBox' is not initialized!"));
	}


	this->charMaxHp = 100.0f;
	this->currHp = this->charMaxHp;
	this->weaponDamage = 5.0f;
	// ...
	
}

void UCharacterStatsComponent::TakeDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	UE_LOG(LogTemp, Warning, TEXT("%s took  %f damage!!"), *this->GetOwner()->GetName(), Damage);
	if (Damage <= 0)
	{
		return;
	}

	this->currHp = FMath::Clamp(this->currHp - Damage, 0.f, this->charMaxHp);
}

UFUNCTION(BlueprintCallable) void UCharacterStatsComponent::HealCharacter(float healAmount)
{
	//return UFUNCTION(BlueprintCallable) void();

	this->currHp = FMath::Clamp(this->currHp + healAmount, 0.f, this->charMaxHp);

}

void UCharacterStatsComponent::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (this->GetOwner()->ActorHasTag("Player"))
	{
		if (OtherActor->ActorHasTag("Enemy") && OtherActor != this->GetOwner())
		{
			//UE_LOG(LogTemp, Warning, TEXT("I deal damage!! with name %s"), *OtherActor->GetName());
			UGameplayStatics::ApplyDamage(OtherActor, this->weaponDamage, this->GetOwner()->GetInstigatorController(), this->GetOwner(), nullptr);
		}
	}
	
	if (this->GetOwner()->ActorHasTag("Enemy"))
	{
		//UE_LOG(LogTemp, Warning, TEXT("I am enemy"));
		if (OtherActor->ActorHasTag("Player") && OtherActor != this->GetOwner())
		{
			UE_LOG(LogTemp, Warning, TEXT("I am enemy"));
			//UE_LOG(LogTemp, Warning, TEXT("I deal damage!! with name %s"), *OtherActor->GetName());
			UGameplayStatics::ApplyDamage(OtherActor, this->weaponDamage, this->GetOwner()->GetInstigatorController(), this->GetOwner(), nullptr);
		}
	}

}



// Called every frame
void UCharacterStatsComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	//UE_LOG(LogTemp, Warning, TEXT("%f hp!"), this->currHp);
	// ...
}

