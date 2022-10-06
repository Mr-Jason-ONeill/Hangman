#pragma once

#include <iostream>
#include <string>	
#include "hangmanheader.h"

// Syntax used to make "Unreal Engine friendly"
using FText = std::string;
using int32 = int;

// Function Prototypes as outside a class
void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();
void PrintGameSummary();

HangmanGame NewGame; // instantiate a new game

int main() {
	return 0;
}


// introduce the game
void PrintIntro()
{
	std::cout << "Welcome to Hangman\n";
void PrintIntro()
	return;
}


// plays a single game to completion
void PlayGame()
{
	NewGame.Reset();
	int32 MaxTries = NewGame.GetMaxTries();
	
	// Looping while the game isn't completed
	while (!NewGame.IsGameWon() && NewGame.GetCurrentTry() <= MaxTries) {
		FText Guess = GetValidGuess();
				
		// submit valid guess to the game, and receive counts
		LifeCount = NewGame.SubmitValidGuess(Guess);
		std::cout << "Oh no! = " << LifeCount.Hang;
		std::cout << ". Phew! = " << LifeCount.Saved << "\n\n";
	}
	PrintGameSummary();
	return;
}
// Loop until player gives valid answer
FText GetValidGuess()
{
	FText Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do {
		// Get guess
		int32 CurrentTry = NewGame.GetCurrentTry();
		std::cout << "Attempt " << CurrentTry << " of " << NewGame.GetMaxTries();
		std::cout << ". Enter your guess: ";
		std::getline(std::cin, Guess);

		// check and give feedback
		Status = NewGame.CheckGuessValidity(Guess);
		switch (Status) {
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << NewGame.GetHiddenWordLength() << " letter word.\n\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word witout repeating letters.\n\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter all lowercase letters.\n\n";
			break;
		default:
			// Assume the guess is valid
			break;
		}
	} while (Status != EGuessStatus::OK); // Loop until no errors
	return Guess;
}
bool AskToPlayAgain()
{
	std::cout << "Do you want to play again with the same word (Y/N)? ";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}
void PrintGameSummary()
{
	if (NewGame.IsGameWon())
	{
		std::cout << "Well Done! You saved that person. \n";
	}
	else
	{
		std::cout << "Oh no! That life must not have meant much. \n";
	}
}
