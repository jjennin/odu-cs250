#ifndef GRADE_H_INCLUDED
#define GRADE_H_INCLUDED
#include "student.h"

/// answer key is loaded in
int answerKey(char * answer, int counter, std::string& gradeMode, std::string filename);
/// grades the student answers based on the answer key
void grader(int numQuestions, studentStruct * student, char * answer, int j);
/// gives a letter grade from the grademode and total
char letterGrade(double total, std::string gradeMode, int * totalGrades);

#endif // GRADE_H_INCLUDED
