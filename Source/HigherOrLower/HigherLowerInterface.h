#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "HigherLowerInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UHigherLowerInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class HIGHERORLOWER_API IHigherLowerInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	//virtual ~IHigherLowerInterface() = delete;
	virtual void LowerGuess() = 0;
	virtual void HigherGuess() = 0;
	virtual void SameGuess() = 0;

};
