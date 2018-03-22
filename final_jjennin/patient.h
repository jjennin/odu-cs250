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
    int getID()
    {
        return id;
    }
    void setID(int const& val)
    {
        id = val;
    }
    int getDoctorID()
    {
        return doctor_id;
    }
    void setDoctorID(int const& val)
    {
        doctor_id = val;
    }
    int getRecordID()
    {
        return record_id;
    }
    void setRecordID(int const& val)
    {
        record_id = val;
    }
    std::string getName()
    {
        return name;
    }
    void setName(std::string const& val)
    {
        name = val;
    }
    std::string getPhone()
    {
        return phone;
    }
    void setPhone(std::string const& val)
    {
        phone = val;
    }
    char getGender()
    {
        return gender;
    }
    void setGender(char const& val)
    {
        gender = val;
    }
    std::string getEmail()
    {
        return email;
    }
    void setEmail(std::string const& val)
    {
        email = val;
    }
    std::string getBloodType()
    {
        return blood_type;
    }
    void setBloodType(std::string const& val)
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
