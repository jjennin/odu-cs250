#ifndef PATIENT_H
#define PATIENT_H
#include <iostream>
#include <string>
#include <vector>
#include "doctor.h"
#include "date_time.h"

class patient
{
private:
    int id;
    int doctor_id;
    int record_id;
    std::string name;
    std::string phone;
    char gender;
    std::string email;
    Date_Time dob;
    std::string blood_type;
public:
    patient();
    int Getid()
    {
        return id;
    }
    void Setid(int val)
    {
        id = val;
    }
    int Getdoctor_id()
    {
        return doctor_id;
    }
    void Setdoctor_id(int val)
    {
        doctor_id = val;
    }
    int Getrecord_id()
    {
        return record_id;
    }
    void Setrecord_id(int val)
    {
        record_id = val;
    }
    std::string Getname()
    {
        return name;
    }
    void Setname(std::string val)
    {
        name = val;
    }
    std::string Getphone()
    {
        return phone;
    }
    void Setphone(std::string val)
    {
        phone = val;
    }
    char Getgender()
    {
        return gender;
    }
    void Setgender(char val)
    {
        gender = val;
    }
    std::string Getemail()
    {
        return email;
    }
    void Setemail(std::string val)
    {
        email = val;
    }
    std::string Getblood_type()
    {
        return blood_type;
    }
    void Setblood_type(std::string val)
    {
        blood_type = val;
    }
    void read(std::ifstream&); /// readin patientList from file
    void display(doctorList);
    void add(doctorList);
    void updateEntry(doctorList);

};

/** typedef vector of patient type **/
typedef std::vector<patient> patientList;
/// accessor to run readin patientList from file
void read (std::ifstream&,patientList&);
void deleteEntry(patientList&,doctorList);
void addEntry(patientList&,doctorList);
void showAllEntries(patientList&,doctorList);
void updateEntry(patientList&);
int searchEntries(patientList,std::string,doctorList);

#endif // PATIENT_H
