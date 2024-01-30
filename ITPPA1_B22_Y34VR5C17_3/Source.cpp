#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>

using namespace std;

//Generate random number for rock, paper, scissors switch case
int GetRandomNum(int min, int max)
{
	srand((int)time(0));
	int number{ (rand() % max) + min };
	return number;
}

// Set the input type and abbreviation to char for higher or lower game
string PlayerGuess(char playAbb_guess)
{
	if (playAbb_guess == 'h')
	{
		return "Higher";
	}
	else
	{
		return "Lower";
	}
}

// Set the input type and abbreviation to char for rock , paper, scissors game
string playerInput(char playAbb_rps)
{
	if (playAbb_rps == 'r')
	{
		return "Rock";
	}
	else if (playAbb_rps == 'p')
	{
		return "Paper";
	}
	else
	{
		return "Scissors";
	}
}

//Generate the computers play decisions
char GetCompPlay()
{
	char compPlay{};
	int number{ GetRandomNum(1, 3) };
	switch (number)
	{
	case 1:
		compPlay = 'r';
		break;
	case 2:
		compPlay = 'p';
		break;
	default:
		compPlay = 's';
	}
	return compPlay;
}

int main()
{
	// Declare a variable to hold the user's menu selections.
	int menuSelection;
	string confirmationMenu;

	//Menu options
	int higher_or_lower = 1, paper_scissors_rock = 2, number_of_fingers = 3, quit = 4;
	string yes = "y", no = "n";

	do {
		// Display the menu.
		cout << " **************************************\n";
		cout << "       GameBots Association\n";
		cout << " **************************************\n";
		cout << "Please select from the following: \n";
		cout << " \n";
		cout << "1. Play higher or lower \n";
		cout << "2. Play paper-scissors-rock \n";
		cout << "3. Guess the number of fingers \n";
		cout << "4. Quit \n" << endl;

		// Prompt the user for a selection
		cout << "Please enter your selection." << endl;
		cin >> menuSelection;

		//Prevents an invalid menu selection
		while (menuSelection < 1 || menuSelection > 5)
		{
			cout << "Invalid input. Please enter either 1, 2, 3 or 4.\n";
			cin >> menuSelection;
		}

		//Higher or lower game code block
		if (menuSelection == higher_or_lower) {

			string higher = "H", lower = "L";

			const int MIN_VALUE = 1,
				MAX_VALUE = 20;
			do {

				//initialize values
				int random_numOne;
				int unsigned seed = time(0);

				srand(seed);

				//Generate random number 1 within a certain range
				random_numOne = (rand() %
					(MAX_VALUE - MIN_VALUE + 1)) +
					MIN_VALUE;

				char playerGuess{};

				cout << "--- Higher or Lower ---" << endl << endl;

				cout << "" << endl;
				cout << random_numOne << endl;

				int random_numTwo;

				//Generate random number 2 within a certain range
				random_numTwo = (rand() %
					(MAX_VALUE - MIN_VALUE + 1)) +
					MIN_VALUE;

				cout << "Do you think the next number will be (H)igher or (L)ower? " << endl;
				cin >> playerGuess;

				//Ensures the value is taken regardless if it is in upper or lower case
				while (playerGuess != 'h' && playerGuess != 'l')
				{
					cout << "Do you think the next number will be (H)igher or (L)ower? " <<  endl;
					cin >> playerGuess;

					playerGuess = tolower(playerGuess);
				}

				// sets parameters for the game
				if (playerGuess == 'h' && random_numOne < random_numTwo)
				{
					cout << "win \n" << random_numTwo << endl;
				}
				else if (playerGuess == 'h' && random_numOne > random_numTwo)
				{
					cout << "loss \n" << random_numTwo << endl;
				}
				else if (playerGuess == 'l' && random_numOne > random_numTwo)
				{
					cout << "win \n" << random_numTwo << endl;
				}
				else if (playerGuess == 'l' && random_numOne < random_numTwo)
				{
					cout << "loss \n" << random_numTwo << endl;
				}
				else {
					cout << "tie \n";
				}
				cout << "Play again?" << endl << "(Y)es" << endl << "(N)o" << endl;
				cin >> confirmationMenu;

				//prevents an invalid input
				while (confirmationMenu != "y" && confirmationMenu != "n")
				{
					cout << "Invalid input. Invalid input. Please answer y for yes or n for no.";
					cin >> confirmationMenu;
				}

				//run this loop as long as play again loop is equal to y
			} while (confirmationMenu == "y");
			return 0;
		}
		//Rock, paper, scissors game code block
		else if (menuSelection == paper_scissors_rock) {
			do{
				//initialize function
				char compPlay{};

				//initialize value
				char userPlay;

				cout << "--- Rock, Paper, Scissors ---" << endl << endl;
				cout << "Enter a choice : (R)ock, (P)aper, (S)cissors : \n";
				cin >> userPlay;

				//Ensures the value is taken regardless if it is in upper or lower case
				userPlay = towlower(userPlay);

				cout << endl << "You played " << playerInput(userPlay) << endl;

				compPlay = GetCompPlay();
				cout << "The computer played " << playerInput(compPlay) << endl;

				// sets parameters for the game
				if (userPlay == 'r' && compPlay == 's')
				{
					cout << "win \n";
				}
				else if (userPlay == 'p' && compPlay == 'r')
				{
					cout << "win \n";
				}
				else if (userPlay == 's' && compPlay == 'p')
				{
					cout << "win \n";
				}
				else if (userPlay == 's' && compPlay == 'r')
				{
					cout << "loss \n";
				}
				else if (userPlay == 'r' && compPlay == 'p')
				{
					cout << "loss \n";
				}
				else if (userPlay == 'p' && compPlay == 's')
				{
					cout << "loss \n";
				}
				else
				{
					cout << "tie \n";
				}
				cout << "Play again?" << endl << "(Y)es" << endl << "(N)o" << endl;
				cin >> confirmationMenu;

				//prevents an invalid input
				while (confirmationMenu != "y" && confirmationMenu != "n")
				{
					cout << "Invalid input. Invalid input. Please answer y for yes or n for no.";
					cin >> confirmationMenu;
				}

				//run this loop as long as play again loop is equal to y
			} while (confirmationMenu == "y");
		}
		else if (menuSelection == number_of_fingers) {
			int userGuess;

			//minimum and maximum numbers to be generated
			const int MIN_VALUE = 1,
				MAX_VALUE = 5;
			do{

				//initialize value
				int random_num;
				int unsigned seed = time(0);
				
				srand(seed);

				//Generate random number within a certain range
				random_num = (rand() %
					(MAX_VALUE - MIN_VALUE + 1)) +
					MIN_VALUE;

				cout << "--- Guess the number of fingers ---" << endl << endl;
			
				cout << "Guess a number from 1 - 5" << endl;
				cin >> userGuess;

				//Ensures the user can only enter a number within the given range
				if (userGuess > 0 && userGuess < 6)
				{
					if (userGuess == random_num) {
						cout << "You win!" << " The number was : " << random_num << endl;
					}
					else {
						cout << "Incorrect.  The number was: " << random_num << endl;
					}
				}
				else {
					cout << "That is not a valid number. Please enter a number between 1 and 5 \n";
				}
				cout << "Play again?" << endl << "(Y)es" << endl << "(N)o" << endl;
				cin >> confirmationMenu;

				//prevents an invalid input
				while (confirmationMenu != "y" && confirmationMenu != "n")
				{
					cout << "Invalid input. Invalid input. Please answer y for yes or n for no.";
					cin >> confirmationMenu;
				}

				//run this loop as long as play again loop is equal to y
			} while (confirmationMenu == "y");
			return 0;
		}
		else 
	{
			exit(0); //close the application
		}
	} while (confirmationMenu == "y");
}
