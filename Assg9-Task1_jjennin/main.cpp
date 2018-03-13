#include <iostream>
#include <iomanip>
#include "fractiontype.h"

using namespace std;

int main()
{
    fractionType num1(5, 6);                        //Line 1
    fractionType num2;                              //Line 2
    fractionType num3;                              //Line 3

    cout << fixed;                                  //Line 4
    cout << showpoint;                              //Line 5
    cout << setprecision(2);                        //Line 6
    cout << "============================================" << endl;
    cout << " Assignment 9 - Task 1" << endl;
    cout << " by Jason Jennings" << endl;
    cout << "============================================" << endl << endl;
    cout << "Line 7: Num1 = " << num1 << endl;      //Line 7
    cout << "Line 8: Num2 = " << num2 << endl;      //Line 8

    cout << "Line 9: Enter the fraction "
		 << "in the form a / b:   ";                //Line 9
    cin >> num2;                                    //Line 10
    cout << endl;                                   //Line 11

    cout << "Line 12: New value of num2 = "
         << num2 << endl;	                        //Line 12

    num3 = num1 + num2;                             //Line 13

    cout << "Line 14: Num3 = " << num3 << endl;     //Line 14
    cout << "Line 15: " << num1 << " + " << num2
         << " = " << num1 + num2 << endl;           //Line 15
    cout << "Line 16: " << num1 << " * " << num2
         << " = " << num1 * num2 << endl;           //Line 16

    num3 = num1 - num2;                             //Line 17

    cout << "Line 18: Num3 = " << num3 << endl;     //Line 18
    cout << "Line 19: " << num1 << " - " << num2
         << " = " << num1 - num2 << endl;           //Line 19
    cout << "Line 20: (" << num1 << ") / (" << num2
         << ") = " << num1 / num2 << endl;          //Line 20
    cout << "Line 21: (" << num1 << ") <= (" << num2
         << ") = " << (num1 <= num2) << endl;         //Line 21
    cout << "Line 22: (" << num1 << ") == (" << num2
         << ") = " << (num1 == num2) << endl ;        //Line 22
    cout << "Line 23: (" << num1 << ") >= (" << num2
         << ") = " << (num1 >= num2) << endl ;        //Line 23
    cout << "Line 24: (" << num1 << ") != (" << num2
         << ") = " << (num1 != num2) << endl ;        //Line 24
    cout << "Line 25: (" << num1 << ") > (" << num2
         << ") = " << (num1 > num2) << endl;          //Line 25
    cout << "Line 26: (" << num1 << ") < (" << num2
         << ") = " << (num1 < num2) << endl;          //Line 26
	return 0;
}
