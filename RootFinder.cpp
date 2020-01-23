/****************************
Name: Kryzstof Kudlak
Course: CIT 163 – Programming Practicum w/C++
Date: September 25, 2018
***************************
Files for Assignment: RootFinder.cpp
Purpose of File: finds the number and type of roots of a quadratic equation in standard form
Assistance Received: N/A
*****************************/

#include <iostream>
#include <cmath>
using namespace std;

/***************************
Function: main
Precondition: iostream and cmath must be included and the std namespace must be used
Postcondition: Outputs what types of roots the equation has as well as the roots themselves
if the equation has real roots
Dates of Coding: September 14, 2018
Modifications: N/A
***************************/

int main()
{
	double a, b, c; // equation variables
	double root1, root2, discriminant; // variables to hold the roots & discriminant

	// gathering input for a, b, and c
	cout << "Input the coefficient of x^2 (a): " << endl;
	cin >> a;
	cout << "\nInput the coefficient of x (b): " << endl;
	cin >> b;
	cout << "\nInput the constant (c): " << endl;
	cin >> c;

	discriminant = pow(b, 2) - (4 * a*c); // calculating the discriminant using the quadratic formula

	// decision block using the discriminant to determine how many roots the equation has
	if (discriminant > 0) // if the discriminant is bigger than 0, the equation has two real roots
	{ 
		root1 = (-b + sqrt(discriminant)) / (2 * a); // finds the roots
		root2 = (-b - sqrt(discriminant)) / (2 * a);
		cout << "\nThe function has two real roots: x = " << root1 << " and x = " << root2;
	}
	else if (discriminant == 0) // if the discriminant is 0, there is one real root
	{
		root1 = (-b) / (2 * a); // finds that root
		cout << "\nThe function has one real root: x = " << root1;
	}
	else if (discriminant < 0) // if the discriminant is less than 0, there are two imaginary roots which I don't think I can find
	{
		cout << "\nThe function has two complex roots";
	}

	cout << endl; // format thing thrown in to make the output more clear

	return 0;
}