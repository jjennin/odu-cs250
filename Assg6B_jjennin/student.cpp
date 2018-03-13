#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "grade.h"
#include "student.h"

using namespace std;

/// Student input file loaded in
int studentFileInput(studentStruct * s, int counter, string filename){
    ifstream inFile;
    /// OPENS IN AND OUT FILES, CHECKS IF IT OPENS
    inFile.open(filename.c_str());
        if(!inFile){
            cout << endl << "Failed to open Student Answers, is it there?";
            return 0;
        }
    char garbage;
    /// Inputs the file created in part A
    for(int i = 0; i < counter; i++){
            getline(inFile, s[i].classname, ',');
                inFile >> noskipws >> garbage;
                inFile >> noskipws >> s[i].studentID >> garbage >> garbage;
            getline(inFile, s[i].lastName, ',');
                inFile >> noskipws >> garbage;
            getline(inFile, s[i].firstName, ',');
                inFile >> noskipws >> garbage;
            getline(inFile, s[i].answers);
    }
    inFile.close();
}

/// Student stats after grading is output to a file
int studentStatsOutput(studentStruct * s, int counter, char * answer, int questions, string gradeMode, string filename){
    int totalGrades[5] = {0,0,0,0,0}; // total grades, ABCD
    ofstream outFile;
    outFile.open(filename.c_str());
        if(!outFile){
            cout << "Failed to write new output file, is it protected?";
            return 0;
        }
    /// Outputs all the generated input into a file
    outFile << "COURSE, STUDENT-ID, LASTNAME, FIRSTNAME, ANSWERS, LETTER-GRADE, CORRECT-COUNT, INCORRECT-COUNT, BLANK-COUNT, TOTAL-POINTS" << endl;
    for(int j = 0; j < counter; j++){
        grader(questions, s, answer, j);
        s[j].letterGrade = letterGrade(s[j].totalPoints,gradeMode,totalGrades); // outputs letter grade
        /// outputs all the information to file
        outFile << s[j].classname << ", " << s[j].studentID << ", " << s[j].lastName << ", " << s[j].firstName << ", " << s[j].answers
        << ", " << s[j].letterGrade << ", " << s[j].numberOfCorrectAnswers << ", " << s[j].numberOfFalseAnswers
        << ", " << s[j].numberOfBlanks << ", " << s[j].totalPoints << endl;
    }
    /// more output to file
    outFile << endl << "Number students attended the exam: " << counter << endl
    << "Number students received A: " << totalGrades[0] << endl
    << "Number students received B: " << totalGrades[1] << endl
    << "Number students received C: " << totalGrades[2] << endl
    << "Number students received D: " << totalGrades[3] << endl
    << "Number students received F: " << totalGrades[4] << endl;
    outFile.close();
}
