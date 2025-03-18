// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePacman_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_Pacman;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_Pacman()
	{
		if (!Z_Registration_Info_UPackage__Script_Pacman.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/Pacman",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0xDF305974,
				0xC8A856CB,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_Pacman.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_Pacman.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_Pacman(Z_Construct_UPackage__Script_Pacman, TEXT("/Script/Pacman"), Z_Registration_Info_UPackage__Script_Pacman, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xDF305974, 0xC8A856CB));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
