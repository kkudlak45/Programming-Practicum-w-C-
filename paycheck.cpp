/****************************
Name: Kryzstof Kudlak
Course: CIT 163 – Programming Practicum w/C++
Date: October 21, 2018 (due date)
***************************
Files for Assignment: paycheck.cpp, etc.
Purpose of File: to practice writing functions
Assistance Received: N/A
*****************************/

#include <iostream>
#include <iomanip> // for setprecision
using namespace std;

/***************************
Function: initialize
Precondition: the values of x, y, and z must be declared prior to the function call
 x - an int value to be set to 0
 y - an int value to be set to 0
 z - a char value to be set to a blank character
Postcondition: this function will initializes the values of x, y, and z by setting their values
Dates of Coding: October 21, 2018
Modifications: None
***************************/
void initialize(int& x, int& y, char& z);

/***************************
Function: getHoursRate
Precondition: the values of rate and hours must be declared prior to the function call
 rate - the rate of pay
 hours - the amount of hours worked
Postcondition: this function sets the values of rate and hours based on user input
Dates of Coding: October 21, 2018
Modifications: None
***************************/
void getHoursRate(double& hours, double& rate);

/***************************
Function: payCheck
Precondition: the values of rate and hours must be set prior to the function call
 rate - the rate of pay
 hours - the amount of hours worked
Postcondition: this function takes the values of rate and hours and uses them to determine the user's pay
Dates of Coding: October 21, 2018
Modifications: None
***************************/
double payCheck(double hours, double rate);

/***************************
Function: payCheck
Precondition: the values of rate, hours, and amount must be set prior to the function call
 rate - the rate of pay
 hours - the amount of hours worked
 amount - the amount of money earned by the person
Postcondition: this function takes the values of rate, amount, and hours and outputs them
Dates of Coding: October 21, 2018
Modifications: None
***************************/
void printCheck(double hours, double rate, double amount);

/***************************
Function: funcOne
Precondition: the values of x and y must be set prior to the function call
 x - arbitrary int value
 y - arbitrary int value
Postcondition: this function takes the values of x and y, takes input from the user for a temporary number, and uses these numbers to change the value of x
Dates of Coding: October 21, 2018
Modifications: None
***************************/
void funcOne(int& x, int y);

/***************************
Function: nextChar
Precondition: the value of z must be set prior to the function call
 z - arbitrary char value
Postcondition: this function takes the value of z and changes it to the char following whatever it is
Dates of Coding: October 21, 2018
Modifications: None
***************************/
void nextChar(char& z);

/***************************
Function: main
Precondition: iostream and iomanip must be included and std namespace should be used
Postcondition: this function tests all previously defined functions
Dates of Coding: October 21, 2018
Modifications: None
***************************/
int main()
{
	// variable declarations for functions to follow
	int x, y;
	char z;
	double rate, hours;
	double amount;

	// testing the initialize function by outputting the values before and after the function executes (first cout statement in all tests does not work in Visual Studio, but works in an online compiler that I found)
	cout << "x = " << x << ", y = " << y << ", z is '" << z << "'" << endl;
	initialize(x, y, z);
	cout << "x = " << x << ", y = " << y << ", z is '" << z << "'" << endl;

	// testing the getHoursRate function (again, first cout works in online IDE but not in Visual Studio)
	cout << "\nHours: " << hours << ", Rate: $" << rate << endl;
	getHoursRate(hours, rate);
	cout << "Hours: " << hours << ", Rate: $" << rate << endl;

	// testing payCheck function
	cout << fixed << showpoint << setprecision(2);
	cout << "\nAmount: $" << amount << endl;
	amount = payCheck(hours, rate);
	cout << "Amount: $" << amount << endl;

	// executing printCheck, self testing bc it has an output associated with it
	printCheck(hours, rate, amount);

	// testing funcOne
	cout << "x = " << x << endl;
	funcOne(x, y);
	cout << "x = " << x << endl;

	// testing nextChar
	cout << "z is '" << z << "'" << endl;
	nextChar(z);
	cout << "z is " << z << "'" << endl;

	return 0;
}

/***************************
Function: initialize
Precondition: the values of x, y, and z must be set prior to the function call
 x - an int value to be set to 0
 y - an int value to be set to 0
 z - a char value to be set to a blank character
Postcondition: this function will initializes the values of x, y, and z by setting their values
Dates of Coding: October 21, 2018
Modifications: None
***************************/
void initialize(int& x, int& y, char& z)
{
	x = 0;
	y = 0;
	z = ' ';
}


/***************************
Function: getHoursRate
Precondition: the values of rate and hours must be declared prior to the function call
 rate - the rate of pay
 hours - the amount of hours worked
Postcondition: this function sets the values of rate and hours based on user input
Dates of Coding: October 21, 2018
Modifications: None
***************************/
void getHoursRate(double& hours, double& rate)
{
	cout << "\nInput the total number of hours worked: " << endl;
	cin >> hours;
	cout << "\nInput the rate of pay: " << endl;
	cin >> rate;
}

/***************************
Function: payCheck
Precondition: the values of rate and hours must be declared prior to the function call
 rate - the rate of pay
 hours - the amount of hours worked
Postcondition: this function takes the values of rate and hours and uses them to determine the user's pay
Dates of Coding: October 21, 2018
Modifications: None
***************************/
double payCheck(double hours, double rate)
{
	double amount = 0;
	if (hours <= 40) {
		return hours * rate;
	}
	else {
		return (40 * rate) + (1.5 * rate * (hours - 40));
	}
}

/***************************
Function: payCheck
Precondition: the values of rate, hours, and amount must be declared prior to the function call
 rate - the rate of pay
 hours - the amount of hours worked
 amount - the amount of money earned by the person
Postcondition: this function takes the values of rate, amount, and hours and outputs them
Dates of Coding: October 21, 2018
Modifications: None
***************************/
void printCheck(double hours, double rate, double amount)
{
	cout << "\nHours Worked: " << hours << endl;
	cout << "Rate per Hour: $" << rate << endl;
	cout << "Salary: $" << amount << endl;
}

/***************************
Function: funcOne
Precondition: the values of x and y must be set prior to the function call
 x - arbitrary int value
 y - arbitrary int value
Postcondition: this function takes the values of x and y, takes input from the user for a temporary number, and uses these numbers to change the value of x
Dates of Coding: October 21, 2018
Modifications: None
***************************/
void funcOne(int& x, int y)
{
	int temp;
	cout << "\nInput a number:" << endl;
	cin >> temp;

	x = (2 * x) + y - temp;

}


/***************************
Function: nextChar
Precondition: the value of z must be set prior to the function call
 z - arbitrary char value
Postcondition: this function takes the value of z and changes it to the char following whatever it is
Dates of Coding: October 21, 2018
Modifications: None
***************************/
void nextChar(char& z)
{
	z++;
}