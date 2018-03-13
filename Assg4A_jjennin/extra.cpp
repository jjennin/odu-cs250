#include "extra.h"
#include<fstream>
#include <iostream>
#include <iomanip>
using namespace std;


/// PRINTS A HORIZONAL LINE
void printHorizontalLine( int width, char border_char){
    cout.fill( border_char );
    cout << setw( width ) << border_char << "\n";
    cout.fill(' ');
}
/// PRINTS AN EASY HEADER
void printHeading( string title, int width ){
    //Declare Variables
    int magic_width = 0;

    magic_width =  (width/2) - (title.length()/2) + title.length();

    cout << "\n";
    cout << left  << setfill('=') << setw( width ) << "=" << "\n";
    cout << right << setfill(' ') << setw( magic_width ) << title << "\n";
    cout << right << setfill('=') << setw( width ) << "=" << endl;

    //reset count
    cout.clear();
    cout.fill(' ');

    //VOID functions do NOT return a value
}
