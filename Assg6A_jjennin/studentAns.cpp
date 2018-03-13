#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "studentAns.h"
#include "randomGenerator.h"


using namespace std;

/// Generates student answers, depending on the input of beginning letter and max options.
string genStudentAns(int answersAmt, char beginLetter, int maxOptions) {
    char tempStudentAns[answersAmt]; // Array for temporary student answers <-- Deletes on line 24
    string fullAns = ""; // sets the full answer to empty so it can add itself to the new statement
    int minASCII = beginLetter; // Conversion to ASCII
    int maxASCII = minASCII + maxOptions - 1; // Conversion to ASCII and raises by 1
    randomNumbers(answersAmt,tempStudentAns,minASCII,maxASCII); // generates letters between minASCII and maxSCII for the maxItems
    for(int i = 0; i < answersAmt; i++){
        fullAns = fullAns + tempStudentAns[i]; // Combines the whole tempStudentAns char array into a string
    }
   // delete [] tempStudentAns; // delete the temporary array created on line 16
    return fullAns;
}
/// This function takes the input and replaces random chars in the input as spaces, according to the percentage provided (0%-maxPercent%).
string percentBlank(string input, float maxPercent, int maxAnswers){
    int randLoc = 0;
    int newMaxPercent = (int)(maxPercent+0.5)*100; // Converts max percent to whole number, as rand doesnt like floats/doubles
    int percent = (rand() % newMaxPercent + 0); // Creates random number
    double blankAmountD = (((double)percent)/10)+0.5; // Allows for decimal percentages, as rand doesnt like floats/doubles
    int blankAmount = (int)blankAmountD; // Converts blankAmt Double back into an int, as for loop doesn't like it.
    for(int i = 0; i < blankAmount; i++){
        randLoc = rand()%maxAnswers; // choses random location
        input[randLoc] = ' '; // replaces random location with space
    }
    return input;

}
