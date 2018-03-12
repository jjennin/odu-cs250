#ifndef APPOINTMENT_H
#define APPOINTMENT_H
#include <iostream>
#include <string>
#include <vector>

#include "record.h"
#include "patient.h"
#include "slot.h"
#include "doctor.h"
#include "diagnoses.h"


class appointment
{
private:
    int id;
    int doctor_id;
    int patient_id;
    int slot_id;
    std::string reason;
    int diagnosis_id;
    std::string prescribed_medication;
public:
    appointment();
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
    int Getpatient_id()
    {
        return patient_id;
    }
    void Setpatient_id(int val)
    {
        patient_id = val;
    }
    int Getslot_id()
    {
        return slot_id;
    }
    void Setslot_id(int val)
    {
        slot_id = val;
    }
    std::string Getreason()
    {
        return reason;
    }
    void Setreason(std::string val)
    {
        reason = val;
    }
    int Getdiagnosis_id()
    {
        return diagnosis_id;
    }
    void Setdiagnosis_id(int val)
    {
        diagnosis_id = val;
    }
    std::string Getprescribed_medication()
    {
        return prescribed_medication;
    }
    void Setprescribed_medication(std::string val)
    {
        prescribed_medication = val;
    }
    void display(doctorList,patientList,diagnosesList,slotList,date_timeList);
    void add(patientList,slotList&,recordList&,diagnosesList,doctorList,date_timeList);
    void updateEntry(patientList,slotList&,recordList&,diagnosesList,doctorList,date_timeList);
};

/** typedef vector of appointment type **/
typedef std::vector<appointment> appointmentList;

void showAllEntries(appointmentList,doctorList,patientList,diagnosesList,slotList,date_timeList);
void addEntry(appointmentList&,doctorList,date_timeList);
int searchEntries(appointmentList,std::string);
void deleteEntry(appointmentList&,slotList&);
void add(appointmentList&,patientList,slotList&,recordList&,diagnosesList,doctorList,date_timeList);
#endif // APPOINTMENT_H
