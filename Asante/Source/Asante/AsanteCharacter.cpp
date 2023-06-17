// Asante 2023


#include "AsanteCharacter.h"

// Sets default values
AAsanteCharacter::AAsanteCharacter()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AAsanteCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAsanteCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAsanteCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

