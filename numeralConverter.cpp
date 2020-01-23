/****************************
Name: Kryzstof Kudlak
Course: CIT 163 – Programming Practicum w/C++
Date: December 4, 2018
***************************
Files for Assignment: numeralConverter.cpp
Purpose of File: to convert a roman numeral to an integer
*****************************/

#include <iostream>
#include <string>
using namespace std;

// class which stores a roman numeral and its decimal form
class romanType
{
public: 
	string numeral;     // the roman numeral (as entered by user)
	int decimal;		// the numeral in decimal form (calculated by the convert function)
	void convert();     // the function which decimalizes the roman numeral
};


int dec(char ch);  // a function which can take a single roman numeral (such as 'X') and convert it to its decimal form

/***************************
Function: Main
Precondition: all above headers, the dec function, and the romanType class must be defined
Postcondition: this function asks the user to input a roman numeral and converts it to an integer
Dates of Coding: December 4, 2018
***************************/
int main()
{
	romanType Number;  // constructor which creates an uninitialized roman numeral object

	cout << "Please enter a roman numeral to be converted:" << endl;  // requesting user input
	cin >> Number.numeral;  // user enters a roman numeral which is assigned to the class's "numeral" variable

	Number.convert();                                   // uses a member fxn to convert to decimal
	cout << "The roman numeral " << Number.numeral      // outputs the numeral
		<< " is the decimal number " << Number.decimal  // outputs its decimal form
		<< '.' << endl;

	return 0;
}


/***************************
Function: romanType::convert
Precondition: this is a member function of the romanType class.  In order to work, a roman numeral must have been inputted
Postcondition: this function takes the numeral, loops through it, and converts it to an integer
Dates of Coding: December 4, 2018
***************************/
void romanType::convert()
{
	decimal = 0;  // setting the decimal variable to 0 so it doesnt mess up the math
	for (int i = 0; i < numeral.length() - 1; i++)        // looping through the entire numeral without throwing an index out of bounds error
	{
		if (dec(numeral[i]) >= dec(numeral[i + 1])) {     // if the current character has a decimal value higher than the next character, 
			decimal += dec(numeral[i]);                   // then we add it to the running decimal value total
		}
		else if (dec(numeral[i]) < dec(numeral[i + 1])) { // however, if the current char has a dec value lower than the next char,
			decimal -= dec(numeral[i]);                   // then we subtract this value from the running total
		}
	}
	// my for loop is weird, and including the final number in the numeral sequence here prevents the index from going out of bounds.  Not the most elegant solution, but it works
	decimal += dec(numeral[numeral.length() - 1]);
} 

/***************************
Function: dec
Precondition: this function takes as input any char value (used in the convert member function)
Postcondition: and returns its roman numeral equivalent
Dates of Coding: December 4, 2018
***************************/
int dec(char ch)
{
	switch (ch)
	{
	case 'M': return 1000; break;  // M = 1000
	case 'D': return 500;  break;  // D = 500
	case 'C': return 100;  break;  // C = 100
	case 'L': return 50;   break;  // L = 50
	case 'X': return 10;   break;  // X = 10
	case 'V': return 5;    break;  // V = 5
	case 'I': return 1;    break;  // I = 1
	default:  return 0;    break; 
	}
}