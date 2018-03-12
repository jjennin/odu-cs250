#include "menu.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;
// easy clear screen, used a lot.
void clearscr()
{
    for (int n = 0; n < 10; n++) std::cout << string(10,'\n');
}
/// MAIN MENU
void menu(patientList& pList, doctorList& docList, slotList& sList, date_timeList& dtList, recordList& rList, diagnosesList& dList, appointmentList& appList)
{
    int choice = 0;
    do
    {
        clearscr();
        cout << string(70,'-') << endl;
        cout << "Welcome to the Hospital Management System (H.M.S)" << endl;
        cout << "1. Manage Appointments" << endl
             << "2. Manage Slots" << endl
             << "3. Manage Doctors" << endl
             << "4. Manage Patients" << endl
             << "5. Manage Patients' Records" << endl
             << "6. Manage labs <--- Not active" << endl
             << "7. Exit HMS" << endl;
        cout << string(70,'-') << endl;

        cout << "Please choose an option: ";
        cin >> choice;
        switch(choice)
        {
        case 1: // Manage apps
            clearscr();
            menu(appList, pList, sList, rList, dList, docList, dtList);
            break;
        case 2: // Manage slots
            clearscr();
            menu(sList,dtList,docList);
            break;
        case 3: // Manage doctors
            clearscr();
            menu(docList,appList);
            break;
        case 4: // Manage patients
            clearscr();
            menu(pList,docList);
            break;
        case 5: // Manage records
            clearscr();
            menu(rList,dList,pList,docList);
            break;
        case 6: // Manage labs
            cout << "Feature not implemented yet.... Try again " << endl;
            break;
        case 7: // Exit program
            cout << "Exiting..." << endl;
            break;
        default: // Duh, invalid
            cout << "---> INVALID CHOICE <----" << endl;
            break;
        }
    }
    while(choice != 7); // continues til Exit key is pressed
}
/// OPTION ONE - Manage Appointments
void menu(appointmentList& app, patientList pat, slotList& slot, recordList& rec, diagnosesList diag, doctorList doc, date_timeList dt)
{
    int choice = 0;
    int loc = -1;


    do
    {
        cout << string(43,'-') << endl;
        cout << "1. Schedule a new appointment." << endl
             << "2. Show all appointments." << endl
             << "3. Show all appointments by doctor's name" << endl
             << "4. Show all appointments by patient's name" << endl
             << "5. Show all appointments between two times" << endl
             << "6. Modify/Reschedule an existing appointment." << endl
             << "7. Remove/Cancel an appointment." << endl
             << "8. Main menu." << endl;
        cout << string(43,'-') << endl;
        cout << "Please choose an option: ";
        cin >> choice;
        switch(choice)
        {
        case 1:
            add(app,pat,slot,rec,diag,doc,dt);
            cout << "Test";
            app[app.size()-1].display(doc,pat,diag,slot,dt);
            break;
        case 2:
            showAllEntries(app,doc,pat,diag,slot,dt);
            break;
        case 3:
            loc = searchEntries(doc,"search");
            if(loc != -1)
            {
                for(unsigned i = 0; i < app.size(); i++)
                {
                    if(app[i].Getdoctor_id() == doc[loc].Getid())
                    {
                        app[i].display(doc,pat,diag,slot,dt);
                    }
                }
            }
            break;
        case 4:
            loc = searchEntries(pat,"search",doc);
            if(loc != -1)
            {
                for(unsigned i = 0; i < app.size(); i++)
                {
                    if(app[i].Getpatient_id() == pat[loc].Getid())
                    {
                        app[i].display(doc,pat,diag,slot,dt);
                    }
                }
            }
            break;
        case 5:
            showBtwnTimesApps(app,pat,slot,rec,diag,doc,dt);
            break;
        case 6:
            loc = searchEntries(app, "update");
            if(loc != -1)
            {
                app[loc].updateEntry(pat,slot,rec,diag,doc,dt);
            }
            break;
        case 7:
            loc = searchEntries(app, "delete");
            if(loc != -1)
            {
                deleteEntry(app,slot);
            }
            break;
        case 8:
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    }
    while(choice != 8);
}
/// OPTION TWO - Manage slots
void menu(slotList& slot, date_timeList dt, doctorList doc)
{
    int loc = 0;
    int choice = 0;
    do
    {
        cout << string(43,'-') << endl;
        cout << "1. Show available slots" << endl
             << "2. Show unavailable slots" << endl
             << "3. Add new slot(s)" << endl
             << "4. Show slots between times" << endl
             << "5. Show all slots" << endl
             << "6. Show all slots for certain doctor" << endl
             << "7. Modify slot information" << endl
             << "8. Remove a slot" << endl
             << "9. Main menu" << endl;
        cout << string(43,'-') << endl;
        cout << "Please choose an option: ";
        cin >> choice;
        switch(choice)
        {
        case 1:
            showAllEntries(slot,1,dt);
            break;
        case 2:
            showAllEntries(slot,0,dt);
            break;
        case 3:
            addEntry(slot,doc,dt);
            break;
        case 4:
            showBtwnTimes(dt, slot);
            break;
        case 5:
            showAllEntries(slot,2,dt);
            break;
        case 6:
            searchAndDisplaySlotsByDoctor(slot,doc,dt);
            break;
        case 7:
            loc = searchEntries(slot, "update",dt);
            if(loc != -1)
            {
                slot[loc].updateEntry(doc,dt);
            }
            break;
        case 8:
            deleteEntry(slot,dt);
            break;
        case 9:
            break;
        default:
            cout << "invalid choice, try again: ";
        }
    }
    while(choice != 9);
}
/// OPTION THREE - Manage doctors
void menu(doctorList& doc, appointmentList app)
{
    int loc = 0;
    int choice = 0;
    bool denied = false;

    do
    {
        cout << string(43,'-') << endl;
        cout << "1. Show all doctors" << endl
             << "2. Update doctor info" << endl
             << "3. Add a doctor" << endl
             << "4. Delete a doctor" << endl
             << "5. Search for doctor" << endl
             << "6. Main menu." << endl;
        cout << string(43,'-') << endl;
        cout << "Please choose an option: ";
        cin >> choice;
        switch(choice)
        {
        case 1:
            showAllEntries(doc);
            break;
        case 2:
            loc = searchEntries(doc, "update");
            if(loc != -1)
            {
                doc[loc].updateEntry();
            }
            break;
        case 3:
            addEntry(doc);
            break;
        case 4:
            loc = searchEntries(doc,"delete");
            if(loc != -1)
            {
                for(unsigned i = 0; i < app.size(); i++)
                {
                    if(app[i].Getdoctor_id() == doc[loc].Getid())
                    {
                        denied = true;
                    }
                }
                if(!denied)
                {
                    deleteEntry(doc,loc);
                }
                else
                {
                    cout << string(20,'!') << endl;
                    cout << "Denied! Doctor has pending appointments. \nThis doctor cannot be deleted until all appointments are canceled." << endl;
                }
            }
            break;
        case 5:
            loc = searchEntries(doc, "search");
            if(loc != -1)
            {
                doc[loc].display();
            }
            break;
        case 6:
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    }
    while(choice != 6);
    cout << string(43,'-') << endl;
}
/// OPTION FOUR - Manage patients
void menu(patientList& pat, doctorList doc)
{
    int choice = 0;
    int loc = 0;
    do
    {
        cout << string(43,'-') << endl;
        cout << "Manage Patients: " << endl
             << "1. Add new patient" << endl
             << "2. Update patient info" << endl
             << "3. Delete a patient" << endl
             << "4. Show all patients" << endl
             << "5. Show all patients by doctor" << endl
             << "6. Search for patient" << endl
             << "7. Main menu." << endl;
        cout << string(43,'-') << endl;
        cout << "Please choose an option: ";
        cin >> choice;
        switch(choice)
        {
        case 1:
            addEntry(pat,doc);
            break;
        case 2:
            loc = searchEntries(pat, "update",doc);
            if(loc != -1)
            {
                pat[loc].updateEntry(doc);
            }
            break;
        case 3:
            deleteEntry(pat,doc);
            break;
        case 4:
            showAllEntries(pat,doc);
            break;
        case 5:
            searchAndDisplayPatientsByDoctor(pat,doc);
            break;
        case 6:
            loc = searchEntries(pat, "search",doc);
            if(loc != -1)
            {
                pat[loc].display(doc);
            }
            break;
        case 7:
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    }
    while(choice != 7);
    cout << string(43,'-') << endl;
}
/// OPTION FIVE - Manage records
void menu(recordList& rec, diagnosesList& diag, patientList pat, doctorList doc)
{
    int choice = 0, choice2 = 0;
    int loc = -1;
    int secLoc = -1;
    string recordUpdate = "";
    do
    {
        cout << string(43,'-') << endl;
        cout << "1. View patient records" << endl
             << "2. Update patient records" << endl
             << "3. Main menu." << endl;
        cout << string(43,'-') << endl;
        cout << "Please choose an option: ";
        cin >> choice;
        switch(choice)
        {
        case 1:
            loc = searchEntries(pat, "search",doc);
            if(loc != -1)
            {
                secLoc = searchEntries(rec, pat[loc].Getid());
                if(secLoc == -1)
                {
                    cout << "No existing records" << endl;
                }
                else
                {
                    cout << "Displaying current records for " << pat[loc].Getname() << ": " << endl;
                    rec[secLoc].display();
                    cout << endl;
                }
            }
            break;
        case 2:
            loc = searchEntries(pat, "search",doc);
            if(loc != -1)
            {
                secLoc = searchEntries(rec, pat[loc].Getid());
                if(secLoc == -1)
                {
                    add(rec,pat[loc].Getid(),pat[loc].Getrecord_id());
                    secLoc = rec.size()-1;
                }
                cout << endl;
                cout << "Displaying current records for " << pat[loc].Getname() << ": " << endl;
                rec[secLoc].display();
                do
                {
                    cout << "What do you want to update for patient " << pat[loc].Getname() << ": " << endl;
                    cout << "1. Notes" << endl
                         << "2. Diagnosis" << endl
                         << "3. Medication" << endl
                         << "4. Abort" << endl;
                    cin >> choice2;
                    switch(choice2)
                    {
                    case 1:
                        rec[secLoc].Setnotes();
                        break;
                    case 2:
                        rec[secLoc].Setdiagnoses_id(diag);
                        break;
                    case 3:
                        rec[secLoc].Setmeds();
                        break;
                    case 4:
                        break;
                    default:
                        cout << "Invalid choice" << endl;
                        break;
                    }

                }
                while(choice2 != 4);
            }
            break;
        case 3:
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }

    }
    while(choice != 3);
}


/// SEARCH FUNCTIONS
//searchAndDisplaySlotsByDoctor
void searchAndDisplaySlotsByDoctor(slotList slot, doctorList doc, date_timeList dt)
{
    int loc = 0;
    loc = searchEntries(doc,"doctor search");
    cout << string(43,'=') << endl;
    cout << "RESULTS:" << endl;
    for(unsigned k = 0; k < slot.size(); k++)
    {
        if(doc[loc].Getid() == slot[k].Getdoctor_id())
            slot[k].display(dt);
    }
    if(loc == -1)
    {
        cout << "Search aborted." << endl;
    }
    cout << string(43,'=') << endl;

}
//searchAndDisplayPatientsByDoctor
void searchAndDisplayPatientsByDoctor(patientList pat, doctorList doc)
{
    int loc = 0;
    loc = searchEntries(doc,"doctor search");
    cout << string(43,'=') << endl;
    cout << "RESULTS:" << endl;
    for(unsigned k = 0; k < pat.size(); k++)
    {
        if(doc[loc].Getid() == pat[k].Getdoctor_id())
            pat[k].display(doc);
    }
    if(loc == -1)
    {
        cout << "Search aborted." << endl;
    }
    cout << string(43,'=') << endl;

}

// Show slots between two times.
void showBtwnTimes(date_timeList dt, slotList slot)
{
    int dtH;
    Date_Time date1, date2;
    cout << "Enter two times to search between and find available slots." << endl;
    cout << "Beginning date: " << endl;
    date1.add();
    cout << "Ending date: " << endl;
    date2.add();

    if(date1.GetAM_PM() == 'P')
    {
        date1.Sethour(date1.Gethour() + 12);
    }
    if(date2.GetAM_PM() == 'P')
    {
        date2.Sethour(date2.Gethour() + 12);
    }
    long long entryDate;
    long long startDate = (((date1.Getyear()+2000) * 100000000LL) + (date1.Getmonth() * 1000000) + (date1.Getday()*10000))+((date1.Gethour()*100)+(date1.Getminute()));
    long long endDate = (((date2.Getyear()+2000) * 100000000LL) + (date2.Getmonth() * 1000000) + (date2.Getday()*10000))+((date2.Gethour()*100)+(date2.Getminute()));
    for(unsigned k = 0; k < dt.size(); k++)
    {
        dtH = dt[k].Gethour();
        if(dt[k].GetAM_PM() == 'P')
        {
            dtH += 12;
        }
        entryDate = (((dt[k].Getyear()+2000) * 100000000LL) + (dt[k].Getmonth()*1000000) + (dt[k].Getday()*10000))+((dtH*100)+(dt[k].Getminute()));;
        if (entryDate >= startDate && entryDate <= endDate)
        {
            cout << string(75,'=') << endl;
            slot[k].display(dt);

        }

    }
}
// Show all appointments between two times
void showBtwnTimesApps(appointmentList& app, patientList pat, slotList& slot, recordList& rec, diagnosesList diag, doctorList doc, date_timeList dt)
{
    int dtH;
    Date_Time date1, date2;
    cout << "Enter two times to search between and find available slots." << endl;
    cout << "Beginning date: " << endl;
    date1.add();
    cout << "Ending date: " << endl;
    date2.add();

    if(date1.GetAM_PM() == 'P')
    {
        date1.Sethour(date1.Gethour() + 12);
    }
    if(date2.GetAM_PM() == 'P')
    {
        date2.Sethour(date2.Gethour() + 12);
    }
    long long entryDate;
    long long startDate = (((date1.Getyear()+2000) * 100000000LL) + (date1.Getmonth() * 1000000) + (date1.Getday()*10000))+((date1.Gethour()*100)+(date1.Getminute()));
    long long endDate = (((date2.Getyear()+2000) * 100000000LL) + (date2.Getmonth() * 1000000) + (date2.Getday()*10000))+((date2.Gethour()*100)+(date2.Getminute()));
    int nums[dt.size()];

    for(unsigned k = 0; k < dt.size(); k++)
    {
        dtH = dt[k].Gethour();
        if(dt[k].GetAM_PM() == 'P')
        {
            dtH += 12;
        }
        entryDate = (((dt[k].Getyear()+2000) * 100000000LL) + (dt[k].Getmonth()*1000000) + (dt[k].Getday()*10000))+((dtH*100)+(dt[k].Getminute()));;
        if ((entryDate >= startDate && entryDate <= endDate))
        {
            nums[k] = dt[k].Getid();
        }

    }
    bool display = false;
    for(unsigned i = 0; i < app.size(); i++)
    {
        for(unsigned j = 0; j < slot.size(); j++)
        {
            if(slot[j].Getid() == app[i].Getslot_id())
            {
                for(unsigned k = 0; k < dt.size(); k++)
                {
                    if(slot[j].Getdate_id() == nums[k])
                    {
                        display=true;
                    }
                }
            }
        }
        if(display)
        {
            app[i].display(doc,pat,diag,slot,dt);
        }
        display = false;
    }
}



