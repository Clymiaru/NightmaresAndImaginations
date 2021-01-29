// Fill out your copyright notice in the Description page of Project Settings.


#include "MainPlayerController.h"

void AMainPlayerController::BeginPlay()
{
	Super::BeginPlay();

	UInputComponent* inputComponent = this->FindComponentByClass<UInputComponent>();
	inputComponent->BindAction("Attack", EInputEvent::IE_Pressed, this, &AMainPlayerController::OnAttack);

}



void AMainPlayerController::Tick(float deltaTime)
{
	Super::Tick(deltaTime);
}




void AMainPlayerController::OnAttack()
{
	this->attacking = true;
	FTimerHandle timeHandler;
	GetWorld()->GetTimerManager().SetTimer(timeHandler, this, &AMainPlayerController::OnTimerEnd, 0.45f, false);
}

void AMainPlayerController::OnTimerEnd()
{
	this->attacking = false;
}
