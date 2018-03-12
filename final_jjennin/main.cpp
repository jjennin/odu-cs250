#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include "patient.h"
#include "doctor.h"
#include "slot.h"
#include "date_time.h"
#include "record.h"
#include "diagnoses.h"
#include "appointment.h"
#include "menu.h"

using namespace std;
// Displays everything, debugging purposes
//void display(patientList pList, doctorList docList, slotList sList, date_timeList dtList, diagnosesList dList);

// Reads all txt files into their proper locations
void readFiles(patientList& pList, doctorList& docList, slotList& sList, date_timeList& dtList, diagnosesList& dList);

int main()
{
    // Creation of vector objects
    patientList pList; /// COMPLETED
    doctorList docList; /// COMPLETED
    slotList sList; /// COMPLETED
    date_timeList dtList; /// COMPLETED
    recordList rList; /// COMPLETED
    diagnosesList dList; /// COMPLETED
    appointmentList appList; /// COMPLETED
//    labList lList; /// MOST LIKELY WONT DO!

    // calls readfiles
    readFiles(pList, docList, sList, dtList, dList);
    // calls menu, the menu.
    menu(pList, docList, sList, dtList, rList, dList, appList);



    //display(pList,docList, sList, dtList, dList);
    return 0;
}



void readFiles(patientList& pList, doctorList& docList, slotList& sList, date_timeList& dtList, diagnosesList& dList)
{
    ifstream inFile;
    read(inFile, pList);
    inFile.close();
    read(inFile, docList);
    inFile.close();
    read(inFile, sList);
    inFile.close();
    read(inFile, dtList);
    inFile.close();
    read(inFile, dList);
    inFile.close();

}
//void display(patientList pList, doctorList docList, slotList sList, date_timeList dtList, diagnosesList dList)
//{
//    cout << "--------DOCTORS-------" << endl;
//    for(unsigned i = 0; i < docList.size(); i++)
//    {
//        docList[i].display();
////       cout << "-" << endl;
//    }
//    cout << "---------END DOCTORS----------" << endl;
//    cout << "--------PATIENTS-------" << endl;
//    for(unsigned i = 0; i < pList.size(); i++)
//    {
//        pList[i].display();
////       cout << "-" << endl;
//    }
//    cout << "---------END PATIENTS----------" << endl;
//    cout << "--------SLOTS-------" << endl;
//    for(unsigned i = 0; i < sList.size(); i++)
//    {
//        sList[i].display();
////       cout << "-" << endl;
//    }
//    cout << "---------END SLOTS----------" << endl;
//    cout << "--------DATE TIME-------" << endl;
//    for(unsigned i = 0; i < dtList.size(); i++)
//    {
//        dtList[i].display();
////       cout << "-" << endl;
//    }
//    cout << "---------END DATE TIME----------" << endl;
//    cout << "--------DIAGNOSES-------" << endl;
//    for(unsigned i = 0; i < dList.size(); i++)
//    {
//        dList[i].display();
////        cout << "-" << endl;
//    }
//    cout << "---------END DIAGNOSES----------" << endl;
//
//}
//
