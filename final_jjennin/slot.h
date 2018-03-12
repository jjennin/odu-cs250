#ifndef SLOT_H
#define SLOT_H
#include <iostream>
#include <string>
#include <vector>
#include "doctor.h"
#include "date_time.h"


class slot
{
private:
    int id;
    int date_id;
    int doctor_id;
    bool available;
public:
    slot();
    int Getid()
    {
        return id;
    }
    void Setid(int val)
    {
        id = val;
    }
    int Getdate_id()
    {
        return date_id;
    }
    void Setdate_id(int val)
    {
        date_id = val;
    }
    int Getdoctor_id()
    {
        return doctor_id;
    }
    void Setdoctor_id(int val)
    {
        doctor_id = val;
    }
    bool Getavailable()
    {
        return available;
    }
    void Setavailable(bool val)
    {
        available = val;
    }
    void read(std::ifstream& in); /// readin slotList from file
    void display(date_timeList);
    void add(int, doctorList, date_timeList);
    void updateEntry(doctorList, date_timeList);

};

/** typedef vector of slot type **/
typedef std::vector<slot> slotList;

/// accessor to run readin slotList from file
void read (std::ifstream&,slotList&);
void showAllEntries(slotList,int,date_timeList);
void showAllEntries(slotList,int,int,date_timeList);
void addEntry(slotList&,doctorList,date_timeList);
int searchEntries(slotList,std::string,date_timeList);
int searchEntries(slotList,std::string,int,date_timeList);
void deleteEntry(slotList&,date_timeList);
#endif // SLOT_H
