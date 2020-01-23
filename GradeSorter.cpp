/****************************
Name: Kryzstof Kudlak
Course: CIT 163 – Programming Practicum w/C++
Date: November 6, 2018
***************************
Files for Assignment: GradeSorter.cpp
Purpose of File: to sort the grades of students
*****************************/

#include <iostream>
#include <fstream>

using namespace std;

void sortGrades(int scores[8], int grade); // puts the grades in their appropriate category
void output(int scores[8]);                // provides a neatly formatted output

/***************************
Function: main
Precondition: all above headers must be included and std namespace must be used
Postcondition: this function takes in integer grades of students from a file and determines how many scores are in each grading range
Dates of Coding: November 6, 2018
***************************/
int main()
{
	int scores[8] = { 0 }; // scores array to track the number of people in each score range
	int grade;             // input variable to store each grade

	ifstream file;
	file.open("grades.txt"); // opening the file with student grades

	while (! file.eof()) // looping through said file
	{
		file >> grade;             // getting each grade
		sortGrades(scores, grade); // finding which range each grade belongs in
	}

	output(scores); // outputting results

	return 0;
}

/***************************
Function: sortGrades
Precondition: this function must be used in a while loop, scores must be defined, and the grade must be taken from the file
Postcondition: this function takes the grade of a student and determines which range it falls under
Dates of Coding: November 6, 2018
***************************/
void sortGrades(int scores[8], int grade)
{
	grade /= 25;     // the index for the score array is found by dividing by 25, seperating the array into 8 categories
	if (grade == 8)  // if the grade is 200, then my method for finding the category sets it to 8 which is out of the range of my array
	{
		grade--;     // so I just change this special case to 7 because I'm not very clever
	}
	scores[grade]++; // this adds one to the given index
}

/***************************
Function: output
Precondition: the scores array must be populated for this function to work
Postcondition: this function outputs the amount of students in each score range
Dates of Coding: November 6, 2018
***************************/
void output(int scores[8])
{
	int r1 = 0;  // lower bound for range output
	int r2 = 24; // upper bound for range output
	for (int i = 0; i < 8; i++) // iteration through scores array
	{
		cout << r1 << '-' << r2 << " Range: " << scores[i] << endl; // outputs: lowerbound-upperbound Range: total people in that range
		r1 += 25; // incraments the range variables for the next iteration
		r2 += 25;
		if (r2 == 199) // special case variable because the final category is 26 values not 25 and I'm again not clever enough for a different solution
		{
			r2++;
		}
	}
}