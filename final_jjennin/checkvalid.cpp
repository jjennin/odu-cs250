#include "checkvalid.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

// checks validity of email
void checkEmail(string& x)
{
    bool valid = false;
    while(!valid)
    {
        for(unsigned i = 0; i < x.length(); i++)
        {
            if(x[i] == '@')
                valid = true;
        }
        if(!valid)
        {
            cout << "Please enter a valid email! (includes @): ";
            cin >> x;
        }
    }
}
// checks validity of phone
void checkPhone(string& x)
{
    while(x.length() != 10)
    {
        if(x.length() < 10)
            cout << "Number too short! Try again: ";
        if(x.length() > 10)
            cout << "Number too long! Try again: ";
        cin >> x;
    }
}
// checks validity of phone
void checkGender(char& x)
{
    while(x != 'M' && x!= 'F')
    {
        cout << "Enter a valid gender (M/F): ";
        cin >> x;
    }
}
// checks validity of blood type
void checkBloodType(string &x)
{
    while(x != "A+" && x != "A-" && x != "B+" && x != "B-" && x != "O+" && x != "O-" && x != "AB" )
    {
        cout << "(A+,A-,B+,B-,O+,O-,AB)" << endl;
        cout << "Incorrect Blood Type: ";
        cin >> x;
    }
}
