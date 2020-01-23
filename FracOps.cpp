/****************************
Name: Kryzstof Kudlak
Course: CIT 163 – Programming Practicum w/C++
Date: October 31, 2018 
***************************
Files for Assignment: FracOps.cpp
Purpose of File: allows the user to perform simple mathematical operations on fractions
Assistance Received: Jennifer Morgan, Michael Morgan
*****************************/

#include <iostream>
using namespace std;

// full documentation of all these functions can be found below main
int menu();                                    // generates a menu
void getInput(int&, int&, int&, int&);         // gathers input from the user
void add(int, int, int, int, int&, int&);      // adds fractions
void subtract(int, int, int, int, int&, int&); // subtracts fractions
void multiply(int, int, int, int, int&, int&); // multiplies
void divide(int, int, int, int, int&, int&);   // divides


/***************************
Function: main
Precondition: must use the iostream header and std namespace
Postcondition: this function presents the user with a menu, asks the user which operation they would like to perform on two fractions, gets those two fractions, and performs the desired operation on them
Dates of Coding: October 24, 2018
***************************/
int main()
{
	int n1, d1, n2, d2, nfinal, dfinal;    // all fraction variables (n for numerator, d for denominator)
	int sel = menu();    // gives the user a menu and records their selection as an int between 1 and 4

	getInput(n1, d1, n2, d2);    // asks the user which fractions they would like to operate on

	switch (sel)    // uses the user selection & performs appropriate operation
	{
	case 1: add(n1, d1, n2, d2, nfinal, dfinal);      break; // add
	case 2: subtract(n1, d1, n2, d2, nfinal, dfinal); break; // subtract
	case 3: multiply(n1, d1, n2, d2, nfinal, dfinal); break; // multiply
	case 4: divide(n1, d1, n2, d2, nfinal, dfinal);   break; // divide
	}

	// final print of solution
	cout << "\nThe solution is " << nfinal << "/" << dfinal << endl;

	return 0;
}


/***************************
Function: menu
Precondition: none
Postcondition: this function presents the user with a menu of operations and asks which one they would like to perform.  it returns the int value of their selection
selection - number constituting which operation the user selected
Dates of Coding: October 24, 2018
***************************/
int menu()
{
	int selection;    // variable to record user selection

	// generates a fancy menu, each operation is associated with an int value
	cout << "Fraction Calculator Menu"
		<< "\n    1    Add"
		<< "\n    2    Subtract"
		<< "\n    3    Multiply"
		<< "\n    4    Divide"
		<< "\nChoose the operation you would like to perform by inputting the number associated with it: "
		<< endl;

	// gets what operation the user wants
	cin >> selection;
	while (selection < 1 || selection > 4)    // if they choose an invalid operation, send an error message and ask again
	{
		cout << "[ERROR] Selection must be between 1 and 4" << endl;
		cin >> selection;
	}

	return selection;    // tell the main function which operation we want to perform
}

/***************************
Function: menu
Precondition: variables for the numerators and denominators of each function must be initiliazed and ready to be set to values
n1 - numerator of fraction one
d1 - denominator of fraction one
n2 - numerator of fraction two
d2 - denominator of fraction two
Postcondition: takes input from the user for which fractions they want to use and sets the values of each of the above variables accordingly
Dates of Coding: October 25, 2018
***************************/
void getInput(int& n1, int& d1, int& n2, int& d2)
{
	char garbage;    // trash variable for the '/' character in each fraction

	// input of fraction one
	cout << "Enter the fraction you would like to perform this operation on in the form n/d" << endl;
	cin >> n1 >> garbage >> d1;  // see look how clever I am, now we don't have to worry about the '/'

	// input of fraction two
	cout << "Enter the other fraction used in the operation in the form n/d" << endl;
	cin >> n2 >> garbage >> d2;
}


/***************************
Function: add
Precondition: variables for the numerators and denominators of each fraction must be set
vvvvv these will be the same for each function from here on out, so I will not list them and waste space after this
n1 - numerator of fraction one
d1 - denominator of fraction one
n2 - numerator of fraction two
d2 - denominator of fraction two
n - numerator of result
d - denominator of result
Postcondition: takes the two fractions and adds them
Dates of Coding: October 26, 2018
***************************/
void add(int n1, int d1, int n2, int d2, int& n, int& d)
{
	if (d1 == d2) {    // if the denominators are the same, then we don't have to change them in order to add
		n = n1 + n2;
		d = d1;
	}
	else {    // however if they are NOT the same, we must multiply each fraction by the other fraction's denominator and make everything ugly before we can add
		n = n1 * d2 + n2 * d1;
		d = d1 * d2;
	}
}

/***************************
Function: subtract
Precondition: variables for the numerators and denominators of each fraction must be set
(all aforementioned fraction defining variables still serve the same purpose)
Postcondition: takes the two fractions and subtracts them
Dates of Coding: October 26, 2018
***************************/
void subtract(int n1, int d1, int n2, int d2, int& n, int& d)
{
	if (d1 == d2) {     // similar to the add function (this is literally a copy/paste with one sign change), we can do a basic operation if denominators match
		n = n1 - n2;
		d = d1;
	}
	else {     // however, if they don't match, we multiply by denominators and make our fractions disgusting
		n = n1 * d2 - n2 * d1;
		d = d1 * d2;
	}
}

/***************************
Function: multiply
Precondition: variables for the numerators and denominators of each fraction must be set
(all aforementioned fraction defining variables still serve the same purpose)
Postcondition: takes the two fractions and multiplies them
Dates of Coding: October 26, 2018
***************************/
void multiply(int n1, int d1, int n2, int d2, int& n, int& d)
{		
	n = n1 * n2;    // multiplication is easy, we just do numerator * numerator and denominator * denominator
	d = d1 * d2;
}

/***************************
Function: divide
Precondition: variables for the numerators and denominators of each fraction must be set
(all aforementioned fraction defining variables still serve the same purpose)
Postcondition: takes the two fractions and divides them
Dates of Coding: October 26, 2018
***************************/
void divide(int n1, int d1, int n2, int d2, int& n, int& d)
{
	n = n1 * d2;    // division is also easy, except the second fraction must be flipped before we multiply it to the other
	d = d1 * n2;
}