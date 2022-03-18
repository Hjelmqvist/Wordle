#pragma once
#include <map>
#include <string>

std::string getGuess(int wordLength);

struct Guess
{
private:
	std::string guess = "";
	std::string wordToGuess = "";
	std::map<char, int> wordChars;
	std::string coloredWord;

public:
	Guess(const std::string& guess, const std::string& wordToGuess);
	bool isCorrectGuess();
	std::string getColoredWord();
};