#ifndef RECORD_H
#define RECORD_H
#include <iostream>
#include <string>
#include <vector>
#include "diagnoses.h"


class record
{
private:
    int id;
    int patient_id;
    int diagnose_id;
    std::string notes;
    std::string meds;
public:
    record();
    int getID()
    {
        return id;
    }
    void setID(int const& val)
    {
        id = val;
    }
    int getPatientID()
    {
        return patient_id;
    }
    void setPatientID(int const& val)
    {
        patient_id = val;
    }
    int getDiagnosesID()
    {
        return diagnose_id;
    }
    void setDiagnosesID(diagnosesList y) // interactive set diagnoses id
    {
        int diagloc = -1;
        while(diagloc == -1)
        {
            diagloc = searchEntries(y, "search");
        }
        if(diagloc != -3)
        {
            diagnose_id = y[diagloc].getID();
        }
    }
    void setDiagnosesID(int const& val)  // simple set diagnoses id
    {
        diagnose_id = val;
    }
    std::string getMeds()
    {
        return meds;
    }
    void setMeds() // Interactive set meds for record
    {
        std::cout << "Please enter new medication: ";
        std::cin.ignore();
        getline(std::cin, meds);
    }
    void setMeds(std::string const& val)  // simple set meds
    {
        meds = val;
    }
    std::string getNotes()
    {
        return notes;
    }
    void setNotes() // interactive set notes
    {
        std::cout << "Please enter new notes: ";
        std::cin.ignore();
        getline(std::cin, notes);
    }
    void display();
};

/** typedef vector of record type **/
typedef std::vector<record> recordList;

void add(recordList&,int,int);
int searchEntries(recordList&,int);
#endif // RECORD_H
