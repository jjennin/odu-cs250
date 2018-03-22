#include "slot.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;
// default constructor
slot::slot()
{
    id = 0;
    date_id = 0;
    doctor_id = 0;
    available = false;
}

// reads in slotList from file
void slot::read(ifstream& in)
{
    in >> id
       >> date_id
       >> doctor_id;
    string av;
    in >> av;
    if(av == "available")
        available = true;
    else
        available = false;

}
// add new slot
void slot::add(int newID, doctorList doc, date_timeList dt)
{
    bool validTime=false;
    bool validDoctor=false;
    char av;
    cout << "Please enter the following:" << endl;
    cout << "Date ID: ";
    while(!validTime)
    {
        cin >> date_id;
        for(unsigned i = 0; i < dt.size(); i++)
        {
            if(date_id == dt[i].getID())
            {
                validTime = true;
            }
        }
        if(!validTime)
        {
            cout << "Invalid Date ID!" << endl;
            for(unsigned i = 0; i < dt.size(); i++)
            {
                cout << "ID: " << dt[i].getID() << " ";
                dt[i].display();
                cout << endl;
            }
            cout << "Please enter date ID: ";
        }
    }
    cout << "Doctor ID: ";
    while(!validDoctor)
    {
        cin >> doctor_id;
        for(unsigned i = 0; i < doc.size(); i++)
        {
            if(doctor_id == doc[i].getID())
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
    cout << "Available (y/n): ";
    cin >> av;
    if(av == 'y')
        av = true;
    else
        av=false;
    id = newID;
    display(dt);
    cout << "slot added!" << endl;
}
// update current slot
void slot::updateEntry(doctorList doc, date_timeList dt)
{
    int entry;
    char tempC;
    bool validDoctor = false;
    bool validTime = false;
    do
    {
        cout << string(43,'-') << endl;
        cout << "1. Date ID" << endl
             << "2. Doctor ID: " << endl
             << "3. Available: " << endl
             << "4. Go back" << endl;
        cout << "Please chose which entry to update: ";
        cin >> entry;
        switch(entry)
        {
        case 1:
            cout << "Enter new date id: ";
            while(!validTime)
            {
                cin >> date_id;
                for(unsigned i = 0; i < dt.size(); i++)
                {
                    if(date_id == dt[i].getID())
                    {
                        validTime = true;
                    }
                }
                if(!validTime)
                {
                    cout << "Invalid Date ID!" << endl;
                    for(unsigned i = 0; i < dt.size(); i++)
                    {
                        cout << "ID: " << dt[i].getID() << " ";
                        dt[i].display();
                        cout << endl;
                    }
                    cout << "Please enter date ID: ";
                }
            }
            break;
        case 2:
            cout << "Enter new doctor ID: ";
            while(!validDoctor)
            {
                cin >> doctor_id;
                for(unsigned i = 0; i < doc.size(); i++)
                {
                    if(doctor_id == doc[i].getID())
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
        case 3:
            cout << "Enter if available (Y/N): ";
            cin >> tempC;
            while(tempC != 'Y' && tempC != 'N')
            {
                cout << "Y/N only: ";
                cin >> tempC;
            }
            if(tempC == 'Y')
            {
                available = true;
            }
            else
            {
                available = false;
            }
            break;
        case 4:
            break;
        }
    }
    while(entry != 4);


}
// accessor to run readin slotList from file part 1
void read (ifstream& in, slotList& sList)
{
    in.open("Slots.txt");
    if(!in)
    {
        cout << "Failed to open slots file" << endl;
    }
    else
    {
        sList.clear();
        int c;
        in >> c;
        for (int i = 0; i < c; i++)
        {
            slot s;
            s.read(in);
            sList.push_back(s);
        }
    }
}
// simple slot display
void slot::display(date_timeList dt)
{
    cout << " ID: " << id << "\t"
         << " Date ID: " << date_id << "\t";
    for(unsigned i = 0; i < dt.size(); i++)
    {
        if(date_id == dt[i].getID())
        {
            dt[i].display();
        }
    }
    cout << endl << " Doctor ID: " << doctor_id << "\t"
         <<"|| Available: ";
    if(available)
        cout << "YES ||";
    else
        cout << "NO ||";
    cout << endl << endl;

}
// add slot part 1
void addEntry(slotList& slo, doctorList doc, date_timeList dt)
{
    int newID = slo[slo.size()-1].getID()+1;
    slot temp;
    temp.add(newID,doc,dt);
    slo.push_back(temp);
}
// display ALL slots
void showAllEntries(slotList slot, int a, date_timeList dt)
{
    int temp = 0;
    for(unsigned i = 0; i < slot.size(); i++)
    {
        switch(a)
        {
        case 2:
            slot[i].display(dt);
            temp++;
            break;
        case 1:
            if(slot[i].getAvailable() == true)
            {
                slot[i].display(dt);
                temp++;
            }
            break;
        case 0:
            if(slot[i].getAvailable() == false)
            {
                slot[i].display(dt);
                temp++;
            }
            break;
        }
    }
    if(temp == 0)
    {
        cout << "No results found!" << endl;
    }
}
// display ALL slots by doctor
void showAllEntries(slotList slot, int a, int doctorID, date_timeList dt)
{
    int temp = 0;
    for(unsigned i = 0; i < slot.size(); i++)
    {
        if(doctorID == slot[i].getDoctorID())
        {
            switch(a)
            {
            case 2:
                slot[i].display(dt);
                temp++;
                break;
            case 1:
                if(slot[i].getAvailable() == true)
                {
                    slot[i].display(dt);
                    temp++;
                }
                break;
            case 0:
                if(slot[i].getAvailable() == false)
                {
                    slot[i].display(dt);
                    temp++;
                }
                break;
            }
        }
    }
    if(temp == 0)
    {
        cout << "No results found!" << endl;
    }
}
// search all slots
int searchEntries(slotList slot,string thing,date_timeList dt)
{
    int choice = 0;
    int id = 0;
    cout << "Slots" << endl;
    cout << "1. Enter Slot ID to " << thing << "." << endl;
    cout << "2. Show all available slots to " << thing << "." << endl;
    cout << "3. Abort." << endl;

    cin >> choice;
    switch(choice)
    {
    case 1:
        cout << "Please enter ID of slot to " << thing << ": ";
        cin >> id;
        for(unsigned i = 0; i < slot.size(); i++)
        {
            if(choice == slot[i].getID())
            {
                return i;
            }
        }
        cout << "No results found" << endl;
        break;
    case 2:
        showAllEntries(slot,1,dt);
        break;
    case 3:
        break;
    }
    return -1;

}
// search all slots using doctor
int searchEntries(slotList slot,string thing, int doctorID,date_timeList dt)
{
    int choice = 0;
    int id = 0;
    cout << "Slots" << endl;
    cout << "1. Enter Slot ID to " << thing << "." << endl;
    cout << "2. Show all available slots to " << thing << "." << endl;
    cout << "3. Abort." << endl;

    cin >> choice;
    switch(choice)
    {
    case 1:
        cout << "Please enter ID of slot to " << thing << ": ";
        cin >> id;
        for(unsigned i = 0; i < slot.size(); i++)
        {
            if(id == slot[i].getID() && doctorID == slot[i].getDoctorID())
            {
                return i;
            }
        }
        cout << "No results found" << endl;
        break;
    case 2:
        showAllEntries(slot,1,doctorID,dt);
        break;
    case 3:
        break;
    }
    return -1;

}
// delete slot
void deleteEntry(slotList& slot,date_timeList dt)
{
    char yn = 'Z';
    int loc = -1;
    loc = searchEntries(slot,"delete",dt);
    if(loc != -1)
    {
        cout << "-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-" << endl;
        do
        {
            cout << "Are you sure you want to delete " << slot[loc].getID() << "? (y/n): ";
            cin >> yn;
            if(yn == 'y')
            {
                slot.erase(slot.begin()+loc);
                cout << "Slot Deleted." << endl;
            }
            else if(yn == 'n')
            {
                cout << "Canceled deletion of slot." << endl;
            }

        }
        while(yn!='y'&&yn!='n');
        cout << "-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-" << endl;
    }
}
