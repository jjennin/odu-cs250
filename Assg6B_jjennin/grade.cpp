#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "grade.h"
#include "student.h"

using namespace std;


/// answer key is loaded in
int answerKey(char * answer, int counter, string& gradeMode, string filename){
    /// OPENS IN AND OUT FILES, CHECKS IF IT OPENS
    ifstream inFile;
    inFile.open(filename.c_str());
        if(!inFile){
            cout << endl << "Failed to open Student Answers, is it there?";
            return 0;
        }
        for(int i = 0; i < counter; i++){
            inFile >> answer[i];
            cout << answer[i];
        }
        inFile >> gradeMode;
        cout << endl << gradeMode;
    inFile.close();
}

/// grades the student answers based on the answer key
void grader(int numQuestions, studentStruct * student, char answer[], int j){
    int maxScore = 100, blankPoints = -2, blankMaxPoints = 5, correctPoints = 2, incorrectPoints = -1, baseScore = 70;
        for(int k = 0; k < numQuestions; k++){
            if(answer[k]==student[j].answers[k]){
                student[j].numberOfCorrectAnswers++;
            }
            else if(student[j].answers[k]==' '){
                student[j].numberOfBlanks++;
            }
            else {
                student[j].numberOfFalseAnswers++;
            }
        }
        /// calculates total points
        student[j].totalPoints = (student[j].numberOfCorrectAnswers*correctPoints)+(student[j].numberOfFalseAnswers*incorrectPoints);
        /// totalpoints = correctAns * points (2) + falseAns * points (0)
        if(student[j].numberOfBlanks > blankMaxPoints){ // checks if max blank points reached
            student[j].totalPoints = student[j].totalPoints + blankPoints; // apply deduction if exceed
        }
        student[j].totalPoints = (((student[j].totalPoints+baseScore)/numQuestions)*100); // calculates score in a whole number.
}
/// gives a letter grade from the grademode and total
char letterGrade(double total, string gradeMode, int totalGrades[]){
    char grade;
    if(gradeMode == "easy"){
        if(total >= 85) grade = 'A';
        else if(total >= 75) grade = 'B';
        else if(total >= 65) grade = 'C';
        else if(total >= 55) grade = 'D';
        else grade = 'F';
    }
    else if(gradeMode == "medium"){
        if(total >= 90) grade = 'A';
        else if(total >= 80) grade = 'B';
        else if(total >= 70) grade = 'C';
        else if(total >= 60) grade = 'D';
        else grade = 'F';
    }
    else if(gradeMode == "hard"){
        if(total >= 95) grade = 'A';
        else if(total >= 85) grade = 'B';
        else if(total >= 75) grade = 'C';
        else if(total >= 65) grade = 'D';
        else grade = 'F';
    }
    else grade = 'Z';

   switch(grade){
    case 'A':
        totalGrades[0]++;
        break;
    case 'B':
        totalGrades[1]++;
        break;
    case 'C':
        totalGrades[2]++;
        break;
    case 'D':
        totalGrades[3]++;
        break;
    case 'F':
        totalGrades[4]++;
        break;
    }
    return grade;

}
