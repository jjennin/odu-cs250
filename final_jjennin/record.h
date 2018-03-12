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
    int Getid()
    {
        return id;
    }
    void Setid(int val)
    {
        id = val;
    }
    int Getpatient_id()
    {
        return patient_id;
    }
    void Setpatient_id(int val)
    {
        patient_id = val;
    }
    int Getdiagnoses_id()
    {
        return diagnose_id;
    }
    void Setdiagnoses_id(diagnosesList y) // interactive set diagnoses id
    {
        int diagloc = -1;
        while(diagloc == -1)
        {
            diagloc = searchEntries(y, "search");
        }
        if(diagloc != -3)
        {
            diagnose_id = y[diagloc].Getid();
        }
    }
    void Setdiagnoses_id(int val)  // simple set diagnoses id
    {
        diagnose_id = val;
    }
    std::string Getmeds()
    {
        return meds;
    }
    void Setmeds() // Interactive set meds for record
    {
        std::cout << "Please enter new medication: ";
        std::cin.ignore();
        getline(std::cin, meds);
    }
    void Setmeds(std::string val)  // simple set meds
    {
        meds = val;
    }
    std::string Getnotes()
    {
        return notes;
    }
    void Setnotes() // interactive set notes
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
