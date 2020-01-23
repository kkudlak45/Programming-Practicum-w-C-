/****************************
Name: Kryzstof Kudlak
Course: CIT 163 – Programming Practicum w/C++
Date: December 12, 2018
***************************
Files for Assignment: FinalProject.cpp, and whatever txt file you choose to load/save to
Purpose of File: this program is a "database for keeping track of a student’s academic history and its related statistics"
*****************************/

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

const int DIF_COURSES = 50;  // my assumed max number of courses a student can take, this influences the student.courses array's length & all loops which loop through it

// struct which makes it somewhat easier to store student info bc I can't implement a class
struct student
{
	string name; // a string storing the student's full name
	string courses[DIF_COURSES][5]; // column format: [ALPHA DESIGNATOR, COURSE NUM, COURSE TITLE, HOURS, GRADE], each row is a different course
};

// full function documentation can be found in the function definitions below main()
int menu();                       // outputs a menu of actions & asks the user which one they would like to carry out
void enterName(student&);         // allows the user to enter a student's name
void enterCourse(student&);       // allows the user to enter a course for the student
void searchByAlpha(student&);     // allows the user to search for & display courses by alpha designator
void searchByGrade(student&);     // allows the user to search for & display courses by grade
void displayCourses(student&);    // displays all the courses taken by the student
void displayGPA(student&);        // calculates & displays the student's GPA
void saveData(student&);          // saves the student's data to a user-specified file
void loadData(student&);          // loads a student's data from a user-specified file
int gradeValue(string);              // helps with GPA calculation by returning the values of letter grades stored as strings
void outputCourse(int, student&);    // helps with displaying course info & keeps me from repeating identical loops

/***************************
Function: main
Precondition: all above headers must be included, function prototypes must be there, there must be the array size constant, and the struct
Postcondition: this function presents the user with a list of actions to perform on this database
Dates of Coding: December 10, 2018
Modifications: switched from a class implementation to a struct because it was easier and more efficient
***************************/
int main()
{
	bool c = true;  // I have to loop the switch statement for this program to be functional, so this c (for continue) bool controls when it stops
	student Student;  // this is our student object/instance

	do {
		switch (menu())  // the menu function requests user input on which action to perform and puts it through this switch statement
		{
		case 1:   enterName(Student);        break;                  //  1. enter name
		case 2:   enterCourse(Student);      break;                  //  2. enter by alpha des
		case 3:   searchByAlpha(Student);    break;                  //  3. search by alpha des
		case 4:   searchByGrade(Student);    break;                  //  4. search by grade
		case 5:   displayCourses(Student);   break;                  //  5. display all courses
		case 6:   displayGPA(Student);       break;                  //  6. display student gpa
		case 7:   saveData(Student);         break;                  //  7. save this data to a file
		case 8:   loadData(Student);         break;                  //  8. load data from a file
		case 9:   cout << "Exiting program"; c = false;      break;  //  9. exit the program
		default:  cout << "ERR: Exiting Program"; c = false; break;  //  invalid action, exit program
		}
	} while (c == true);

	return 0;
}

/***************************
Function:menu
Precondition: this function gets called as part of a switch statement
Postcondition: this function will present the user with a menu of options and allow him/her to choose an action (this is the foundation of my program)
Dates of Coding: December 10, 2018
***************************/
int menu()
{
	int choice;  // variable for the user's inputted choice
	// this array of options keeps me from hard coding the menu because nobody wants to hard code the menu
	string selections[9] = { "Enter Student Name", "Add a Course to the Database", "Search for Course(s) by Alpha - Designator", "Search for Course(s) by Grade", "Show a Listing of All Courses Taken w / Grades", "Display GPA Information", "Save Database to a file", "Load Database from a file", "Exit" };

	cout << "\nMenu:" << endl; //cute lil menu title
	for (int i = 0; i < 9; i++) // looping throught our array of options
	{
		cout << i + 1 << ". " << selections[i] << endl;  // outputs format: "X. Action Title" where x is the iteration + 1
	}

	// requesting the user's desired action
	cout << "Please input the number corresponding with the action you would like to take:" << endl;
	cin >> choice;

	return choice;  // sending this action to the switch statement to be carried out
}

/***************************
Function: enterName
Precondition: the student struct, like all other menu functions, must be passed by reference
Postcondition: this function will requests the student's name & stores it in the struct
Dates of Coding: December 10, 2018
***************************/
void enterName(student& Student)
{
	string full, trash;  // I needed a string to take input for the user's name as well as one to get rid of some trashy input which messes everything up (pretty sure it's a newline character)
	
	// requesting the name
	cout << "\nYou have chosen to enter the name of a student" << endl
		<< "Please enter the student's full name:" << endl;
	getline(cin, trash);  // trash removal (this will be seen later as well)
	getline(cin, full);   // getting the student name

	Student.name = full;  // storing the name

	// a nice success message so our user knows it worked
	cout << "Success! Student's name has been entered as: " << Student.name << endl;
}

/***************************
Function: enterCourse
Precondition: student struct must be passed, and having a name entered would be helpful
Postcondition: this function allows the user to enter new courses into the student's record
Dates of Coding: December 11, 2018
***************************/
void enterCourse(student& Student)
{
	string trash;  // needed a trash var once again
	int j;  // j values are important for navigating my 2D array, they represent the different courses

	// this loop finds the first available row to enter a course into (first blank row)
	for (int i = 0; i < DIF_COURSES; i++) // checking each row
	{
		if (Student.courses[i][0] == "")  // if the row is blank,
		{
			j = i;                        // then use this j value
			break;                        // and cut off the loop
		}
	}

	// this is just a series of outputs asking for information relating to the course, boring hard code
	cout << "\nYou have chosen to enter a course into this student's record" << endl << endl
		<< "Please enter the alpha designator of the course (ie., CIT):" << endl;
	getline(cin, trash); // notice my trash removal again, I still think it's a newline character
	getline(cin, Student.courses[j][0]); // alpha des
	cout << "Please enter the course number (ie., 163):" << endl;
	getline(cin, Student.courses[j][1]); // course num
	cout << "Please enter the course title (ie., Programming with C++):" << endl;
	getline(cin, Student.courses[j][2]); // course title
	cout << "Please enter the credit hours for this course (ie., 3):" << endl;
	getline(cin, Student.courses[j][3]); // credit hours
	cout << "Please enter the grade the student earned in this course (ie., A):" << endl;
	getline(cin, Student.courses[j][4]); // grade earned

	// once again, confirming to the user that everything went well
	cout << "Success! You have entered: ";
	for (int i = 0; i < 5; i++)
	{
		cout << Student.courses[j][i] << ' ';
	}
	cout << "for this student." << endl;
}

/***************************
Function: searchByAlpha
Precondition: student struct must be passed.  it's generally helpful to have some courses entered before searching for them
Postcondition: this function asks the user to input an alpha designator & shows all courses with that particular alpha designator
Dates of Coding: December 11, 2018
***************************/
void searchByAlpha(student& Student)
{
	string alpha; // string to store the alpha des
	bool coursesFound = false; // bool val which tells the computer to output an error message if no courses were found

	// asking for the alpha des
	cout << "You have chosen to search for a course by alpha designator" << endl << endl
		<< "Enter the alpha designator you would like to search for:" << endl;
	cin >> alpha;
	
	// formatting a nice looking table for the course info
	cout << '\n' << left << setw(15) << "Course" << setw(30) << "Title" << setw(10) << "Hours" << setw(10) << "Grade" << endl;
	for (int j = 0; j < DIF_COURSES; j++) // looping through each course
	{
		if (Student.courses[j][0] == alpha) { // checking to see if it has the desired alpha des (first column is alpha des)
			outputCourse(j, Student); // if it is, then we use the handy dandy output course function to output it in a nice format
			coursesFound = true; // and we make sure that our computer knows that at least one of the courses matches this alpha designator
		}
		else if (Student.courses[j][0] == "") { // once we get to a point where there are no more courses in the 2D array, we can break the loop
			break;
		}
	}

	if (coursesFound == false) // if no courses were found, we tell the user
	{
		cout << "No courses were found for this particular alpha designator" << endl;
	}

}

/***************************
Function: searchByGrade
Precondition: student struct must be passed, and again, having courses entered is helpful
Postcondition: this function allows the user to search courses by grade and returns those courses in a nice format, similar to searchByAlpha
Dates of Coding: December 11, 2018
***************************/
void searchByGrade(student& Student)
{
	string grade;  // stores the grade we are looking for
	bool coursesFound = false; // like the other search, if we dont find courses with this particular grade, then we want to tell the user

	// asking for the desired grade
	cout << "You have chosen to search for a course by grade" << endl << endl
		<< "Enter the letter grade you would like to search for:" << endl;
	cin >> grade;

	// nice format
	cout << '\n' << left << setw(15) << "Course" << setw(30) << "Title" << setw(10) << "Hours" << setw(10) << "Grade" << endl;
	for (int j = 0; j < DIF_COURSES; j++) // looping through each course
	{
		if (Student.courses[j][4] == grade) { // if the courses grade is the desired grade...
			outputCourse(j, Student); // then we output it
			coursesFound = true; // and we let the computer know it exists
		}
		else if (Student.courses[j][4] == "") { // once we get to a point where there are no more courses,
			break;                              // we break the loop
		}
	}

	if (coursesFound == false)  // if we didn't find any courses with that grade, we tell the user
	{
		cout << "No courses were found for this particular grade" << endl;
	}

}

/***************************
Function: displayCourses
Precondition: student struct must be passed, and having courses entered is pretty much essential
Postcondition: this function displays all of the courses on record for the student
Dates of Coding: December 11, 2018
***************************/
void displayCourses(student& Student)
{
	// similar to the searches, we want a table format for the courses
	cout << '\n' << left << setw(15) << "Course" << setw(30) << "Title" << setw(10) << "Hours" << setw(10) << "Grade" << endl;
	for (int j = 0; j < DIF_COURSES; j++) // we loop through each course
	{
		if (Student.courses[j][4] == "") { // of course if there are no more courses, we want to break the loop
			break;
		}
		outputCourse(j, Student); // but if it isn't time to break, we want to use our handy dandy output course function to output the course
	}
}

/***************************
Function: displayGPA
Precondition: student struct must be passed, and having courses entered would be helpful
Postcondition: this function takes all the course info and turns it into a GPA and displays said GPA
Dates of Coding: December 12, 2018
***************************/
void displayGPA(student& Student)
{
	double qualityPoints = 0; // running total of QP
	double qualityHours = 0;  // running total of QH
	double GPA;               // the GPA to be outputted at the end of this function

	for (int j = 0; j < DIF_COURSES; j++) // looping through all courses
	{
		if (Student.courses[j][0] == "") { // if there are no more courses, we break
			break;
		}
		if (Student.courses[j][4] != "F") // if there are courses, and this course wasn't failed (bc F's don't count), then 
		{
			qualityHours += stoi(Student.courses[j][3]);  // we add the credit hrs to QH (converting string to int)
			qualityPoints += stoi(Student.courses[j][3]) *  gradeValue(Student.courses[j][4]); // and do cred hrs * grade to get QP
			               // ^ this converts hrs string to int, and ^ this converts the letter grade to its int value using a later defined fxn
		}
	}

	GPA = qualityPoints / qualityHours;  // grand total GPA, really basic bc of my complicated loop

	cout << fixed << setprecision(4);  // formatting output to show 4 decimal places
	cout << "\nStudent " << Student.name << "'s GPA is " << GPA << endl; // telling the user the student's GPA
	cout.unsetf(ios::fixed); // getting rid of my weird format
}

/***************************
Function: saveData
Precondition: student struct must be passed with all its hopefully entered info
Postcondition: this function allows the user to save student info to a file
Dates of Coding: December 12, 2018
***************************/
void saveData(student& Student)
{
	ofstream outFile;  // declaring an output stream
	char fileName[50]; // letting the user enter a file name using a c-string

	// gimme a file to output to
	cout << "\nYou have chosen to store the student's data in the database" << endl << endl
		<< "Please enter the name of the file you would like to store this student's data:" << endl;
	cin >> fileName;

	outFile.open(fileName); // lemme open that file

	outFile << Student.name << endl; // let's put the student's name at the top of the file
	for (int j = 0; j < DIF_COURSES; j++) // and loop through his/her courses
	{
		if (Student.courses[j][0] == "") { // of course if there are no more courses, we break the loop
			break;
		}
		for (int i = 0; i < 5; i++) // for each course we must dump its info to the file
		{
			outFile << Student.courses[j][i] << '|'; // each info fragment is seperated by the | character bc I don't expect anyone to use it ever
		}

		outFile << endl; // makes new lines for each course
	}

	/*
	Basically what this will look like in a file is:
	Student Full Name
	ALPHA|123|This is the Title|4|A
	*/

	outFile.close(); // close the output file bc it should be closed

	// give the user that sweet message of success
	cout << "Success! All data has been appropriately stored." << endl;
}

/***************************
Function: loadData
Precondition: hopefully a file has some data in it, and the student struct should be passed
Postcondition: this function allows the user to load student info from a file into the struct, opposite of saving
Dates of Coding: December 12, 2018
***************************/
void loadData(student& Student)
{
	ifstream inFile;  // input file
	char fileName[50]; // c-string for user selection
	string trash; // trash var to avoid input gathering issues

	// getting a file name to take input from 
	cout << "\nYou have chosen to store the student's data in the database" << endl << endl
		<< "Please enter the name of the file you would like to store this student's data:" << endl;
	cin >> fileName;

	inFile.open(fileName); // opening this file

	getline(inFile, Student.name); // getting the name (should be first line)

	int j = 0; // starting at the first course (row number = 0)
	while (!inFile.eof()) // looping til the end of the file
	{
		for (int i = 0; i < 5; i++) // get all course info in the line
		{
			getline(inFile, Student.courses[j][i], '|'); // get input by taking input until the | character which tells it to stop taking input
		}
		getline(inFile, trash); // get rid of input ruining trash (probably still the newline character)
		j++; // incrament to the next row of courses
	}

	inFile.close();  // close up the file cuz we should

	// another sweet message of success
	cout << "Success! All data for student " << Student.name << " has been loaded." << endl;
}

/***************************
Function: gradeValue
Precondition: this function takes a letter grade as input 
Postcondition: and returns that letter grade's value
Dates of Coding: December 12, 2018
***************************/
int gradeValue(string grade)
{
	char g = grade[0]; // changing the string to a char
	switch (g) // putting it through the switch statement
	{ 
	case 'A': return 4; // a = 4
	case 'B': return 3; // b = 3, etc.
	case 'C': return 2;
	case 'D': return 1;
	case 'F': return 0;
	}
}

/***************************
Function: outputCourse
Precondition: this function takes the course row (j value) and the student struct
Postcondition: and it uses this information to output the course info in a nice format
Dates of Coding: December 11, 2018
***************************/
void outputCourse(int j, student& Student)
{
	cout << Student.courses[j][0] << ' ' << left // alpha des
		<< setw(11) << Student.courses[j][1]     // course num
		<< setw(30) << Student.courses[j][2]     // title
		<< setw(10) << Student.courses[j][3]     // hours
		<< setw(10) << Student.courses[j][4]     // grade
		<< endl;
}

