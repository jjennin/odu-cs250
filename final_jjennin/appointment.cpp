#include "appointment.h"
#include <string>
#include <fstream>
#include <iostream>


using namespace std;

// Default Constructor
appointment::appointment()
{
    id = 0;
    doctor_id = 0;
    patient_id = 0;
    slot_id = 0;
    reason = "No Reason Defined";
    diagnosis_id = 0;
    prescribed_medication = "None";
}

// Basic display for appointments
void appointment::display(doctorList d, patientList p, diagnosesList di, slotList s, date_timeList dt)
{
    int dloc=0,ploc=0,diloc=0,sloc=0,dtloc=0;
    for(unsigned i = 0; i < d.size(); i++)
    {
        if(d[i].Getid() == doctor_id)
        {
            dloc = i;
        }
    }
    for(unsigned i = 0; i < p.size(); i++)
    {
        if(p[i].Getid() == patient_id)
        {
            ploc = i;
        }
    }
    for(unsigned i = 0; i < di.size(); i++)
    {
        if(di[i].Getid() == diagnosis_id)
        {
            diloc = i;
        }
    }
    for(unsigned i = 0; i < s.size(); i++)
    {
        if(s[i].Getid() == slot_id)
        {
            sloc = i;
        }
    }
    for(unsigned i = 0; i < dt.size(); i++)
    {
        if(dt[i].Getid() == s[sloc].Getdate_id())
        {
            dtloc = i;
        }
    }
    cout << string(43,'=') << endl;
    cout << " ID: " << id << endl
         << " Doctor: " << d[dloc].Getname()  << " (ID:" << doctor_id << ")" << endl
         << " Patient: " << p[ploc].Getname() << " (ID:" << patient_id << ")" << endl
         << " Slot: ";
    dt[dtloc].display();
    cout << " (ID:" << slot_id << ")" << endl
         << " Reason: " << reason << endl
         << " Diagnosis: " << di[diloc].Getdisease_name() << " (ID:" << diagnosis_id << ")" << endl
         << " Medication: " << prescribed_medication << endl;
    cout << string(43,'=') << endl;
}
//void showAllEntries(appointmentList x, doctorList d, patientList p, diagnosesList di, slotList s, date_timeList dt)
// Shows all appointments
void showAllEntries(appointmentList app, doctorList doc, patientList pat, diagnosesList diag, slotList slot, date_timeList dt)
{
    for(unsigned i = 0; i < app.size(); i++)
    {
        app[i].display(doc,pat,diag,slot,dt);
    }
}
// searches appointments by id
int searchEntries(appointmentList app,string thing)
{
    int choice = 0;
    cout << string(43,'-') << endl;

    cout << "Please enter appointment ID to " << thing << ": ";
    cin >> choice;

    for(unsigned i = 0; i < app.size(); i++)
    {
        if(choice == app[i].Getid())
        {
            return i;
        }
    }
    cout << "No results found" << endl;
    return -1;
}
// delete an appointment
void deleteEntry(appointmentList& app, slotList& slot)
{
    char yn = 'Z';
    int loc = -1;
    loc = searchEntries(app,"delete");
    if(loc != -1)
    {
        cout << "-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-" << endl;
        do
        {
            // double check choice of deletion
            cout << "Are you sure you want to delete appointment " << app[loc].Getid() << "? (y/n): ";
            cin >> yn;
            if(yn == 'y')
            {
                app[loc].Getslot_id();
                for(unsigned i = 0; i < slot.size(); i++)
                {
                    if(app[loc].Getslot_id() == slot[i].Getid())
                    {
                        slot[i].Setavailable(true);
                    }
                }
                app.erase(app.begin()+loc);
                cout << "Appointment Deleted." << endl;
            }
            else if(yn == 'n')
            {
                cout << "Canceled deletion of Appointment." << endl;
            }

        }
        while(yn!='y'&&yn!='n');
        cout << "-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-" << endl;

    }
}
// allows update of each section of appointment
void appointment::updateEntry(patientList pat, slotList& slot, recordList& rec, diagnosesList diag, doctorList doc, date_timeList dt)
{
    int entry;
    int loc = 0;
    int prLoc = 0;
    int temp = 0;
    do
    {
        cout << string(43,'-') << endl;
        cout << "1. Doctor" << endl
             << "2. Patient" << endl
             << "3. Slot" << endl
             << "4. Reason for visit" << endl
             << "5. Diagnosis" << endl
             << "6. Prescribed Medications" << endl
             << "7. Abort" << endl;
        cout << "Please chose which entry to update: ";
        cin >> entry;
        switch(entry)
        {
        case 1:
            loc = searchEntries(doc, "search");
            if(loc != -1)
            {
                doctor_id = doc[loc].Getid();
                cout << "Doctor ID updated for appointment." << endl;
            }
            break;
        case 2:
            loc = searchEntries(pat, "search",doc);
            if(loc != -1)
            {
                patient_id = pat[loc].Getid();
                cout << "Patient ID updated for appointment." << endl;
                prLoc = searchEntries(rec,patient_id);
                if(prLoc == -1)
                {
                    temp = 0;
                    for(unsigned i = 0; i < rec.size(); i++)
                    {
                        if (rec[i].Getpatient_id() == patient_id)
                        {
                            temp = rec[i].Getid();
                        }
                    }
                    ::add(rec,patient_id,temp);
                }
            }
            break;
        case 3:
            loc = searchEntries(slot, "assign", doctor_id,dt);
            if(loc != -1)
            {
                slot_id = slot[loc].Getid();
                slot[loc].Setavailable(false);
                cout << "Slot updated for appointment." << endl;

            }
            break;
        case 4:
            cout << "Please enter reason for visit: " << endl;
            cin.ignore();
            getline(cin,reason);
            cout << "Reason updated for appointment." << endl;
            break;
        case 5:
            loc = searchEntries(diag,"assign");
            if(loc != -1)
            {
                diagnosis_id = diag[loc].Getid();
                cout << "Diagnosis ID updated for appointment." << endl;
                if(patient_id > 0)
                {
                    prLoc = searchEntries(rec,patient_id);
                    if(prLoc != -1)
                    {
                        rec[prLoc].Setdiagnoses_id(diagnosis_id);
                    }
                    else
                    {
                        temp = 0;
                        for(unsigned i = 0; i < rec.size(); i++)
                        {
                            if(rec[i].Getpatient_id() == patient_id)
                            {
                                temp = rec[i].Getid();
                            }
                        }
                        ::add(rec,patient_id,temp);
                        rec[rec.size()-1].Setdiagnoses_id(diagnosis_id);
                    }
                }
            }
            break;
        case 6:
            cout << "Please enter new medications for visit: " << endl;
            cin.ignore();
            getline(cin,prescribed_medication);
            cout << "Prescribed Medications updated for appointment." << endl;
            if(patient_id > 0)
            {
                prLoc = searchEntries(rec,patient_id);
                if(prLoc != -1)
                {
                    rec[prLoc].Setmeds(prescribed_medication);
                }
                else
                {
                    temp = 0;
                    for(unsigned i = 0; i < rec.size(); i++)
                    {
                        if(rec[i].Getpatient_id() == patient_id)
                        {
                            temp = rec[i].Getid();
                        }
                    }
                    ::add(rec,patient_id,temp);
                    rec[rec.size()-1].Setmeds(prescribed_medication);
                }
            }
            break;
        case 7:
            break;
        default:
            break;
        }
        loc = -1;

    }
    while(entry != 7);


}
// add new appointment step-2
//void appointment::add(patientList y, slotList& z, recordList& a, diagnosesList b, doctorList c)
void appointment::add(patientList pat, slotList& slot, recordList& rec, diagnosesList diag, doctorList doc,date_timeList dt)
{
    int loc = -1;
    while(loc == -1)
    {
        cout << string(43,'-') << endl;
        cout << "Set a Doctor for the appointment: " << endl;
        loc = searchEntries(doc, "search");
        doctor_id = doc[loc].Getid();
    }
    loc = -1;
    while(loc == -1)
    {
        cout << string(43,'-') << endl;
        cout << "Set the patient for the appointment: " << endl;
        loc = searchEntries(pat, "search",doc);
        patient_id = pat[loc].Getid();
    }
    loc = -1;
    while(loc == -1)
    {
        cout << string(43,'-') << endl;
        cout << "Set a Slot ID for appointment: " << endl;
        loc = searchEntries(slot, "search", doctor_id,dt);
        slot_id = slot[loc].Getid();
        slot[loc].Setavailable(false);
    }
    loc = -1;
    cout << "Please enter reason for visit: " << endl;
    cin.ignore();
    getline(cin,reason);
}
// add new appointment step-1
void add(appointmentList& app, patientList pat, slotList& slot, recordList& rec, diagnosesList diag, doctorList doc, date_timeList dt)
{
    appointment temp;
    temp.add(pat,slot,rec,diag,doc,dt);
    temp.Setid(app.size());
    app.push_back(temp);
}
