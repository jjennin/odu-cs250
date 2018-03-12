#ifndef MENU_H
#define MENU_H
#include "patient.h"
#include "doctor.h"
#include "slot.h"
#include "date_time.h"
#include "record.h"
#include "diagnoses.h"
#include "appointment.h"
#include <iostream>
#include <string>
#include <vector>
///EXTRAS
void clearscr();


///MENUS
void menu(patientList& pList, doctorList& docList, slotList& sList, date_timeList& dtList, recordList& rList, diagnosesList& dList, appointmentList& appList);
void menu(appointmentList& app, patientList pat, slotList& slot, recordList& rec, diagnosesList diag, doctorList doc, date_timeList dt);
void menu(slotList& slot, date_timeList dt, doctorList doc);
void menu(doctorList& slot, appointmentList app);
void menu(patientList& pat, doctorList doc);
void menu(recordList& rec, diagnosesList& diag, patientList pat, doctorList doc);
void searchAndDisplayPatientsByDoctor(patientList pat, doctorList doc);
void searchAndDisplaySlotsByDoctor(slotList slot, doctorList doc,date_timeList);
void showBtwnTimes(date_timeList dt, slotList slot);
void showBtwnTimesApps(appointmentList& app, patientList pat, slotList& slot, recordList& rec, diagnosesList diag, doctorList doc, date_timeList dt);
#endif // MENU_H
