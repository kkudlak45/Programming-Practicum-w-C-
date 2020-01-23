/****************************
Name: Kryzstof Kudlak
Course: CIT 163 – Programming Practicum w/C++
Date: September 17, 2018 (due date)
***************************
Files for Assignment: TicketSales.cpp
Purpose of File: Takes data from a txt file and calculates the amount of people 
in attendance to a concert as well as revenue from ticket sales
Assistance Received: N/A
*****************************/

#include <iostream> // in/output stream
#include <fstream> // file stream
#include <iomanip> // allows use of setprecision
using namespace std;

/***************************
Function: main
Precondition: all above libraries must be included
Postcondition: this function will take data from a text file and use it to 
find the amount of people in attendance to a concert as well as the revenue made
from their ticket sales
Dates of Coding: September 14, 2018
Modifications: None
***************************/

int main()
{
	// turns admissions.txt into an input stream
	ifstream admissions;
	admissions.open("admissions.txt");

	// variables to make sense of the data contained in admissions.txt as well as make calculations 
	double price;
	double totalPrice = 0;
	int people;
	int totalPeople = 0;

	// loop which iterates through each line of the file and calculates the total revenue from tickets as well as people in attendance
	for (int var = 0; var < 3; var++) {
		admissions >> price >> people;
		totalPrice = totalPrice + price * people;
		totalPeople = totalPeople + people;
	}

	// nice looking output which displays findings from the for loop
	cout << fixed << setprecision(2);
	cout << "Tickets Sold: " << totalPeople << endl;
	cout << "Sale Amount: $" << totalPrice << endl;	

	admissions.close(); // closing the txt file

	return 0;
}