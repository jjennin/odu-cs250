#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "randomGenerator.h"

using namespace std;


/// Generates a set of random numbers depending on the supplied maxitems, the min and max number to generate from.
/// ** This is used for basically the whole program.
void randomNumbers(int maxItems, char nums[100], int minNum, int maxNum) {
    for(int i = 0; i < maxItems; i++){
        nums[i]=rand()%(maxNum-minNum+1)+minNum;
    }
}
/// Generates random name, 5-10 characters
string randomName(){

    int nameLength = rand()%5+5;
    string name = "";
    int Z = (char)'Z'; // converts ASCII Z to int
    int A = (char)'A'; // converts ASCII A to int
    char charName[nameLength]; // creates char array
    randomNumbers(nameLength,charName,A,Z); // uses randomNumbers function to generate random numbers
                                            // The array provided is a char array, which means any number generated is turned into ASCII
    for(int i = 0; i < nameLength; i++){
        name = name + charName[i];
    }
//    delete [] charName; // deletes temporary charName array
    return name;

}
/// Generates a random ID between 10000-99999, all IDS are unique
int randomID(int ids[], int place){
random: // Needed to loop a new random to ensure it does not match ANY of the IDs
    int random = rand()%90000+10000;
    for(int i = 0; i < place; i++){ // this loop checks all created ids, and if any match the new, regenerate
        if(ids[i] == random){
                goto random; // Goes to line 56, repeats check
        }
    }
    ids[place] = random; // updates location of array with new value
    return random;
}
