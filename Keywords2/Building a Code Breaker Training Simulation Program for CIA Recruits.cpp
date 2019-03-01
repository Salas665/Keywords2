#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;

//The 10 words I chose
/*
Agent 
Classified 
Conspiracy 
Espionage 
Intelligence 
Surveillance 
Terrorist 
Target 
America 
illegal 
*/

int main()
{
	bool gameContinue = true;
	if (gameContinue == true)
	{
		//Introduction to the program
		cout << "Welcome to the Code Breaker Training Simulation Program for CIA Recruits!\n";
		cout << "Your mission is to guess the word in each level.\n";
		cout << "There are 3 levels, the more you progress the less guesses you have\n";
		cout << "making it harder on you.\n";
		cout << "Good Luck!\n";
		system("pause");

		//Collection of possible words to guess
		vector<string> words; //this creates the vector "words"
		words.push_back("AGENT");
		words.push_back("CLASSIFIED");
		words.push_back("CONSPIRACY");
		words.push_back("ESPIONAGE");
		words.push_back("INTELLIGENCE");
		words.push_back("SURVEILLANCE");
		words.push_back("TERRORIST");
		words.push_back("TARGET");
		words.push_back("AMERICA");
		words.push_back("ILLEGAL");

		//This shuffles the the values inside the vector
		//so that every playthrough is different
		srand(static_cast<unsigned int>(time(0)));
		random_shuffle(words.begin(), words.end());

		//Words to guess
		//chooses the first three values from the shuffled vector
		const string wordOne = words[0];          
		const string wordTwo = words[1];
		const string wordThree = words[2];
		//This is the max wrong guesses the user gets
		//To increase the difficulty of the game
		//I decreased the number of  the max incorrect 
		//guesses by one each level
		int maxWrongOne = 8;
		int maxWrongTwo = 7;
		int maxWrongThree = 6;
		//number of incorrect guesses
		int wrongOne = 0; 
		int wrongTwo = 0;
		int wrongThree = 0;
		//word guessed so far
		string soFarOne(wordOne.size(), '-');         
		string soFarTwo(wordTwo.size(), '-');
		string soFarThree(wordThree.size(), '-');
		//letters already guessed
		string usedOne = "";                          
		string usedTwo = "";
		string usedThree = "";

		// LEVEL 1
		cout << "\n\nWelcome to level 1!\n";
		system("pause");
		while ((wrongOne < maxWrongOne) && (soFarOne != wordOne))
		{
			//Displaying information to the user
			cout << "\n\nYou have " << (maxWrongOne - wrongOne);
			cout << " incorrect guesses left.\n";
			cout << "\nYou have used the following letters:\n" << usedOne << endl;
			cout << "So far, the word is:\n" << soFarOne << endl;
			char guess;
			cout << "\nEnter your guess: ";
			cin >> guess;
			//make uppercase since secret word in uppercase
			guess = toupper(guess);
			//This will run if the user inputs repeated values
			while (usedOne.find(guess) != string::npos)
			{
				cout << "\nYou have already guessed " << guess << endl;
				cout << "Enter your guess: ";
				cin >> guess;
				guess = toupper(guess);
			}

			usedOne += guess;
			// This will run if the user inputs a correct value
			if (wordOne.find(guess) != string::npos)
			{
				cout << "That is right! " << guess << " is in the word.\n";
				//update soFar to include newly guessed letter
				for (int i = 0; i < wordOne.length(); ++i)
				{
					if (wordOne[i] == guess)
					{
						soFarOne[i] = guess;
					}
				}
			}
			//This will run if the user inputs an incorrect value
			else
			{
				cout << "Sorry, " << guess << " is not in the word.\n";
				++wrongOne;
			}
			// This will run if the user has used up all of the guesses
			if (wrongOne == maxWrongOne)
			{
				cout << "\nGAME OVER!";
				cout << "\nYou reached the maximum amount of incorrect guesses";
				gameContinue = false;
				char playAgain;
				cout << "\nWant to play again? (y/n)" << endl;
				cin >> playAgain;
				if (playAgain == 'y' || playAgain == 'Y')
				{
					gameContinue = true;
					return main();
				}
				if (playAgain == 'n' || playAgain == 'N')
				{
					cout << "Thanks for playing!" << endl;
					cout << "GoodBye!" << endl;
					system("pause");
					return 0;
				}
			}
		}
		cout << "\nThe word was " << wordOne << endl;

		// LEVEL 2
		system("pause");
		cout << "Nice Job making it past level 1, now it's time for level 2!\n";
		system("pause");
		while ((wrongTwo < maxWrongTwo) && (soFarTwo != wordTwo))
		{
			cout << "\n\nYou have " << (maxWrongTwo - wrongTwo);
			cout << " incorrect guesses left.\n";
			cout << "\nYou have used the following letters:\n" << usedTwo << endl;
			cout << "So far, the word is:\n" << soFarTwo << endl;
			char guess;
			cout << "\nEnter your guess: ";
			cin >> guess;
			guess = toupper(guess); //make uppercase since secret word in uppercase
			while (usedTwo.find(guess) != string::npos)
			{
				cout << "\nYou have already guessed " << guess << endl;
				cout << "Enter your guess: ";
				cin >> guess;
				guess = toupper(guess);
			}

			usedTwo += guess;

			if (wordTwo.find(guess) != string::npos)
			{
				cout << "That is right! " << guess << " is in the word.\n";
				//update soFar to include newly guessed letter
				for (int i = 0; i < wordTwo.length(); ++i)
				{
					if (wordTwo[i] == guess)
					{
						soFarTwo[i] = guess;
					}
				}
			}
			else
			{
				cout << "Sorry, " << guess << " is not in the word.\n";
				++wrongTwo;
			}
			if (wrongTwo == maxWrongTwo)
			{
				cout << "\nGAME OVER!";
				cout << "\nYou reached the maximum amount of incorrect guesses";
				gameContinue = false;
				char playAgain;
				cout << "\nWant to play again? (y/n)" << endl;
				cin >> playAgain;
				if (playAgain == 'y' || playAgain == 'Y')
				{
					gameContinue = true;
					return main();
				}
				if (playAgain == 'n' || playAgain == 'N')
				{
					cout << "Thanks for playing!" << endl;
					cout << "GoodBye!" << endl;
					system("pause");
					return 0;
				}
			}
		}
		cout << "\nThe word was " << wordTwo << endl;

		// LEVEL 3
		system("pause");
		cout << "Impressive! You made it past level 2, now it's time for level 3, the final level!\n";
		system("pause");
		while ((wrongThree < maxWrongThree) && (soFarThree != wordThree))
		{
			cout << "\n\nYou have " << (maxWrongThree - wrongThree);
			cout << " incorrect guesses left.\n";
			cout << "\nYou have used the following letters:\n" << usedThree << endl;
			cout << "So far, the word is:\n" << soFarThree << endl;
			char guess;
			cout << "\nEnter your guess: ";
			cin >> guess;
			guess = toupper(guess); //make uppercase since secret word in uppercase
			while (usedThree.find(guess) != string::npos)
			{
				cout << "\nYou have already guessed " << guess << endl;
				cout << "Enter your guess: ";
				cin >> guess;
				guess = toupper(guess);
			}

			usedThree += guess;

			if (wordThree.find(guess) != string::npos)
			{
				cout << "That is right! " << guess << " is in the word.\n";
				//update soFar to include newly guessed letter
				for (int i = 0; i < wordThree.length(); ++i)
				{
					if (wordThree[i] == guess)
					{
						soFarThree[i] = guess;
					}
				}
			}
			else
			{
				cout << "Sorry, " << guess << " is not in the word.\n";
				++wrongThree;
			}
			if (wrongThree == maxWrongThree)
			{
				cout << "\nGAME OVER!";
				cout << "\nYou reached the maximum amount of incorrect guesses";
				gameContinue = false;
				char playAgain;
				cout << "\nWant to play again? (y/n)" << endl;
				cin >> playAgain;
				if (playAgain == 'y' || playAgain == 'Y')
				{
					gameContinue = true;
					return main();
				}
				if (playAgain == 'n' || playAgain == 'N')
				{
					cout << "Thanks for playing!" << endl;
					cout << "GoodBye!" << endl;
					system("pause");
					return 0;
				}
			}
		}
		cout << "\nThe word was " << wordThree << endl;

		//Ends the game
		gameContinue = false;
		system("pause");
		// Asking the user if they want to play again
		if (gameContinue == false)
		{
			cout << "You have completed the Code Breaker Training Simulation Program for CIA Recruits!\nCONGRATULATIONS" << endl;
			char playAgain;
			cout << "Want to play again? (y/n)" << endl;
			cin >> playAgain;
			if (playAgain == 'y' || playAgain == 'Y')
			{
				gameContinue = true;
				return main();
			}
			if (playAgain == 'n' || playAgain == 'N')
			{
				cout << "Thanks for playing!" << endl;
				cout << "GoodBye!" << endl;
				system("pause");
				return 0;
			}
		}
	}
}