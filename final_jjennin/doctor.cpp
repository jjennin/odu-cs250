#include "doctor.h"
#include <string>
#include <fstream>
#include <iostream>
#include "checkvalid.h"

using namespace std;

// default constructor
doctor::doctor()
{
    id = 0;
    username = "Unnamed";
    password = "Undefined";
    name = "Unnamed";
    phone = "Undefined";
    skill = "None";
}


// reads in slotList from file step-2
void doctor::read(ifstream& in)
{
///INFILE
    in >> id
       >> username
       >> password
       >> name
       >> phone
       >> skill;

}
// add new doctor step-2
void doctor::add()
{
    cout << "Please enter the following:" << endl;
    cout << "Name: ";
    cin >> name;
    cout << "Skill: ";
    cin >> skill;
    cout << "Phone: ";
    cin >> phone;
    checkPhone(phone);
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    cout << name << " added!" << endl;
}

// accessor to run readin slotList from file step-1
void read (ifstream& in, doctorList& docList)
{
    in.open("Doctors.txt");
    if(!in)
    {
        cout << "Failed to open doctor file" << endl;
    }
    else
    {
        docList.clear();
        int c;
        in >> c;
        for (int i = 0; i < c; i++)
        {
            doctor d;
            d.read(in);
            docList.push_back(d);
        }
    }
}
// basic doctor display
void doctor::display()
{
    cout << string(43,'=') << endl;
    cout << " ID: " << id << endl
         << " User: " << username << endl
         << " Pass: " << password << endl
         << " Name: " << name << endl
         << " Phone: " << phone << endl
         << " Skill: " << skill << endl;
    cout << string(43,'=') << endl;

}
// delete a doctor
void deleteEntry(doctorList& doc, int loc)
{
    char yn = 'A';
    cout << "-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-" << endl;
    do
    {
        cout << "Are you sure you want to delete " << doc[loc].getID() << " " << doc[loc].getName() << "? (y/n): ";
        cin >> yn;
        if(yn == 'y')
        {
            doc.erase(doc.begin()+loc);
            cout << "Doctor Deleted." << endl;
        }
        else if(yn == 'n')
        {
            cout << "Canceled deletion of doctor." << endl;
        }

    }
    while(yn!='y'&&yn!='n');
    cout << "-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-" << endl;
}
// step 1 of adding doctor
void addEntry(doctorList& doc)
{
    int largest = 0;
    for(unsigned i = 0; i < doc.size(); i++)
    {
        if(doc[i].getID() > largest)
        {
            largest = doc[i].getID();
        }
    }
    doctor temp;
    temp.add();
    temp.setID(largest + 1);
    doc.push_back(temp);
}
// show ALL doctors
void showAllEntries(doctorList& doc)
{
    for(unsigned i = 0; i < doc.size(); i++)
    {
        doc[i].display();
    }
}
// update a doctor information
void doctor::updateEntry()
{
    int entry;
    string tempS;
    do
    {
        cout << string(43,'-') << endl;
        cout << "1. Name" << endl
             << "2. Phone" << endl
             << "3. Skill" << endl
             << "4. Username" << endl
             << "5. Password" << endl
             << "6. Cancel" << endl;
        cout << "Please chose which entry to update: ";
        cin >> entry;
        switch(entry)
        {
        case 1:
            cout << "Enter new name: ";
            cin >> name;
            break;
        case 2:
            cout << "Enter new phone: ";
            cin >> tempS;
            checkPhone(tempS);
            phone = tempS;
            break;
        case 3:
            cout << "Enter new skill: ";
            cin >> skill;
            break;
        case 4:
            cout << "Enter new username: ";
            cin >> username;
            break;
        case 5:
            cout << "Enter new password: ";
            cin >> password;
            break;
        case 6:
            break;
        }
    }
    while(entry != 6);


}
// search for a certain doctor
int searchEntries(doctorList doc, string thing)
{
    int num = 0;
    string word = "";
    int choice = 0;
    do
    {
        cout << string(43,'-') << endl;
        cout << "Search by: " << endl
             << "1. ID" << endl
             << "2. Name" << endl
             << "3. Show all" << endl
             << "4. Abort" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cout << string(3,'-') << endl;
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
            showAllEntries(doc);
            break;
        case 4:
            break;
        }
    }
    while((choice < 1 || choice > 3) && choice != 4);
    for(unsigned i = 0; i < doc.size(); i++)
    {
        switch(choice)
        {
        case 1:
            if(doc[i].getID() == num)
                return i;
            break;
        case 2:
            if(doc[i].getName() == word)
                return i;
            break;
        }
    }
    if(choice != 4 && choice != 3)
        cout << "No results found" << endl;
    return -1;
}
