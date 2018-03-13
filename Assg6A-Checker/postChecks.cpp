#include <iostream>
#include <fstream>

using namespace std;

struct studentStruct {
    string classname;
    int studentID;
    string lastName;
    string firstName;
    string answers;
    char letterGrade;
    int numberOfCorrectAnswers = 0;
    int numberOfFalseAnswers = 0;
    int numberOfBlanks = 0;
    double totalPoints = 0;
};

int main()
{
    int numOfStudents = 5000;
    studentStruct * student = new studentStruct[numOfStudents];
    ifstream inFile;
    char garbage;
    int matchingID=0,matchingLL=0,matchingFF=0,matchingFL=0,matchingLF=0,matchingAS=0;

    inFile.open("studentsAnswer.txt");
        if(!inFile){
            cout << "Failed to open Student Answers, is it there?";
            return 0;
        }
    for(int i = 0; i < numOfStudents; i++){
            getline(inFile, student[i].classname, ',');
                inFile >> noskipws >> garbage;
                inFile >> noskipws >> student[i].studentID >> garbage >> garbage;
            getline(inFile, student[i].lastName, ',');
                inFile >> noskipws >> garbage;
            getline(inFile, student[i].firstName, ',');
                inFile >> noskipws >> garbage;
            getline(inFile, student[i].answers);

    }

    int uniqueitems;
    for(int i = 0; i <  numOfStudents; i++){
        for(int j = 0; j < numOfStudents; j++){
            if(student[i].studentID == student[j].studentID && i != j){
                matchingID++;
            }
            else uniqueitems++;
            if(student[i].lastName == student[j].lastName && i != j){
                matchingLL++;
            }
            else uniqueitems++;
            if(student[i].firstName == student[j].firstName && i != j){
                matchingFF++;
            }
            else uniqueitems++;
            if(student[i].firstName == student[j].lastName && i != j){
                matchingFL++;
            }
            else uniqueitems++;
            if(student[i].lastName == student[j].firstName && i != j){
                matchingLF++;
            }
            else uniqueitems++;
            if(student[i].answers == student[j].answers && i != j){
                matchingAS++;
            }
            else uniqueitems++;
        }
    }
    cout << "matchingID: " << matchingID << endl;
    cout << "matchingLL: " << matchingLL << endl;
    cout << "matchingFF: " << matchingFF << endl;
    cout << "matchingLF: " << matchingLF << endl;
    cout << "matchingFL: " << matchingFL << endl;
    cout << "matchingAS: " << matchingAS << endl;
    cout << "unique: " << uniqueitems;
}
