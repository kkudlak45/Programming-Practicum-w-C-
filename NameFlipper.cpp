/****************************
Name: Kryzstof Kudlak
Course: CIT 163 – Programming Practicum w/C++
Date: October 31, 2018
***************************
Files for Assignment: NameFlipper.cpp
Purpose of File: to take input from a file with names listed in the form "last first middle" and convert them to "first middle last"
*****************************/

#include <iostream>
#include <fstream> // needed for file reading
#include <string> // needed for strings and their operators
using namespace std;

/***************************
Function: reverseName
Precondition: the variable "name" must be read from the file and stored in a string
 name - the full name that was read from the file in the form "last firt middle"
Postcondition: this function converts the name parameter from "last first middle" to "first middle last" and returns it
Dates of Coding: October 31, 2018
***************************/
string reverseName(string);

/***************************
Function: main
Precondition: headers iostream, fstream, and string must be used
Postcondition: this function iterates through all lines of text in a file called "names.txt" which stores names in the format "last first middle" and converts them to "first middle last"
Dates of Coding: October 31, 2018
***************************/
int main()
{
	string name; // declaring the variable used to store the entire name

	ifstream file; // setting up the file with all the names
	file.open("names.txt");

	cout << "Reversed names: " << endl << endl;   // makes the output pretty

	while (! file.eof()) // iterates through the each line of the input file
	{
		getline(file, name); // gets the full line of the file (full name) and stores it as name
		name = reverseName(name); // passes the entire name into the reverse function and sets the original name variable to the reversed one
		cout << name << endl; // outputs the name in its reversed form
	}

	file.close(); // close the file
	return 0;
}

/***************************
Function: reverseName
Precondition: the variable "name" must be read from the file and stored in a string
 name - the full name that was read from the file in the form "last firt middle"
Postcondition: this function converts the name parameter from "last first middle" to "first middle last" and returns it
Dates of Coding: October 31, 2018
***************************/
string reverseName(string name)
{
	string first, last, mid; // variables for each part of the name
	int b1, b2, len; // variables to help parse the string (b1 and b2 are indexes of the ' ' character, and len is the length of the string)

	len = name.length(); // set length = to string length
	b1 = name.find(' '); // find first space's index
	b2 = name.find(' ', b1 + 1); // second space's index
	
	// parse strings using some formulas that I worked out and the substr function
	last = name.substr(0, b1);
	first = name.substr(b1 + 1, b2 - b1 - 1);
	mid = name.substr(b2 + 1, len - b2);

	// concatenate all the name parts together
	name = first + " " + mid + " " + last;

	return name; // return the name because for some reason it's easier to pass this back instead of altering the original variable directly
}