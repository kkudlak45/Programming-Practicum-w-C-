/****************************
Name: Kryzstof Kudlak
Course: CIT 163 – Programming Practicum w/C++
Date: October 6, 2018 (due date)
***************************
Files for Assignment: SeriesProblem.cpp
Purpose of File: to determine how many steps it takes for a given arithmetic sequence to reach 1
Assistance Received: N/A
*****************************/

#include <iostream>
using namespace std;

/***************************
Function: main
Precondition: must include iostream and use std namespace
Postcondition: this function will ask the user to input a value for x and then loop the arithmetic sequence until it reaches 1 at which point it will output how many iterations it took for the sequence to reach 1
Dates of Coding: October 2, 2018
Modifications: None
***************************/

int main() 
{
	// initializing variables
	int x;
	int k = 0;

	// looping to take input for x to make sure it is >=1 because the sequence is infinite if x is negative
	do 
	{
		cout << "Input the value of x:" << endl;
		cin >> x;
		if (x < 1) {
			cout << "x cannot be less than 1" << endl << endl;
		}
	} while (x < 1);

	cout << x; // printing asub0 so the output looks nice

	// while x is not yet 1, check whether it is even or odd then perform the appropriate operation and print x to the output
	while (x != 1) {
		if (x % 2 == 0) {
			x = x / 2;
		}
		else if (x % 2 != 0) {
			x = 3*x + 1;
		}
		k++; // using k to track iterations of this loop
		cout << ", " << x; // outputs x each iteration in a nice format
	}

	cout << " and k is " << k << endl; // final output displaying how many iterations of the loop occurred

	return 0;
}