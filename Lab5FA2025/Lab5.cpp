/*
	Olivia Dodds
	C++ FA2025
	Due: Nov 11th, 2025
	Lab 5 Number Guessing Game
	This program plays a number guessing game with the user, asking if the user wants to play again, and displaying their results at the end
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <istream>

void playingGame();
void randWinMessage();
void randLoseMessage();
void randPlayAgainMessage();
void playAgain();

//made global so all functions can access the values
int winCount = 0;
int loseCount = 0;


int main()
{
	std::cout << "Welcome to the Number Guessing Game." << std::endl;
	playingGame(); //starts the game

	return 0;
}

//controls the guessing game part
void playingGame()
{
	//generates a new number for each game
	srand(time(0));
	int randomNumber = rand() % 101;

	//variables to track how many guesses the user has left 
	int curGuess;
	int guessAttempts = 20;

	std::cout << "\n\nI have decided on a random number. You have 20 attempts to guess it. " << std::endl;

	//loops until either the user guesses the number or runs out of guesses
	do 
	{
		//takes input from user
		std::cin >> curGuess;

		//checks if the guessed number is the selected number
		if (curGuess == randomNumber)
		{
			//goes to win message if number was correct
			randWinMessage();
			break;
		}
		else
		{
			//takes away a guess attempt, displays how many guesses are left
			guessAttempts--;
			std::cout << "Sorry, that wasn't right. You have " << guessAttempts << " attempt(s) remaining." << std::endl;

			//if the player runs out of guesses, displays the losing message
			if (guessAttempts == 0)
			{
				randLoseMessage();
			}
		}
	} while (guessAttempts > 0); //loop runs until user runs out of guesses

}

//randomly selects one of the ten win messages to display
void randWinMessage()
{
	int randNum = rand() % 10;

	switch (randNum)
	{
		case 1: std::cout << "You nailed it! That’s the number, great job!" << std::endl;
				break;
		case 2: std::cout << "Mind reader alert! You guessed it perfectly." << std::endl;
				break;
		case 3:std::cout << "Boom! You crushed it. That's the correct number!" << std::endl;
				break;
		case 4:std::cout << "Smooth move, genius. You guessed right!" << std::endl;
				break;
		case 5:std::cout << "Winner winner, number guesser! You got it!" << std::endl;
				break;
		case 6:std::cout << "Spot on! Your guessing skills are sharp today." << std::endl;
				break;
		case 7:std::cout << "Victory! You found the secret number!" << std::endl;
				break;
		case 8:std::cout << "Hot streak! You guessed the number exactly right!" << std::endl;
				break;
		case 9:std::cout << "Bullseye! You hit the target number dead on." << std::endl;
				break;
		default: std::cout << "Congradulations! You've won!" << std::endl;
	}

	winCount = winCount++; //tracking how many wins the user gets
	playAgain();
}

//randomly selects one of the ten lose messages to display
void randLoseMessage()
{
	int randNum = rand() % 10;

	switch (randNum)
	{
	case 1: std::cout << "Oof! Not quite right. Better luck next time!" << std::endl;
		break;
	case 2: std::cout << "The number laughs in mystery. You lose this round!" << std::endl;
		break;
	case 3:std::cout << "So close, yet so far. Don’t give up!" << std::endl;
		break;
	case 4:std::cout << "Not the winning number! Maybe next time?" << std::endl;
		break;
	case 5:std::cout << "Nope! The number escaped your grasp." << std::endl;
		break;
	case 6:std::cout << "Cold, cold, cold... try warming up that guess!" << std::endl;
		break;
	case 7:std::cout << "That's not it! But hey, at least you tried." << std::endl;
		break;
	case 8:std::cout << "Game over! The number remains a secret... for now." << std::endl;
		break;
	case 9:std::cout << "The number hides in the shadows. You'll need sharper instincts!" << std::endl;
		break;
	default: std::cout << "You've lost. Better luck next time!" << std::endl;
	}

	loseCount = loseCount++; //tracking how many loses the user gets
	playAgain();
}

//randomly selects one of the ten play again messages to display
void randPlayAgainMessage()
{
	int randNum = rand() % 10;

	switch (randNum)
	{
	case 1: std::cout << "That was fun! Want to play another game?" << std::endl;
		break;
	case 2: std::cout << "Ready for another round?" << std::endl;
		break;
	case 3:std::cout << "Do you want to go again?" << std::endl;
		break;
	case 4:std::cout << "Another game? I'm just getting warmed up!" << std::endl;
		break;
	case 5:std::cout << "That was a good one, up for another one?" << std::endl;
		break;
	case 6:std::cout << "Rematch?" << std::endl;
		break;
	case 7:std::cout << "How about one more game?" << std::endl;
		break;
	case 8:std::cout << "Shall we start a new game?" << std::endl;
		break;
	case 9:std::cout << "You in for another round?" << std::endl;
		break;
	default: std::cout << "Would you like to play again?" << std::endl;
	}

}

//asks the user if they'd like to play another game
void playAgain()
{
	randPlayAgainMessage();

	//take input from user
	std::string playGame;
	std::cin >> playGame;

	//if user inputs yes, plays the game again
	if (playGame == "yes" || playGame == "Yes" || playGame == "YES")
	{
		playingGame();
	}
	else if (playGame == "no" || playGame == "No" || playGame == "NO") //else, ends the program and displays messages
	{
		std::cout << "\nThank you for playing! Here are your stats: \n Wins: " << winCount << "\n Lose: " << loseCount << std::endl;
	}
	else //makes sure expected input is given, loops this function until proper input is received
	{
		std::cout << "Sorry, I don't understand. Please reply with yes or no." << std::endl;
		playAgain();
	}
}