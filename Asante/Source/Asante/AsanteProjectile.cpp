// Fill out your copyright notice in the Description page of Project Settings.


#include "AsanteProjectile.h"

#include "AsanteCombatInterface.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AAsanteProjectile::AAsanteProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    // Use a sphere as a simple collision representation
    CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
    CollisionComp->InitSphereRadius(5.0f);
    CollisionComp->BodyInstance.SetCollisionProfileName("Projectile");
    CollisionComp->OnComponentBeginOverlap.AddDynamic(this, &AAsanteProjectile::OnHit);        // set up a notification for when this component hits something blocking

    // Players can't walk on it
    CollisionComp->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.f));
    CollisionComp->CanCharacterStepUpOn = ECB_No;

    // Set as root component
    RootComponent = CollisionComp;

    // Use a ProjectileMovementComponent to govern this projectile's movement
    ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp"));
    ProjectileMovement->UpdatedComponent = CollisionComp;
    ProjectileMovement->InitialSpeed = 3000.f;
    ProjectileMovement->MaxSpeed = 3000.f;
    ProjectileMovement->bRotationFollowsVelocity = true;
    ProjectileMovement->bShouldBounce = true;

    // Create Static Mesh Component
    StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
    StaticMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
    StaticMesh->SetupAttachment(RootComponent);

    // Die after 3 seconds by default
    InitialLifeSpan = 3.0f;
	BaseDamage = 25.f;
}

// Called when the game starts or when spawned
void AAsanteProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAsanteProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int32 AAsanteProjectile::GetOwnerTeamId() const
{
	if (const auto CombatOwner = Cast<IAsanteCombatInterface>(GetOwner()))
		return CombatOwner->GetTeamId();

	return -1;
}

int32 AAsanteProjectile::GetTeamId() const
{
	return GetOwnerTeamId();
}

bool AAsanteProjectile::GetIsTargetable() const
{
	return false;
}

float AAsanteProjectile::GetHealth() const
{
	return 0.f;
}

float AAsanteProjectile::GetHealthMax() const
{
	return 0.f;
}

void AAsanteProjectile::SetHealth(float Value)
{
}

void AAsanteProjectile::SetHealthMax(float Value)
{
}

void AAsanteProjectile::Splode()
{
	BP_OnSplode();
	Destroy();
}

void AAsanteProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIdx, bool sweep, const FHitResult& Hit)
{
	// Don't hit friendlies.
	if (const auto CombatUnit = Cast<IAsanteCombatInterface>(OtherActor))
	{
		if (CombatUnit->GetTeamId() == GetOwnerTeamId())
			return;
	}

	UGameplayStatics::ApplyDamage(OtherActor, BaseDamage, GetInstigatorController(), this, nullptr); // TODO: Damage type class maybe?
	Splode();
}

