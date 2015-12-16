//************************************************************
// Jay Rosen
// SUPER SCANTRON READER reads a student's multiple choice exam, compares it the teacher's answer key, and calculates the grade for the student
//************************************************************

#include <iostream>
#include <fstream>
using namespace std;

const int Test_Size = 20;																			//Global Constant, The test is 20 questions long.
char AnswerKey[Test_Size], StudentTest[Test_Size];													//Global Character Array to hold answers for AnswerKey and StudentTest
ifstream CorrectAnswers, StudentAnswers;															//Global Inputfile for for CorrectAnswer and StudentAnswers

void displayWelcome();																				//Prototype function for displaying the welcome message
void getAnswerKey(char[]);																			//Prototype function for getting AnswerKey with character array 
void getStudentTest(char[]);																		//Prototype function for getting StudentTest with character array
void calculateGrade();																				//Prototype function for calculating grade of student's exam

int main()																							//Main function header
{
	displayWelcome();																				//Call function to display welcome message
	getAnswerKey(AnswerKey);																		//Call function to get AnswerKey
	getStudentTest(StudentTest);																	//Call function to get StudentTest
	calculateGrade();																				//Call function to calculate grade


	system("pause");
	return 0;
}																									//End of Main function

void displayWelcome()																				//Display Welcome function header
{
	cout << "\n\t\t********************************" << endl;										//Introduce the Super Scantron Reader
	cout << "\t\tWELCOME TO SUPER SCANTRON READER " << endl;
	cout << "\t\t********************************" << endl;
	cout << "\n\tInsert \"CorrectAnswers.txt\" into Slot 1." << endl;								//Locate external files
	cout << "\tInsert \"StudentAnswers.txt\" into Slot 2." << endl;
	cout << "\n\t\tPress <ENTER> to grade exam." << endl;

	cin.get();																						//Wait for input to continue
}																									//End of display Welcome function

void getAnswerKey(char AnswerKey[])																	//getAnswerKey function header
{
	CorrectAnswers.open("CorrectAnswers.txt");														//Open external file

	for (int i = 0; i < Test_Size; i++)																//Set counter to 20
		CorrectAnswers >> AnswerKey[i];																//Create Array for AnswerKey from file, reading line by line

	CorrectAnswers.close();																			//Close external file
}																									//End of getAnswerKey function


void getStudentTest(char StudentTest[])																//getStudentTest function header
{
	StudentAnswers.open("StudentAnswers.txt");														//Open external file

	for (int i = 0; i < Test_Size; i++)																//Set counter to 20
		StudentAnswers >> StudentTest[i];															//Create Array for StudentTest from file, reading line by line

	StudentAnswers.close();																			//Close external file
}																									//End of getStudentTest function

void calculateGrade()																				//calculate Grade function header
{
	cout << "\n\tIncorrect answers: \t Corrected answers:\n";										//Display chart for Incorrect and correct answers
	cout << "\t-------------------\t ------------------\n\t";

	int Correct = 0;																				//Initalize Correct and Incorrect to 0
	int Incorrect = 0;


	for (int i = 0; i < Test_Size; i++)																//Set count to 20
	{

		if (AnswerKey[i] == StudentTest[i])															//Compare AnswerKey to StudentTest
			Correct++;																				//If both characters match, add a counter to Correct
		else
		{																							//IF both characters do not match, add a counter to Incorrect
			Incorrect++;
			cout << (i + 1) << ". " << StudentTest[i] << " \t\t\t " << (i + 1) << ". " << AnswerKey[i] << "\n\t";
		}																							//Display incorrect answer with correct answer across from it in chart
	}

	cout << "\n\n\tTotal incorrect: " << Incorrect << endl;											//Display total number of incorrect answers

	double Grade = Correct / 20.0;																	//Calculate Crade as number of correct answers divided by number of questions
	double Percent = Grade * 100.0;																	//Multiple Grade by 100 to get a percent

	cout << "\n\tThis student answered " << Percent << "% correctly, and ";							//Display grade percent

	if (Percent >= 70.0)

		cout << "passed the exam.\n\n\t";															//Determine if the grade is passing or failing 

	if (Percent < 70.0)

		cout << "failed the exam.\n\n\t";
}																									//End of CalculateGrade Function