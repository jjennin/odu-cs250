#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

/// Struct for the students, used in an array later
class studentStruct {
    public:
        std::string classname;
        int studentID;
        std::string lastName;
        std::string firstName;
        std::string answers;
        char letterGrade;
        int numberOfCorrectAnswers;
        int numberOfFalseAnswers;
        int numberOfBlanks;
        double totalPoints;
};


/// Student input file loaded in
int studentFileInput(studentStruct * s, int counter, std::string filename);
/// Student stats after grading is output to a file
int studentStatsOutput(studentStruct * s, int counter, char * answer, int questions, std::string gradeMode, std::string filename);

#endif // STUDENT_H_INCLUDED
