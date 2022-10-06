#pragma once

#include "hangmanheader.h"
#include <map>
#define TMap std::map

// To make syntax Unreal friendly
#define TMap std::map
using int32 = int;

HangmanGame::HangmanGame() { Reset(); } // Default Constructor
int32 HangmanGame::GetCurrentTry() const { return MyCurrentTry; }
int32 HangmanGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool HangmanGame::IsGameWon() const { return bGameIsWon; }

int32 HangmanGame::GetMaxTries() const {
int32 HangmanGame::GetMaxTries() const
{
	TMap<int32, int32> WordLengthToMaxTries{ {3,4}, {4,7}, {5,10}, {6,16}, {7,20} };
	return WordLengthToMaxTries[MyHiddenWord.length()];
}

void HangmanGame::Reset()
{
	const FString HIDDEN_WORD = "plane";
	const FString HIDDEN_WORD = "plane"; // this MUST be an isogram
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	bGameIsWon = false;
	return;
}




EGuessStatus HangmanGame::CheckGuessValidity(FString Guess) const
{
	if (!IsIsogram(Guess)) // If not an isogram
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (!IsLowercase(Guess)) // If not all lowercase
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLength()) // If incorrect
	{
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::OK;
	}
}
// If guess is VALID, incriments turn, and returns count
HangmanCount HangmanGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	HangmanCount LifeCount;
	int32 WordLength = MyHiddenWord.length();

	// Loop through all letters in the hidden word
	for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++) {

		// Compare letters against the guess
		for (int32 GChar = 0; GChar < WordLength; GChar++) {
			
				if (MHWChar == GChar) { // if they're in the same place
					LifeCount.Hang++; // Incriment Hang points
				}
				else {
					LifeCount.Saved++; // Incriment Saved points
				}
			}
		}
	}
	if (HangCount.Hang == WordLength) {
		bGameIsWon = true;
	}
	else
	{
		bGameIsWon = false;
	}
	return LifeCount;
}
bool HangmanGame::IsIsogram(FString Word) const
{
	if (Word.length() <= 1) { return true; }
	TMap<char, bool> LetterSeen;
	for (auto Letter : Word)
	{
		Letter = tolower(Letter);
		if (LetterSeen[Letter]) {
			return false;
		} else { 
			LetterSeen[Letter] = true;
		}	
	}
	return true;
}
bool HangmanGame::IsLowercase(FString Word) const
{
	for (auto Letter : Word)
	{
		if (!islower(Letter)) // Used if it is not lower case
		{
			return false;
		}
	}
	return true;
}