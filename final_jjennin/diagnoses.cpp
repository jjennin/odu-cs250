#include "diagnoses.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;
// default constructor
diagnoses::diagnoses()
{
    id = 0;
    disease_name = "Undefined";
}

// reads in slotList from file
void diagnoses::read(ifstream& in, int i)
{
//INFILE
    char x;
    in >> noskipws >> x;
    getline(in, disease_name);
    id = i+1;

}

// accessor to run readin slotList from file
void read (ifstream& in, diagnosesList& dList)
{
    in.open("Diagnosis.txt");
    if(!in)
    {
        cout << "Failed to open diag file" << endl;
    }
    else
    {
        dList.clear();
        int c;
        in >> c;
        for (int i = 0; i < c; i++)
        {
            diagnoses d;
            d.read(in,i);
            dList.push_back(d);
        }
    }
}
// basic display for diagnosis
void diagnoses::display()
{
    cout << string(43,'=') << endl;
    cout << " Diagnoses ID: " << id << endl
         << " Disease Name: " << disease_name << endl;
    cout << string(43,'=') << endl;

}
// search diagnoses
int searchEntries(diagnosesList diag,string thing)
{
    int choice = 0;
    int num = 0;
    string word = "";
    do
    {
        cout << string(43,'-') << endl;
        cout << endl;
        cout << "Search by: " << endl
             << "1. ID" << endl
             << "2. Name" << endl
             << "3. List All" << endl
             << "4. Abort" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cout << "-" << endl;
        switch(choice)
        {
        case 1:
            cout << "Enter ID to " << thing << ": ";
            cin >> num;
            break;
        case 2:
            cout << "Enter name to " << thing << ": ";
            cin >> word;
            break;
        case 3:
            for(unsigned i = 0; i < diag.size(); i++)
            {
                diag[i].display();
            }
            break;
        case 4:
            cout << "Aborting search...";
            return -3;
            break;
        }
    }
    while(((choice < 1 || choice > 2) && (choice != 4)) || (choice == 3));
    for(unsigned i = 0; i < diag.size(); i++)
    {
        switch(choice)
        {
        case 1:
            if(diag[i].getID() == num)
                return i;
            break;
        case 2:
            if(diag[i].getDiseaseName() == word)
                return i;
            break;
        }
    }


    cout << "Not a valid choice" << endl;
    return -1;
}
