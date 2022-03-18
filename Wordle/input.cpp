#include <string>
#include <vector>
#include <fstream>
#include <iostream>

#define WORD_LENGTH 5

using namespace std;

vector<string> getWordsFromFile(const string& filename)
{
	vector<string> words;

	string line;
	ifstream file;
	file.open(filename);
	if (file.is_open())
	{
		while (getline(file, line))
		{
			words.push_back(line);
		}
		file.close();
	}

	return words;
}

string getInput()
{
	string input;
	cin.clear();
	cin >> input;
	return input;
}

bool isUpperAlpha(const char& c)
{
	return (c >= 'A' && c <= 'Z');
}

bool isValidGuess(string& guess)
{
	if (guess.size() != WORD_LENGTH)
	{
		return false;
	}
		
	for (auto& letter : guess)
	{
		letter = toupper(letter);
		if (isUpperAlpha(letter) == false)
		{
			return false;
		}
	}
	return true;
}

string getGuess()
{
	while (true)
	{
		string input = getInput();
		if (isValidGuess(input))
		{
			return input;
		}
		cout << "Invalid guess!" << endl;
	}
}

char getPlayAgainInput()
{
	while (true)
	{
		string input = getInput();
		char firstLetter = tolower(input[0]);
		if (firstLetter == 'y' || firstLetter == 'n')
			return firstLetter;
	}
}