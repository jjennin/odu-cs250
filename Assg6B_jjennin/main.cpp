#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "grade.h"
#include "student.h"

using namespace std;
/*
* Jason Jennings
* Assignment 6 Part B
* CS 250
* 10/23/17
* Generates organizes information from studentAnswers.txt and gets analytics of file. Resulting in the total of each Letter grade.
*/

int main(){

    int numQuestions = 100, numOfStudents = 5000;
    string gradeMode; // stores the gradeMode
    char answer[numQuestions]; // stores the answer key
    studentStruct * student = new studentStruct[numOfStudents]; // creates the student struct array
    student->numberOfCorrectAnswers = 0;
    student->numberOfFalseAnswers = 0;
    student->numberOfBlanks = 0;
    student->totalPoints = 0;

    answerKey(answer, numQuestions, gradeMode, "answerKey.txt");
    studentFileInput(student, numOfStudents, "studentsAnswer.txt");
    studentStatsOutput(student, numOfStudents, answer, numQuestions, gradeMode, "results.txt");

    return 0;
}
