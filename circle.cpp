/****************************
Name: Kryzstof Kudlak
Course: CIT 163 – Programming Practicum w/C++
Date: October 21, 2018 (due date)
***************************
Files for Assignment: circle.cpp
Purpose of File: to take points of a circle and determine its measurements
Assistance Received: N/A
*****************************/

#include <iostream>
#include <cmath> // necessary for some math operations
using namespace std;

// pi constant
const double PI = std::atan(1.0) * 4; 

/***************************
Function: distance
Precondition: the values of x1, y1, x2, and y2 must be set
 x1, y1 - coordinates of first point
 x2, y2 - coordinates of second point
Postcondition: this function takes the values of the points and uses distance formula to find the distance between them
Dates of Coding: October 21, 2018
Modifications: None
***************************/
int distance(double x1, double y1, double x2, double y2)
{
	return sqrt(pow((x1 - x2), 2) + pow(y1 - y2, 2));
}

/***************************
Function: Radius
Precondition: the values of x1, y1, x2, and y2 must be set
 x1, y1 - center of circle
 x2, y2 - point on the outside of the circle
Postcondition: this function takes the values of the points and passes them into the distance function to find the radius
Dates of Coding: October 21, 2018
Modifications: None
***************************/
int Radius(double x1, double y1, double x2, double y2)
{
	return distance(x1, y1, x2, y2);
}

/***************************
Function: Circumfrence
Precondition: the value of r must be set
 r - radius of the circle
Postcondition: this function takes the radius of the circle and uses it to find the circumfrence of the circle
Dates of Coding: October 21, 2018
Modifications: None
***************************/
int Circumfrence(double r)
{
	return 2 * PI * r;
}

/***************************
Function: Area
Precondition: the value of r must be set
 r - radius of the circle
Postcondition: this function takes the radius of the circle and uses it to find the area of the circle
Dates of Coding: October 21, 2018
Modifications: None
***************************/
int Area(double r)
{
	return PI * pow(r, 2);
}

/***************************
Function: main
Precondition: cmath and iostream headers must be included, std namespace should be used
Postcondition: this function asks for input of a circles center point and a point on the circle, then finds its radius, circumfrence, and area
Dates of Coding: October 21, 2018
Modifications: None
***************************/
int main() {
	//declaring variables to be used in the functions
	double x1, x2, y1, y2; // circle points
	double r, d, C, A; // measurements of the circle

	// asking for input of the center
	cout << "Enter the coordinates of the center of the circle: \nx = ";
	cin >> x1;
	cout << "y = ";
	cin >> y1;
	
	// asking for input of a point on the circle
	cout << "Enter the coordinates of a point on the circle: \nx = ";
	cin >> x2;
	cout << "y = ";
	cin >> y2;

	// determining all measurements of the circle
	r = Radius(x1, y1, x2, y2); // radius
	d = r * 2; // diameter
	C = Circumfrence(r); // circumfrence
	A = Area(r); // area

	// outputting each measurement
	cout << "\nRadius: " << r << endl;
	cout << "Diameter: " << d << endl;
	cout << "Circumfrence: " << C << endl;
	cout << "Area: " << A << endl;

	return 0;
}