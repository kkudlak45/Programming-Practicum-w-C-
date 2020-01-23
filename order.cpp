/****************************
Name: Kryzstof Kudlk
Course: CIT 163 – Programming Practicum w/C++
Date: November 27, 2018 (apologies for lateness)
***************************
Files for Assignment: order.cpp, menuItems.txt.
Purpose of File: to present the user with a menu of some generic restuarant, allow them to choose what they would like to eat, then print a bill for their meal
*****************************/

#include <iostream>  // generic i/o
#include <string>    // needed for storing the names of food items
#include <fstream>   // my chosen way of initializing the struct array
#include <iomanip>   // important for formatting the output at various intervals
using namespace std;

const double TAX_RATE = 0.06;   // tax rate constant
const int SIZE = 7;             // array size constant (there are 7 food items)

// struct for each menu/dinner item (I think the required names of several variables on the assignment page changed after the due date, so I took the time to change them)
struct dinnerItemType
{
	string dinnerItem;       // name of dinner item
	double dinnerPrice;      // its price
	int dinnerOrdered = 0;   // the amount of this item ordered by the customer
};

// full documentation with each function definition
void getFood(dinnerItemType menuItems[]);     // reads a file to initialize array of food item structs
void printMenu(dinnerItemType menuItems[]);   // outputs the menu to the user
void takeOrder(dinnerItemType menuItems[]);   // takes the user's order & tells he/she how to order
void printCheck(dinnerItemType ourMenu[]);    // prints the bill

/***************************
Function: main
Precondition: all above headers are necessary as well as the constants and function definitions
Postcondition: this function controls the order of execution of the other functions and acts as the driving force of this program
Dates of Coding: November 21 - 27, 2018
Modifications: Several edits to variable names bc either the posted assignment changed or I copied wrong
***************************/
int main()
{
	dinnerItemType ourMenu[SIZE];  // array of menu item structs
	getFood(ourMenu);              // adding all the menu items to the array
	printMenu(ourMenu);            // printing the menu using this arry
	takeOrder(ourMenu);            // taking the user's order
	printCheck(ourMenu);           // printing the user's bill

	return 0;
}

/***************************
Function: getFood
Precondition: The struct array must be declared, the struct must be defined, and the txt file must be in the same folder for input
 menuItems[] - the array of structs to be populated by this function
 menuItems.txt - The input stream of all necessary information for populating this array
Postcondition: this function populates the menuItems (ourMenu) array of structs using input from a txt file
Dates of Coding: November 21, 2017
Modifications: changes to var names
***************************/
void getFood(dinnerItemType menuItems[])
{
	ifstream file;
	file.open("menuItems.txt");  // opening the input file

	for (int i = 0; i < SIZE; i++)  // iterating through it
	{
		getline(file, menuItems[i].dinnerItem, '$');  // gets everything up until the dollar sign (aka the food item name) and assigns it to struct.dinneritem
		file >> menuItems[i].dinnerPrice;             // gets the price of the item (much easier than getting the name)
	}

	file.close();  // closing the file bc I don't need it anymore
}

/***************************
Function: printMenu
Precondition: the array of structs must be populated and ready to use
Postcondition: this function prints the menu to the user.
Dates of Coding: November 23, 2018
Modifications: Probably also a few var name changes
***************************/
void printMenu(dinnerItemType menuItems[])
{
	cout << "Menu:" << endl;        // "hey, this is a menu"
	for (int i = 0; i < SIZE; i++)  // iterating through the array of structs
	{
		cout << i + 1 << ".  "                    // this numbers each food item for ordering purposes
			<< setw(20) << setfill('.') << left   // this basically gives the format of FOOD .....$PRI.CE
			<< menuItems[i].dinnerItem
			<< '$' << menuItems[i].dinnerPrice
			<< endl;
	}
}

/***************************
Function: takeOrder
Precondition: struct array must be populated and menu must be displayed so that this all makes sense
Postcondition: this function takes the user's order & adds 1 to the quantity of each respective item in the arry when ordered
Dates of Coding: November 27, 2018
***************************/
void takeOrder(dinnerItemType menuItems[])
{
	// basic instructions are that the user enters the number of each food item they want to order, 0 is the exit code
	cout << "\nTo order, enter the numbers of the food item you would like to select, seperated by spaces.  When you are finished ordering, enter '0'." << endl;
	int item;    // the int value that the user enters, AKA the number associated w/ the food
	while (cin)  // I needed an indefinite loop
	{
		cin >> item;                      // take the user's order
		if (item == 0) {                  // if it's the exit code, we exit
			break;
		}
		item--;                           // otherwise we format it into an array index
		menuItems[item].dinnerOrdered++;  // and add to that particular struct's item quantity
	}
}

/***************************
Function: printCheck
Precondition: by this time, each struct in the array should be entirely populated and ready to be displayed
Postcondition: this function prints the user's bill
Dates of Coding: November 27, 2018
***************************/
void printCheck(dinnerItemType ourMenu[])
{
	double total = 0;  // for finding the total price of the order
	double itemPrice;  // makes my long cout statement look a little more clean
	cout << fixed << setprecision(2) << setfill(' ');  // formatting so that we get 2 decimal places & whitespace fill (it was set to '.')
	cout << "\nThank you for eating at this generic restuarant!" << endl;  // lighthearted heading
	cout << setw(5) << "Qty" << setw(20) << "Item" << setw(8) << "Price" << endl;  // establishes table columns
	for (int i = 0; i < SIZE; i++)  // once again, iterating through the array
	{
		if (ourMenu[i].dinnerOrdered == 0) {  // if none of this particular item was ordered, then it shouldnt be displayed on the bill, so we ignore it
			continue;
		}
		else {  // but if it was ordered...
			itemPrice = ourMenu[i].dinnerPrice * ourMenu[i].dinnerOrdered; // finds the price of the item based on quantity and the price of an individual item
			cout << left << setw(5) << ourMenu[i].dinnerOrdered            // outputs the quantity
				<< setw(20) << ourMenu[i].dinnerItem                       // outputs the name
				<< '$' << itemPrice << endl;                               // outputs the price
			total += itemPrice;                                            // adds to the total price of the order
		}
	}
	cout << setw(25) << "Tax" << '$' << total * TAX_RATE << endl;               // prints the tax (aka tax rate * order cost)
	cout << setw(25) << "Amount Due" << '$' << total * (1 + TAX_RATE) << endl;  // prints the total cost (order cost * (1 + tax rate))
}