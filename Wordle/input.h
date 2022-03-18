#pragma once
#include <string>
#include <vector>

std::vector<std::string> getWordsFromFile(const std::string& filename);
std::string getGuess();

/**
 * \return 'y' or 'n'
 */
char getPlayAgainInput();