//************************************  PROGRAM IDENTIFICATION  ***************************************
//*                                                                                                   *
//*   PROGRAM FILE NAME:  Source1.cpp          ASSIGNMENT #:  1             Grade: _________          *
//*                                                                                                   *
//*   PROGRAM AUTHOR:         Khushbu Shah                                                            *
//*                   ___________________________________________________                             *
//*                                   Khushbu Shah                                                    *
//*                                                                                                   *
//*   COURSE #:  CSC 30500                                 DUE DATE:09/08/2020                        *
//*                                                                                                   *
//*****************************************************************************************************


//preprocessor directives
#include <iostream>                     //for output and Input streams
#include<string>                       // to Insert thie string
#include<iomanip>                     //to formate the output
#include<fstream>                    //for inserting a file and outputting it
using namespace std;                //namespace to use in program



//prototypes

void addCourse();                  //add courses to the txt file
void addGrade();                   //add grades to the file.txt
void SemCode();                    //add semesters with term to the file
void NameAndNumber();              //add names and numbers
void AddTranscript();              //add transcript including all info into the file
void ListCourse();                 //list out all course
void ListGrade();                   //list out all grades
void ListSemester();                //list out all semester
void ListNameNumbers();             //list out names and numbers
void PrintTranscript();              //get you the final transcript when entering last and first name

int main()
{

	char command;
	char type;
	cout << ">>";
	do
	{
		//input the command
		cin >> command;
		if (command == 'a')      //if they choose to add student
		{
			cin >> type;         //choose which type of commend
			if (type == 'c')    //to add courses
			{
				//call the function
				addCourse();
			}
			else if (type == 'g')    //to addgrade type
			{
				//call the function
				addGrade();
			}
			else if (type == 'm')    //to add semester code + last 2 digit of year+ year + term
			{
				//call the function 
				SemCode();
			}
			else if (type == 's')    //to add last+first+phone number
			{
				//call the function
				NameAndNumber();
			}
			else if (type == 't')    //to add L.N + F.N +course prefix +course num+ course grade + semester code
			{
				//call the function 

				AddTranscript();
			}
		}

		//break; <- do not need this

		//set other conditions
		if (command == 'l')       //listing courses, grade type, semestercode,(f.n,l.n,phone#),trascript
		{
			cin >> type;
			if (type == 'c')
			{
				//call listing function
				ListCourse();
			}
			if (type == 'g')
			{
				//call listing function
				ListGrade();
			}
			if (type == 'm')
			{
				//call the function
				ListSemester();
			}
			if (type == 's')
			{
				//call the function
				ListNameNumbers();
			}


		}

		if (command == 't')               //this commend by itself to build the transcript
		{
			PrintTranscript();            //call this function here
		}
		

		//in case user wants to quit now

		if (command == 'q')
		{
			exit;
		}

	} 
	while (command != 'q');

}


void addCourse()
{
	string coursePrefix;           // string for course prefix like CSC
	string courseTitle;             //Course Title like computer system
	int courseNum, creditHours;      //30500 and credit hour
	cin >> coursePrefix >> courseNum >> courseTitle >> creditHours;   //input declared variables

	//now open the file
	ofstream outfile("AddCourse.txt", ios::app);

	//output the userinput variables
	outfile << coursePrefix << " " << courseNum << " " << courseTitle << " " << creditHours << endl;

	//closing the file
	outfile.close();

	main();                //return to the main

	
}
//this function add grades into file
void addGrade()
{
	string g;             //declaring grade type A,B etc
	float GradeValue;     //Declaring value according to grades. user can manually do that

	cin>> g >> GradeValue;   //user input these var

	//now open the file
	ofstream outfile("AddGrade.txt", ios::app);

	
	//outputting grades and value
	outfile << g <<" " << GradeValue<<endl;
	outfile.close();          //closing the file

	main();                  //return to the main

}

void SemCode()
{
	//string m;
	string semesterCode;        //F86, Sp89
	int year;                   //Declare year
	string term;                //spring , summer etc

	
	cin >> semesterCode >> year >> term;              //inputting semester code, year and term

	//now open the file
	ofstream outfile("AddSemesterCode.txt", ios::app);

	
	outfile << semesterCode << " "<< year << " "<< term<<endl;
	outfile.close();

	main();

}

void NameAndNumber()
{
	string fname;
	string lname;
	string number;

	cin >> fname  >> lname >> number;

	//now open the file
	ofstream outfile("AddName&Number.txt", ios::app);

	outfile << fname << " " << lname << " " << number<<endl;
	outfile.close();
	main();
}

void AddTranscript()
{
	ifstream ifile("AddTranscript.txt");
	string lname;
	string fname;
	string CoursePrefix;        //F86,sp89
	int CourseCode;
	string grade;
	string TermCode;


	//declaring variables to sort semesters
	int temp;
	//int k;
	int flag = 0;
	static int n = 100; //total possible size

	cin >> lname >> fname >> CoursePrefix >> CourseCode >> grade >> TermCode;

	//sort semester and term then outfile it                        //Here I tried to sort by the course code and used that website
	//ascending order, using bubble sort                           //however It didnt work maybe because failure to use the array..
	//https://mathbits.com/MathBits/CompSci/Arrays/Bubble.htm
	//open this file to write in
	//for (int i = 0; i < n - i - 1; i++)
	//{
	//	if (TermCode.length > TermCode.length++)
	//	{
	//		temp = TermCode.length;
	//		TermCode.length = TermCode.length++;  //next int come in front
	//		TermCode.length++ = temp;

	//		//we have to switch all elements with semester
	//		
	//		temp = lname.length;
	//		lname.length = lname.length++;
	//		lname.length++ = temp;

	//		temp = fname.length;
	//		fname.length = fname.length++;
	//		fname.length++ = temp;

	//		//for switching course prefix according to the term
	//		temp = CoursePrefix.length;
	//		CoursePrefix.length = CoursePrefix.length++;
	//		CoursePrefix.length++ = temp;

	//		//switch CourseCode

	//		temp = CourseCode;
	//		CourseCode = CourseCode++;
	//		CourseCode++ == temp;

	//		temp = grade.length;
	//		grade.length = grade.length++;
	//		grade.length++ = temp;

	//		flag = 1;    //indicates that swapping process occured


	//	}

	//open the file
	
	ofstream outfile("AddTranscript.txt", ios::app);

	//output the variables situated 
	outfile << lname << " " << fname << " " << CoursePrefix << " " << CourseCode << " " << grade << " " << TermCode << endl;
	outfile.close();
	 //return to main
	main();
}

//this function will list out the courses taken
void ListCourse()
{
	//open the file
	ifstream ifile("AddCourse.txt");
	string CoursePrefix;              //course type like CSC, MTH
	int courseNum, creditHours;        
	string CourseTitle;

	//set condition
	while (ifile >> CoursePrefix >> courseNum >> CourseTitle >> creditHours)
	{
		//output the result
		cout << CoursePrefix << " " << courseNum << " " << CourseTitle << " " << creditHours << endl;
	}

	main();
}

void ListGrade()
{
	//open the file

	ifstream ifile("addGrade.txt");
	string g;                //again g for the grades
	float GradeValue;

	//scan variables from the file
	while (ifile >> g >> GradeValue )
	{
		cout << g<< " " << GradeValue<< endl;
	}

	main();
}

//List out semesters and term
void ListSemester()
{
	ifstream ifile("AddSemesterCode.txt");
	//string m;
	string semesterCode;
	int year;
	string term;

	while (ifile >> semesterCode >> year >> term)
	{
		cout << semesterCode << " "<<year << " "<<term << endl;
	}
	main();
}

//list out name and numbers
void ListNameNumbers()
{
	ifstream ifile("AddName&Number.txt");
	//string s;
	string fname;
	string lname;
	string number;

	while (ifile >> fname >> lname >> number)
	{
		cout << fname << " " << lname << " " << number << endl;
	}
	main();
}

//finally printing the transcript

void PrintTranscript()
{
	
	string getContent;                //to get the lastname from the file
	string fname;                    //first name
	string lname;                    //last name
	string CoursePrefix;             //CSC,MTH 
	int CourseCode;                  //30500, 25500
	string grade;       
	string SemesterCode;  //F86,sp89
	int creditHour;
	string CourseTitle;              //Course title

	//declare temp variable to store data in order to compare with original text for ADDCOURSE
	string tempLast;             //will hold lastname into temp variablw
	string tempFirst;             //will hold firstname into temp variablw
	string tempPrefix;             //hold prefix
	int tempCourseCode;            //to hold the Course code
	string tempCourseTitle;        //To hold the title
	int tempCreditHours;           //to calculate the credit hour
	int Total_creditHours = 0;     //initialization
	int Total_GradeValue = 0;
	float GPA = 0;               //initialization to GPA
	
	//declare temp var to hold semester and year
	int year;          // 2020
	string tempSemCode;    //sp20
	string semester;     //like fall

	//declare temp var to hold grades and year
	string tempYear;
	int GradeVal;
	string tempGrade;
	

	//open the file AddTranscript
	
	ifstream ifile("AddTranscript.txt");
	//user will enter last and first name
	
	cin >> lname>>fname;
	//scanning all variables from the file after opening it
	ifile >> lname >> fname >> CoursePrefix >> CourseCode >> grade >> SemesterCode;

	//assigning  lastname to the string to set the condition
	lname = getContent;

	//using that assignamnet operation to match string last name

	if (lname == getContent)                //if matches
	{
		//open the add course file
		ifstream ifile("AddCourse.txt");     //open the file 

		//here scanning all varibles from course file
		while (ifile >> tempPrefix >> tempCourseCode >> tempCourseTitle >> tempCreditHours)
		{
			CoursePrefix = tempPrefix;                //store them into temporary var
			CourseCode = tempCourseCode;              //remember that course part is declared already above from transcript file
			CourseTitle = tempCourseTitle;
			creditHour = tempCreditHours;
		}
		//we will use that operation to match with each other
		if (CourseCode == tempCourseCode && CoursePrefix == tempPrefix)    //if matches
		{
			//open the file for semester
			ifstream ifile("AddSemesterCode.txt");
			//scanning the var
			while (ifile >> tempSemCode >> year >> semester)
			{
				//assign to temp var
				SemesterCode = tempSemCode;

				if (SemesterCode == tempSemCode)       //if matches

					//print the year and semester
					cout << "========= Semester:" << semester << " " << year << "===========" << endl;


				//open AddGrade file
				ifstream ifile("AddGrade.txt");
				//scan vars
				while (ifile >> tempGrade >> GradeVal)
				{
					//assigning grades to temp grade
					grade = tempGrade;

					if (grade == tempGrade)            //if matches


						//output the variabales
						cout << tempPrefix << tempCourseCode << " " << tempCourseTitle << " " << "(" << tempCreditHours << ")" << " " << tempGrade << endl;

					Total_creditHours += tempCreditHours;          //add up all credit hours
					Total_GradeValue += GradeVal;                  //add up gradevalues for generatng GPA
					GPA = Total_GradeValue / int(tempCreditHours);     //Total grade value/ credit hours to get GPA
					
				}

			}
			//add up all credit hours
			

			//output the result Total hours and GPA
			cout << "STUDENT HOURS COMPLETED :" << Total_creditHours << endl;
			cout << "STUDENT GPA :" << GPA << endl;
		}



	}
	//close the file
	ifile.close();

		system("PAUSE");
		//return to main
	main();
}

