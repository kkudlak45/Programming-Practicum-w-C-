/****************************
Name: Kryzstof Kudlak
Course: CIT 163 – Programming Practicum w/C++
Date: September 17, 2018 (due date)
***************************
Files for Assignment: penguins.cpp
Purpose of File: Take raw input from a file and make it look nice
Assistance Received: N/A
*****************************/

#include <iostream>
#include <fstream> // file stream
#include <iomanip> // for output manipulation (setw, setprecision)
#include <string> // necessary for string use
using namespace std;

/***************************
Function: main
Precondition: all above libraries must be included before the function can execute
Postcondition: function will take raw data from a file, format it, and output it to the screen
Dates of Coding: September 12, 2018
Modifications: None
***************************/
int main()
{
	string name, id; // name of penguin and id (both strings)
	double weight, increase; // weight of food for penguin and percent increase of their food

	// turning the penguin text file into an input stream
	ifstream rawData;
	rawData.open("PenguinData.txt");

	// creating a data file to output to
	ofstream dat;
	dat.open("FeedingOutput.dat");

	dat << fixed << setprecision(2) << left; // setting the decimal to have two places after the decimal point

	// iterates through each line of the text file and formats the penguin data into the output data file
	for (int i = 0; i < 3; i++) 
	{
		rawData >> name >> id >> weight >> increase;
		weight = weight + weight * increase / 100; // calculation to determine new food weight using % increase
		dat << setw(10) << name;
		dat << setw(5) << id;
		dat << setw(5) << weight << "lbs." << endl;
	}

	// closing files
	rawData.close();
	dat.close();

	return 0;
}