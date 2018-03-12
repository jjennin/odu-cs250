#include "record.h"
#include <string>
#include <fstream>
#include <iostream>
//#include "diagnoses.h"

using namespace std;
// default constructors
record::record()
{
    id = 0;
    patient_id = 0;
    notes = "None.";
    diagnose_id = 0;
    meds = "None.";
}
// simple records display
void record::display()
{
    cout << string(43,'=') << endl;
    cout << " Record ID: " << id << endl
         << " Patient ID: " << patient_id << endl
         << " Notes: " << notes << endl
         << " Diagnosis ID: " << diagnose_id << endl
         << " Medications: " << meds << endl;
    cout << string(43,'=') << endl;
}
// add new record
void add(recordList& rec, int patientID, int recordID)
{
    cout << string(43,'-') << endl;
    cout << "There is not a record for this patient! Creating one . . . " << endl;
    record temp;
    if(recordID < 1)
    {
        temp.Setid(1);
    }
    else
    {
        temp.Setid(recordID);
    }
    temp.Setpatient_id(patientID);
    rec.push_back(temp);
}
// search all records
int searchEntries(recordList& rec, int patientID)
{
    for(unsigned i = 0; i < rec.size(); i++)
    {
        if(patientID == rec[i].Getpatient_id())
        {
            return i;
        }
    }
    return -1;
}


