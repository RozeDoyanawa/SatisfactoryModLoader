#pragma once
#include "CoreMinimal.h"
#include "Toolkit/AssetGeneration/AssetTypeGenerator.h"
#include "SimpleAssetGenerator.generated.h"

UCLASS(Abstract)
class SMLEDITOR_API USimpleAssetGenerator : public UAssetTypeGenerator {
	GENERATED_BODY()
protected:
	virtual UClass* GetAssetObjectClass() const PURE_VIRTUAL(GetAssetObjectClass, return NULL;);
	virtual UPackage* CreateAssetPackage() override final;
	virtual void OnExistingPackageLoaded() override final;
	
	virtual void PopulateSimpleAssetWithData(UObject* Asset);
	virtual bool IsSimpleAssetUpToDate(UObject* Asset) const;
public:
	virtual void PopulateStageDependencies(TArray<FAssetDependency>& OutDependencies) const override;
};