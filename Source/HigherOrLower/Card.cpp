#include "Card.h"

Card::Card()
{
}

//Standard enum based constructor
Card::Card(CardValue cardValue, CardSuit cardSuit)
{
	suit = cardSuit;
	value = cardValue;
}

//Integer based on constructor, just casts the integer to the card suit/value enums.
Card::Card(int cardValueEnumIndex, int cardSuitEnumIndex)
{
	suit = (CardSuit)cardSuitEnumIndex;
	value = (CardValue)cardValueEnumIndex;
}

Card::~Card()
{
}

Card::CardSuit Card::GetSuit()
{
	return suit;
}

Card::CardValue Card::GetValue()
{
	return value;
}

//Returns an FString value equal to that of the suit enum
FString Card::GetSuitString()
{
	switch (suit)
	{
	case 0:
		return FString(TEXT("Spades"));
	case 1:
		return FString(TEXT("Diamonds"));
	case  2:
		return FString(TEXT("Clubs"));
	case 3:
		return FString(TEXT("Hearts"));
	}

	return  FString(TEXT(""));
}

// Returns an FString value equal to that of the value enum
FString Card::GetValueString()
{
	switch (value)
	{
	case 0:
		return FString(TEXT("Two"));
	case 1:
		return FString(TEXT("Three"));
	case  2:
		return FString(TEXT("Four"));
	case 3:
		return FString(TEXT("Five"));
	case 4:
		return FString(TEXT("Six"));
	case 5:
		return FString(TEXT("Seven"));
	case 6:
		return FString(TEXT("Eight"));
	case 7:
		return FString(TEXT("Nine"));
	case 8:
		return FString(TEXT("Ten"));
	case 9:
		return FString(TEXT("Jack"));
	case 10:
		return FString(TEXT("Queen"));
	case 11:
		return FString(TEXT("King"));
	case 12:
		return FString(TEXT("Ace"));
	}

	return  FString(TEXT(""));
}
