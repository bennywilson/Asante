// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Asante/AsanteGameModeBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAsanteGameModeBase() {}
// Cross Module References
	ASANTE_API UClass* Z_Construct_UClass_AAsanteGameModeBase();
	ASANTE_API UClass* Z_Construct_UClass_AAsanteGameModeBase_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_Asante();
// End Cross Module References
	void AAsanteGameModeBase::StaticRegisterNativesAAsanteGameModeBase()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AAsanteGameModeBase);
	UClass* Z_Construct_UClass_AAsanteGameModeBase_NoRegister()
	{
		return AAsanteGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_AAsanteGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AAsanteGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_Asante,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAsanteGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "AsanteGameModeBase.h" },
		{ "ModuleRelativePath", "AsanteGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AAsanteGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AAsanteGameModeBase>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AAsanteGameModeBase_Statics::ClassParams = {
		&AAsanteGameModeBase::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_AAsanteGameModeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AAsanteGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AAsanteGameModeBase()
	{
		if (!Z_Registration_Info_UClass_AAsanteGameModeBase.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AAsanteGameModeBase.OuterSingleton, Z_Construct_UClass_AAsanteGameModeBase_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AAsanteGameModeBase.OuterSingleton;
	}
	template<> ASANTE_API UClass* StaticClass<AAsanteGameModeBase>()
	{
		return AAsanteGameModeBase::StaticClass();
	}
	AAsanteGameModeBase::AAsanteGameModeBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AAsanteGameModeBase);
	AAsanteGameModeBase::~AAsanteGameModeBase() {}
	struct Z_CompiledInDeferFile_FID_000_Projects_0__UnrealPractice_Asante_Asante_Asante_Source_Asante_AsanteGameModeBase_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_000_Projects_0__UnrealPractice_Asante_Asante_Asante_Source_Asante_AsanteGameModeBase_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AAsanteGameModeBase, AAsanteGameModeBase::StaticClass, TEXT("AAsanteGameModeBase"), &Z_Registration_Info_UClass_AAsanteGameModeBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AAsanteGameModeBase), 3136675110U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_000_Projects_0__UnrealPractice_Asante_Asante_Asante_Source_Asante_AsanteGameModeBase_h_3030936212(TEXT("/Script/Asante"),
		Z_CompiledInDeferFile_FID_000_Projects_0__UnrealPractice_Asante_Asante_Asante_Source_Asante_AsanteGameModeBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_000_Projects_0__UnrealPractice_Asante_Asante_Asante_Source_Asante_AsanteGameModeBase_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
