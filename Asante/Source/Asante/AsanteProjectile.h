// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AsanteCombatInterface.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"
#include "AsanteProjectile.generated.h"

UCLASS()
class ASANTE_API AAsanteProjectile : public AActor, public IAsanteCombatInterface
{
	GENERATED_BODY()
	
public:	
	AAsanteProjectile();
	virtual void Tick(float DeltaTime) override;

	int32 GetOwnerTeamId() const;

	virtual int32 GetTeamId() const override;
	virtual bool GetIsTargetable() const override;
	virtual float GetHealth() const override;
	virtual float GetHealthMax() const override;
	virtual void SetHealth(float Value) override;
	virtual void SetHealthMax(float Value) override;
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float BaseDamage;

	virtual void BeginPlay() override;
	virtual void Splode();

	UFUNCTION(BlueprintImplementableEvent, DisplayName="On Splode")
	void BP_OnSplode();
	
	/*Projectile OnHit*/
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIdx, bool sweep, const FHitResult& Hit);
	/** Sphere collision component */
	UPROPERTY(VisibleDefaultsOnly, Category=Projectile)
	USphereComponent* CollisionComp;

	/** Projectile movement component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	UProjectileMovementComponent* ProjectileMovement;

	/** Static Mesh component */
	UPROPERTY(Category = StaticMeshActor, VisibleAnywhere, BlueprintReadOnly, meta = (ExposeFunctionCategories = "Mesh,Rendering,Physics,Components|StaticMesh", AllowPrivateAccess = "true"))	
	UStaticMeshComponent *StaticMesh;

	/**Niagara Explosion Particle System Component*/
	UPROPERTY(Category = ParticleSystem, VisibleAnywhere, BlueprintReadOnly)
	UNiagaraComponent* ExplosionFX;


};
