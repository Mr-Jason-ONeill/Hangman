#pragma once
#include <string>

// to make syntax Unreal friendly
using FString = std::string;
using int32 = int;

// All values intialised to zero
struct HangmanCount
{
	int32 Hang = 0;
	int32 Saved = 0;
};


enum class EGuessStatus
{
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};
class HangmanGame
{
public:
	HangmanGame(); // Constructor
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(FString) const;

	void Reset();
	void Reset();
	HangmanCount SubmitValidGuess(FString);


private:

	int32 MyCurrentTry;
	FString MyHiddenWord;
	bool bGameIsWon;
	bool IsIsogram(FString) const;
	bool IsLowercase(FString) const;
};