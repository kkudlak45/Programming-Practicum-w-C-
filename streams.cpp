/****************************
Name: Kryzstof Kudlak
Course: CIT 163 – Programming Practicum w/C++
Date: October 8, 2018 (due date)
***************************
Files for Assignment: streams.cpp
Purpose of File: finds the amount of years it takes for the plant growth of stream A to surpass stream b
Assistance Received: N/A
*****************************/

#include <iostream>
#include <cmath>
using namespace std;

/***************************
Function: main
Precondition: iostream and cmath (for the floor fxn) must be included using std namespace
Postcondition: the function takes input for the growth rate and plant count of both streams and calculates when stream A's plant count will surpass that of stream B if the rate of growth of A is bigger than B and the initial plant count for A is smaller than B
Dates of Coding: October 2-4, 2018
Modifications: Added a do-while loop to my input statements and realized that the program is only supposed to deal with ONE case where A's growth rate > B's growth rate and A's initial plant count < B's
***************************/

int main()
{
	// variable declaration for known information about the streams which needs to be inputted
	int years = 0;
	double aRate, bRate, aCount, bCount;
	
	// do while loop which takes input for each variable
	do
	{
		cout << "Enter the plant count of A: " << endl;
		cin >> aCount;
		cout << "Enter the rate of growth of A (as a percentage without the % sign, eg: 2.5 or 3):" << endl;
		cin >> aRate;

		cout << "\nEnter the plant count of B: " << endl;
		cin >> bCount;
		cout << "Enter the rate of growth of B (in the same format as before):" << endl;
		cin >> bRate;

		// prints an error message if the conditions for the program to function are not met
		if (bCount < aCount || bRate > aRate) {
			cout << "\nThe plant count and rate of growth for Stream B cannot be greater than Stream A\n" << endl;
		}
	} 
	while (bCount < aCount || bRate > aRate); // if the conditions for the program's algorithm to work are not met, then the user will be informed and input will be regathered

	// decimalizes rate of growth to simplify later math
	aRate /= 100;
	bRate /= 100;

	// while loop which repeats until stream A's plant count is bigger than B's
	while (aCount < bCount) {
		// increases A's count by the rate
		aCount *= (1 + aRate);
		aCount = floor(aCount);

		// increases B's count by the rate
		bCount *= (1 + bRate);
		bCount = floor(bCount);

		// incraments the years
		years++;
	}

	// final output displaying both streams' plant counts and how many years it took for A to surpass B
	cout << "\nStream A: " << aCount << endl;
	cout << "Stream B: " << bCount << endl; 
	cout << "It took " << years << " years for Stream A to surpass Stream B" << endl;

	return 0;
}