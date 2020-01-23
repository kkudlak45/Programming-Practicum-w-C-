/********************
Name: Kryzstof Kudlak
Date: 12/29/18
File: dictCount
Purpose: Counts the letters in the dictionary
********************/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;


int main() {
	ifstream file;
	file.open("words_alpha.txt");

	int letterCount[26] = { 0 };
	char letters[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

	char letter;
	int number;

	while (!file.eof())
	{
		file >> letter;
		number = letter - 97;
		cout << letter << ' ';
		if (number >= 1 || number <= 25)
		{
			letterCount[number]++;
		}
	}

	file.close();

	cout << endl << endl << "Results" << endl;

	for (int i = 0; i < 26; i++)
	{
		cout << letters[i] << ": " << letterCount[i] << endl;
	}

	return 0;
}
