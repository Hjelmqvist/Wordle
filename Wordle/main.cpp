#include <iostream>
#include <string>
#include <vector>

#include "input.h"
#include "guess.h"

#define MAX_TRIES 6

using namespace std;

string getRandomWord(const vector<string>& words)
{
	int index = rand() % (words.size() - 1);
	return words[index];
}

void startNewRound(const vector<string>& words)
{
	string wordToGuess = getRandomWord(words);
	bool won = false;

	for (int i = 0; i < MAX_TRIES; ++i)
	{
		cout << "Guess " << i + 1 << "/" << MAX_TRIES << ": ";
		Guess guess(getGuess(), wordToGuess);
		cout << guess.getColoredWord() << endl;

		won = guess.isCorrectGuess();
		if (won)
		{
			break;
		}
	}

	if (won)
	{
		cout << "You won!" << endl;
	}
	else
	{
		cout << "You lost!" << endl;
		cout << "The word was: " << wordToGuess << endl;
	}
}

int main()
{
	srand(time(NULL));
	vector<string> words = getWordsFromFile("words.txt");

	while (true)
	{
		startNewRound(words);

		cout << "Play again? (y/n): ";
		char input = getPlayAgainInput();
		cout << endl;

		if (input == 'n')
		{
			break;
		}
	}
}