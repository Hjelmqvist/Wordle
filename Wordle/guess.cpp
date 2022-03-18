#include <map>
#include <string>
#include <vector>

#include "guess.h"

#define FOREGROUND(color, text) "\x1B[" + color + "m" + text + "\033[0m"
#define BACKGROUND(color, text) "\033[3;42;" + color + "m" + text + "\033[0m"

enum class ForegroundColor : int {
	Red = 31,
	Green = 32,
	Yellow = 33,
	BrightRed = 91,
	BrightGreen = 92,
	BrightYellow = 93
};

enum class BackgroundColor : int {
	Red = 41,
	Green = 42,
	Yellow = 43,
	BrightRed = 101,
	BrightGreen = 102,
	BrightYellow = 103
};

using namespace std;

map<char, int> getNumberOfLettersInWord(string word)
{
	map<char, int> wordChars;
	for (auto& letter : word)
	{
		wordChars[letter]++;
	}
	return wordChars;
}

vector<int> getPositionColors(const string& guess, const string& wordToGuess, map<char, int> wordChars)
{
	int wordLength = wordToGuess.size();
	vector<int> colors(wordLength, (int)ForegroundColor::BrightRed);

	for (int i = 0; i < wordLength; ++i) // Letter at correct position
	{
		char letter = guess[i];
		if (letter == wordToGuess[i])
		{
			colors[i] = (int)ForegroundColor::BrightGreen;
			wordChars[letter]--;
		}
	}

	for (int i = 0; i < wordLength; ++i) // Letter exists in word and more than 0 left
	{
		char letter = guess[i];
		if (colors[i] == (int)ForegroundColor::BrightRed && wordChars[letter] > 0)
		{
			colors[i] = (int)ForegroundColor::BrightYellow;
			wordChars[letter]--;
		}
	}

	return colors;
}

string createColoredWord(const string& word, vector<int> colors)
{
	string coloredWord;
	for (int i = 0; i < word.size(); ++i)
	{
		coloredWord += FOREGROUND(to_string(colors[i]), word[i]);
	}
	return coloredWord;
}

Guess::Guess(const string& guess, const string& wordToGuess)
{
	this->guess = guess;
	this->wordToGuess = wordToGuess;
	vector<int> colors = getPositionColors(guess, wordToGuess, getNumberOfLettersInWord(wordToGuess));
	this->coloredWord = createColoredWord(guess, colors );
}

bool Guess::isCorrectGuess()
{
	return guess == wordToGuess;
}

string Guess::getColoredWord()
{
	return coloredWord;
}