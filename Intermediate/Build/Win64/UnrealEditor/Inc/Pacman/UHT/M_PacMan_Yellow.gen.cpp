// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Pacman/Private/M_PacMan_Yellow.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeM_PacMan_Yellow() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
PACMAN_API UClass* Z_Construct_UClass_AM_PacMan_Yellow();
PACMAN_API UClass* Z_Construct_UClass_AM_PacMan_Yellow_NoRegister();
UPackage* Z_Construct_UPackage__Script_Pacman();
// End Cross Module References

// Begin Class AM_PacMan_Yellow
void AM_PacMan_Yellow::StaticRegisterNativesAM_PacMan_Yellow()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AM_PacMan_Yellow);
UClass* Z_Construct_UClass_AM_PacMan_Yellow_NoRegister()
{
	return AM_PacMan_Yellow::StaticClass();
}
struct Z_Construct_UClass_AM_PacMan_Yellow_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "M_PacMan_Yellow.h" },
		{ "ModuleRelativePath", "Private/M_PacMan_Yellow.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AM_PacMan_Yellow>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AM_PacMan_Yellow_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_Pacman,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AM_PacMan_Yellow_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AM_PacMan_Yellow_Statics::ClassParams = {
	&AM_PacMan_Yellow::StaticClass,
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
	0x008000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AM_PacMan_Yellow_Statics::Class_MetaDataParams), Z_Construct_UClass_AM_PacMan_Yellow_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AM_PacMan_Yellow()
{
	if (!Z_Registration_Info_UClass_AM_PacMan_Yellow.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AM_PacMan_Yellow.OuterSingleton, Z_Construct_UClass_AM_PacMan_Yellow_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AM_PacMan_Yellow.OuterSingleton;
}
template<> PACMAN_API UClass* StaticClass<AM_PacMan_Yellow>()
{
	return AM_PacMan_Yellow::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AM_PacMan_Yellow);
AM_PacMan_Yellow::~AM_PacMan_Yellow() {}
// End Class AM_PacMan_Yellow

// Begin Registration
struct Z_CompiledInDeferFile_FID_Users_kprado_OneDrive___Kansas_State_University_Documents_Unreal_Projects_Pacman_5_5_Source_Pacman_Private_M_PacMan_Yellow_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AM_PacMan_Yellow, AM_PacMan_Yellow::StaticClass, TEXT("AM_PacMan_Yellow"), &Z_Registration_Info_UClass_AM_PacMan_Yellow, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AM_PacMan_Yellow), 2700800903U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_kprado_OneDrive___Kansas_State_University_Documents_Unreal_Projects_Pacman_5_5_Source_Pacman_Private_M_PacMan_Yellow_h_1570207944(TEXT("/Script/Pacman"),
	Z_CompiledInDeferFile_FID_Users_kprado_OneDrive___Kansas_State_University_Documents_Unreal_Projects_Pacman_5_5_Source_Pacman_Private_M_PacMan_Yellow_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_kprado_OneDrive___Kansas_State_University_Documents_Unreal_Projects_Pacman_5_5_Source_Pacman_Private_M_PacMan_Yellow_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
