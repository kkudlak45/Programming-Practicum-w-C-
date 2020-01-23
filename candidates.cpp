/****************************
Name: Kryzstof Kudlak
Course: CIT 163 – Programming Practicum w/C++
Date: November 12, 2018
***************************
Files for Assignment: candidates.cpp
Purpose of File: gather information about candidates of an election, return a nicely formatted table and the winner of the election
*****************************/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// gathers candidate info (all functions fully documented below)
void getInput(string cNames[5], double votes[], double& total);
// outputs table
void output(const string cNames[5], const double votes[], double total);
// determines winner of election
int winner(const double votes[5]);


/***************************
Function: main
Precondition: all above headers must be included and functions must be defined, std namespace is used
Postcondition: this function controls the execution of all other functions such that we gather an input of all candidates, return a table of results, and return the winner
Dates of Coding: November 12, 2018
***************************/
int main() 
{
	string cNames[5]; // array for candidate names
	double votes[5];  // array for votes each candidate receives (parallel to cNames)
	double total = 0; // total number of votes cast
	int winnerIndex;  // index of the winner of the election

	getInput(cNames, votes, total); // gather candidate info
	output(cNames, votes, total);   // output this info in a nice looking table

	winnerIndex = winner(votes);    // determine the election winner
	cout << "\nThe winner of the election is " << cNames[winnerIndex];  // return the election winner

	return 0;
}

/***************************
Function: getInput
Precondition: all parameters must be defined
cNames - array of candidate names
votes - array of votes for each candidate (parallel with cNames)
total - total number of votes cast for use in later function
Postcondition: this function gathers information on each candidate and stores it in the arrays as well as gathers the total number of votes cast
Dates of Coding: November 12, 2018
***************************/
void getInput(string cNames[5], double votes[], double& total)
{
	for (int i = 0; i < 5; i++)  // iterate 5 times (once for each candidate)
	{
		cout << "Enter the last name of Candidate " << i + 1 << " and the number of votes he/she received:" << endl;
		cin >> cNames[i] >> votes[i]; // get candidate names and votes received for particular candidate
		total += votes[i];            // calculate total votes
		cout << endl;
	}
}

/***************************
Function: output
Precondition: all parameters must have been defined in main and there values should have been set by the getInput function
cNames - names of each candidate
votes - votes received by each candidate
total - total number of votes cast overall
Postcondition: this function prints a nice looking table of values which includes each candidates name, amount of votes for them, and % of the total vote that they received
Dates of Coding: November 12, 2018
***************************/
void output(const string cNames[5], const double votes[], double total)
{
	// table labels
	cout << left << setw(20) << "Candidate" << setw(20) << "Votes Received" << setw(20) << "% of Total Votes" << endl;
	for (int i = 0; i < 5; i++)  // loops through full list of candidates
	{
		cout << setw(20) << cNames[i]                                           // output name of candidate
			<< setw(20) << fixed << setprecision(0) << votes[i]	                // output number of votes received
			<< setw(20) << fixed << setprecision(2) << (votes[i] / total) * 100 // output % of total vote received
			<< endl;
	}
}

/***************************
Function: winner
Precondition: votes array must be defined and populated with values from running the getInput function
votes - votes received by each candidate
Postcondition: this function determines which candidate received the most votes and returns the index of that candidate
Dates of Coding: November 12, 2018
***************************/
int winner(const double votes[5])
{
	int index = 0;         // variable to track the index of the winner
	double big = votes[0]; // variable to store the current largest vote count (the first one to begin with)

	for (int i = 1; i < 5; i++) // iterates through each of the other vote counts
	{
		if (votes[i] > big) // if the vote count is bigger than the current biggest vote count, then
		{
			big = votes[i]; // we make it the new biggest
			index = i;      // and set the new largeset index
		}
	}

	return index; // return the winner's index
}