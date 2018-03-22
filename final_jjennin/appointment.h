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
    int getPatientID()
    {
        return patient_id;
    }
    void setPatientID(int const& val)
    {
        patient_id = val;
    }
    int getSlotID()
    {
        return slot_id;
    }
    void setSlotID(int const& val)
    {
        slot_id = val;
    }
    std::string getReason()
    {
        return reason;
    }
    void setReason(std::string const& val)
    {
        reason = val;
    }
    int getDiagnosisID()
    {
        return diagnosis_id;
    }
    void setDiagnosisID(int const& val)
    {
        diagnosis_id = val;
    }
    std::string getPrescribedMedication()
    {
        return prescribed_medication;
    }
    void setPrescribedMedication(std::string const& val)
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
