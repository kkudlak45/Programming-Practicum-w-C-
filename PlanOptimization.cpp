/****************************
Name: Kryzstof Kudlak
Course: CIT 163 – Programming Practicum w/C++
Date: September 25, 2018 (due date)
***************************
Files for Assignment: PlanOptimization.cpp
Purpose of File: To find the optimal plan for an ice cream shop
Assistance Received: N/A
*****************************/

#include <iostream>
using namespace std;

/***************************
Function: main
Precondition: iostream must be included & the std namespace must be used
Postcondition: the function takes input of 3 different ice cream shop plans
and outputs which one is the cheapest
Dates of Coding: September 19, 2018
Modifications: N/A
***************************/

int main()
{
	double price, land, a, b, c; // declaring all necessary values for inputs and comparisons

	// taking input for each plan (could have been coded easier using a loop and a table)
	cout << "Input the price of Plan A:" << endl;
	cin >> price; // price input
	cout << "Input the square feet of land purchased by Plan A:" << endl;
	cin >> land; // square feet of land input
	a = price * land; // calculation figuring out how much the plan costs and assigning it to that plan's name

	// same process for plan b
	cout << "\nInput the price of Plan B:" << endl;
	cin >> price;
	cout << "Input the square feet of land purchased by Plan B:" << endl;
	cin >> land;
	b = price * land;

	// same process for plan c
	cout << "\nInput the price of Plan C:" << endl;
	cin >> price;
	cout << "Input the square feet of land purchased by Plan C:" << endl;
	cin >> land;
	c = price * land;

	cout << endl; // to make it look pretty

	// decision block finding the cheapest plan (if one is bigger than both of the others, then print which one it is)
	if (a < b && a < c) 
	{
		cout << "Plan A";
	}
	else if (b < a && b < c) 
	{
		cout << "Plan B";
	}
	else if (c < a && c < b) 
	{
		cout << "Plan C";
	}
	else 
	{
		cout << "There is not one plan which is better than the others"; // in case there is no biggest (probably not necessary)
	}

	cout << " is the cheapest" << endl; // adds to the output but is not affected by the if statements, so it's placed here to save time writing

	return 0;
}