#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "randomGenerator.h"
#include "studentAns.h"

using namespace std;
/*
* Jason Jennings
* Assignment 6 Part A
* CS 250
* 10/23/17
* Generates random IDs, random answers (with empty spaces), and random names into a output file named studentAnswers.txt
*/


int main()
{
    int totalAnswersAmt = 100; // Easily changed
    int totalStudents = 5000; // Easily changed
    string tempStudentAns; // Student answers, temp string for loop
    string studentAns;
    string firstEntry; // stores the first entry as requested
    ifstream inFile;
    ofstream outFile;
    int studentIDs[totalStudents]; // stores all student ids, ensuring non-redundancy
    srand(time(0)); // seeds my randomness

    inFile.open("firstStudentAnswersEntry.txt"); /// Read in the single beginning entry as requested
    outFile.open("studentsAnswer.txt"); /// Creates new file named studentsAnswer.txt; excluding append to ensure new file.
    /// FIRST ENTRY
    getline(inFile, firstEntry);
    inFile.close(); // Close input file
    outFile << "CS-250, " << randomID(studentIDs,0) << ", " << randomName() << ", " << randomName() << ", " << firstEntry << endl;
    /// end FIRST ENTRY
    /// Next 4999 entries
    for(int j = 1; j < totalStudents; j++){
        // Generation of the answers
        // questionString questions 1-4, A,B,C
        tempStudentAns = genStudentAns(4, 'A', 3)
        // questions 5, T/F (A,B)     questions 6-14, A,B,C
        + genStudentAns(1, 'A', 2) + genStudentAns(9, 'A', 3)
        // questions 15, T/F (A,B)    questions 16-24, A,B,C
        + genStudentAns(1, 'A', 2) + genStudentAns(9, 'A', 3)
        // question 25, T/F (A,B)     question 26-100, A,B,C
        + genStudentAns(1, 'A', 2) + genStudentAns(75, 'A', 3);
        studentAns = percentBlank(tempStudentAns, 1.00, totalAnswersAmt);
        outFile << "CS-250, " << randomID(studentIDs,j) << ", " << randomName() << ", " << randomName() << ", " << studentAns << endl;

    }
    /// end 4999 entries
    cout << "Finished generating grades into file!" << endl;
    outFile.close(); // Close output file
    return 0;
}

