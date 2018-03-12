#include "date_time.h"
#include "checkvalid.h"
#include <string>
#include <fstream>
#include <iostream>
#include "patient.h"

using namespace std;

// default constructor
patient::patient()
{
    id = 0;
    doctor_id = 0;
    record_id = 0;
    name = "Unnamed";
    phone = "Undefined";
    gender = 'Z';
    email = "Undefined";
    blood_type = "Undefined";
}


// reads in managerList from file part2
void patient::read(ifstream& in)
{
    in >> id
       >> doctor_id
       >> record_id
       >> name
       >> phone
       >> gender
       >> email
       >> blood_type;
}
// add patient part 2
void patient::add(doctorList doc)
{
    int loc = -1;;
    cout << string(43,'-') << endl;
    cout << "Please enter the following:" << endl
         << "Doctor ID: " << endl;
    while(loc == -1)
    {
        loc = searchEntries(doc, "search");
        if(loc != -1)
        {
            doctor_id = doc[loc].Getid();
            cout << "Assigned doctor ID to patient" << endl;
        }
    }
    cout << "Name: ";
    cin >> name;
    cout << "Phone: ";
    cin >> phone;
    checkPhone(phone);
    cout << "Gender: ";
    cin >> gender;
    while(gender != 'M' && gender != 'F')
    {
        cout << "Please enter a proper gender (M/F): ";
        cin >> gender;
    }
    gender = toupper(gender);
    cout << "Email: ";
    cin >> email;
    checkEmail(email);
    cout << "Blood Type: ";
    cin >> blood_type;
    checkBloodType(blood_type);
    cout << name << " added!" << endl;
}

// accessor to run readin managerList from file part 1
void read (ifstream& in, patientList& pList)
{
    in.open("Patients.txt");
    if(!in)
    {
        cout << "Failed to open patient file" << endl;
    }
    else
    {
        pList.clear();
        int c;
        in >> c;
        for (int i = 0; i < c; i++)
        {
            patient p;
            p.read(in);
            pList.push_back(p);
        }
    }
}
// simple display for patients
void patient::display(doctorList doc)
{
    string docName;
    for(unsigned i = 0; i < doc.size(); i++)
    {
        if(doc[i].Getid() == doctor_id)
        {
            docName = doc[i].Getname();
        }
    }
    cout << string(43,'=') << endl;
    cout << " Patient ID: " << id << endl
         << " Doctor: " << docName << " (ID:" << doctor_id << ")" << endl
         << " Record ID: " << record_id << endl
         << " Name: " << name << endl
         << " Gender: " << gender << endl
         << " Phone: " << phone << endl
         << " Email: " << email << endl
         << " Blood: " << blood_type << endl;
    cout << string(43,'=') << endl;
}
// delete patient
void deleteEntry(patientList& pat,doctorList doc)
{
    char yn = 'Z';
    int loc = -1;
    loc = searchEntries(pat,"delete",doc);
    if(loc != -1)
    {
        cout << "-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-" << endl;
        do
        {
            cout << "Are you sure you want to delete " << pat[loc].Getid() << " " << pat[loc].Getname() << "? (y/n): ";
            cin >> yn;
            if(yn == 'y')
            {
                pat.erase(pat.begin()+loc);
                cout << "Patient Deleted." << endl;
            }
            else if(yn == 'n')
            {
                cout << "Canceled deletion of patient." << endl;
            }

        }
        while(yn!='y'&&yn!='n');
        cout << "-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-" << endl;
    }
    else
    {
        cout << "No results found . . . " << endl;
    }
}
// add patient - part 1
void addEntry(patientList& pat, doctorList doc)
{
    int largest = 0;
    for(unsigned i = 0; i < pat.size(); i++)
    {
        if(pat[i].Getid() > largest)
        {
            largest = pat[i].Getid();
        }
    }
    patient temp;
    temp.add(doc);
    temp.Setid(largest +1);
    pat.push_back(temp);
}
// display ALL patients
void showAllEntries(patientList& pat, doctorList doc)
{
    for(unsigned i = 0; i < pat.size(); i++)
    {
        pat[i].display(doc);
    }
}
// easy update of patient variables
void patient::updateEntry(doctorList doc)
{
    int entry;
    string tempS;
    char tempC;
    bool validDoctor = false;
    do
    {
        cout << string(43,'-') << endl;
        cout << "1. Name" << endl
             << "2. Phone" << endl
             << "3. Gender" << endl
             << "4. Email" << endl
             << "5. Blood Type" << endl
             << "6. Doctor ID: " << endl
             << "7. Go back" << endl;
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
            cout << "Enter new gender: ";
            cin >> tempC;
            checkGender(tempC);
            gender = tempC;
            break;
        case 4:
            cout << "Enter new email: ";
            cin >> tempS;
            checkEmail(tempS);
            email = tempS;
            break;
        case 5:
            cout << "Enter new blood type: ";
            cin >> tempS;
            checkBloodType(tempS);
            blood_type = tempS;
            break;
        case 6:
            cout << "Enter new doctor ID: ";
            while(!validDoctor)
            {
                cin >> doctor_id;
                for(unsigned i = 0; i < doc.size(); i++)
                {
                    if(doctor_id == doc[i].Getid())
                    {
                        validDoctor = true;
                    }
                }
                if(!validDoctor)
                {
                    cout << "Invalid doctor ID!" << endl;
                    cout << "Please enter doctor ID: ";
                }
            }
            break;
        case 7:
            break;
        }
    }
    while(entry != 7);


}
// search patients
int searchEntries(patientList pat,string thing,doctorList doc)
{
    int choice = 0;
    int num = 0;
    string word = "";
    do
    {
        cout << "Search by: " << endl
             << "1. ID" << endl
             << "2. Name" << endl
             << "3. Email" << endl
             << "4. Show all" << endl
             << "5. Abort" << endl;
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
            cout << "Enter email to " << thing << ": ";
            cin >> word;
            break;
        case 4:
            showAllEntries(pat,doc);
            break;
        case 5:
            break;
        }
    }
    while((choice < 1 || choice > 4) && choice != 5);
    for(unsigned i = 0; i < pat.size(); i++)
    {
        switch(choice)
        {
        case 1:
            if(pat[i].Getid() == num)
                return i;
            break;
        case 2:
            if(pat[i].Getname() == word)
                return i;
            break;
        case 3:
            if(pat[i].Getemail() == word)
                return i;
            break;
        }
    }
    if(choice != 4 && choice !=5)
        cout << "No results found" << endl;
    return -1;
}

