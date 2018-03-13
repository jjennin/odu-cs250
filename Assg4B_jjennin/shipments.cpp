#include "shipments.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
using namespace std;
Shipment::Shipment(){ /// Default constructor, assigns default values.
    foodName="";
    weightOfBox=0.0;
    storageMethod='A';
    priceofitem=0.0;
}
/// Organizes shipments in chronological order, and by total price if tied
bool shipmentcomparing(Shipment name, Shipment name2){
    if(name.shipmentrecieved.year > name2.shipmentrecieved.year){
        return true; // if year greater, return true
    }
    else if(name.shipmentrecieved.year < name2.shipmentrecieved.year){
        return false; // if year less, return false
    }
    if(name.shipmentrecieved.month > name2.shipmentrecieved.month){
        return true; // if month greater, return true
    }
    else if(name.shipmentrecieved.month < name2.shipmentrecieved.month){
        return false; // if month less, return false
    }
    if(name.shipmentrecieved.day > name2.shipmentrecieved.day){
        return true; // if day greater, return true
    }
    else if(name.shipmentrecieved.day < name2.shipmentrecieved.day){
        return false; // if day less, return false
    }
    /// EXPDATE TIE BREAKER
    if(name.expdate.year > name2.expdate.year){
        return true; //  if year greater, return true
    }
    else if(name.expdate.year < name2.expdate.year){
        return false; // if year less, return false
    }
    if(name.expdate.month > name2.expdate.month){
        return true; // if month greater, return true
    }
    else if(name.expdate.month < name2.expdate.month){
        return false; // if month less, return false
    }
    if(name.expdate.day > name2.expdate.day){
        return true; // if day greater, return true
    }
    else if(name.expdate.day < name2.expdate.day){
        return false; // if day less, return false
    }
}


/// SORTS THE SHIPMENTS!
void sortShipmentOrder(Shipment* shipmentList, int totalShipments){
    for(int i = 0; i < totalShipments; ++i){ /// LOOP 1
        for(int j = 0; j < totalShipments; ++j){ /// LOOP 2 inside of 1

            if(shipmentcomparing(shipmentList[j],shipmentList[i])){ /// COMPARES SHIPMENT 1 to SHIPMENT 2
                        Shipment temp = shipmentList[i];   // temp set from i
                        shipmentList[i] = shipmentList[j]; // i = j
                        shipmentList[j] = temp; // j = temp
            }
        }
    }
}
/// DISPLAYS THE SHIPMENTS
void displayShipments(Shipment* shipmentList, int totalShipments, ofstream& outFile){
   cout << setw(10) << "Food Item" << "  | "
        << "Exp Date " << "  | "
        << "Box Size" << "  | "
        << "Weight" << " | "
        << "Storage" << " | "
        << "Received date" << " | "
        << "Price" << endl;

    // SENT OUT TO FILE
   outFile << setw(10) << "Food Item" << "  | "
        << "Exp Date " << "  | "
        << "Box Size" << "  | "
        << "Weight" << " | "
        << "Storage" << " | "
        << "Received date" << " | "
        << "Price" << endl;

    for(int k = 0; k < 80; k++){
        cout << "-";
        outFile << "-";
    }
    cout << endl;
    outFile << endl; // send out to file
    for(int i = 0; i < totalShipments; i++){
    // sends out to the console
        cout << left << setw(9) << shipmentList[i].foodName << " | "
        << right <<setw(2) << setfill('0') << shipmentList[i].expdate.month <<":" << setw(2) << setfill('0') << shipmentList[i].expdate.day <<":" << setw(2) << setfill('0') << shipmentList[i].expdate.year << " | "
        << right <<setw(2) << setfill('0') << shipmentList[i].sizeofbox.length <<":"<< setw(2) << setfill('0') << shipmentList[i].sizeofbox.width << ":" << setw(2) << setfill('0') <<shipmentList[i].sizeofbox.height << " | "
        << right <<setw(2) << fixed << setprecision(2) << shipmentList[i].weightOfBox << " | "
        << right << shipmentList[i].storageMethod << " | "
        << right <<setw(2) << setfill('0') << shipmentList[i].shipmentrecieved.month <<":" << setw(2) << setfill('0') << shipmentList[i].shipmentrecieved.day <<":" << setw(2) << setfill('0') << shipmentList[i].shipmentrecieved.year << " | "
        << right << fixed << setprecision(2) << setfill('0') << shipmentList[i].priceofitem << " "
        << setfill(' ') << endl;
        cout.unsetf(ios_base::fixed);

    // sends out to the file
    outFile << left << setw(9) << shipmentList[i].foodName << " | "
        << right <<setw(2) << setfill('0') << shipmentList[i].expdate.month <<":" << setw(2) << setfill('0') << shipmentList[i].expdate.day <<":" << setw(2) << setfill('0') << shipmentList[i].expdate.year << " | "
        << right <<setw(2) << setfill('0') << shipmentList[i].sizeofbox.length <<":"<< setw(2) << setfill('0') << shipmentList[i].sizeofbox.width << ":" << setw(2) << setfill('0') <<shipmentList[i].sizeofbox.height << " | "
        << right <<setw(2) << fixed << setprecision(2) << shipmentList[i].weightOfBox << " | "
        << right << shipmentList[i].storageMethod << " | "
        << right <<setw(2) << setfill('0') << shipmentList[i].shipmentrecieved.month <<":" << setw(2) << setfill('0') << shipmentList[i].shipmentrecieved.day <<":" << setw(2) << setfill('0') << shipmentList[i].shipmentrecieved.year << " | "
        << right << fixed << setprecision(2) << setfill('0') << shipmentList[i].priceofitem << " "
        << setfill(' ') << endl;
        outFile.unsetf(ios_base::fixed);
    }
    outFile.close(); // close outfile
}
/// Grabs all the shipment data from inFile.
Shipment* getDataShipments(Shipment* shipmentList, int totalShipments, ifstream& inFile, ofstream& outFile){

    char decimal;

    for(int i = 0; i < totalShipments; i++){
        inFile >> shipmentList[i].foodName;
        inFile >> shipmentList[i].expdate.month >> decimal >> shipmentList[i].expdate.day >> decimal >> shipmentList[i].expdate.year;
        inFile >> shipmentList[i].sizeofbox.length >> decimal >> shipmentList[i].sizeofbox.width >> decimal >> shipmentList[i].sizeofbox.height;
        inFile >> shipmentList[i].weightOfBox;
        inFile >> shipmentList[i].storageMethod;
        inFile >> shipmentList[i].shipmentrecieved.month >> decimal >> shipmentList[i].shipmentrecieved.day >> decimal >> shipmentList[i].shipmentrecieved.year;
        inFile >> shipmentList[i].priceofitem;
    }
    inFile.close(); // close infile

    printHeading("Shipments", 80); // header

    sortShipmentOrder(shipmentList,totalShipments); // calls sort function which calls the organize function
    displayShipments(shipmentList,totalShipments,outFile); // calls display shipments function
    return shipmentList;
}
/// Search the shipments
void searchShipments(Shipment* shipmentList, string itemName, int totalShipments){

    string originalItemName;
    bool searchHit = false;

	cout << "\n\nSearching for Food Item: " << itemName << "\n\n"<< endl;

    transform(itemName.begin(),itemName.end(),itemName.begin(), ::toupper);

    printHeading("Search Results",80);

    cout << setw(10) << "Food Item" << "  | "
         << "Exp Date " << "  | "
         << "Box Size" << "  | "
         << "Weight" << " | "
         << "Storage" << " | "
         << "Received date" << " | "
         << "Price" << endl;

    for(int k = 0; k < 80; k++){
        cout << "-";
    }
    cout << endl;

    for(int i = 0; i < totalShipments; i++){
		originalItemName = shipmentList[i].foodName;
        transform(originalItemName.begin(),originalItemName.end(),originalItemName.begin(),::toupper);
        if(itemName.compare(originalItemName) == 0){
            searchHit = true;
            cout << left << setw(9) << shipmentList[i].foodName << "   | "
                 << right <<setw(2) << setfill('0') << shipmentList[i].expdate.month <<":" << setw(2) << setfill('0') << shipmentList[i].expdate.day <<":" << setw(2) << setfill('0') << shipmentList[i].expdate.year << " | "
                 << right <<setw(2) << setfill('0') << shipmentList[i].sizeofbox.length <<":"<< setw(2) << setfill('0') << shipmentList[i].sizeofbox.width << ":" << setw(2) << setfill('0') <<shipmentList[i].sizeofbox.height << "  | "
                 << right <<setw(2) << shipmentList[i].weightOfBox << "     | "
                 << right <<shipmentList[i].storageMethod << "       | "
                 << right <<setw(2) << setfill('0') << shipmentList[i].shipmentrecieved.month <<":" << setw(2) << setfill('0') << shipmentList[i].shipmentrecieved.day <<":" << setw(2) << setfill('0') << shipmentList[i].shipmentrecieved.year << "    | "
                 << right << fixed  << setprecision(2) << setfill('0') << shipmentList[i].priceofitem << " "
                 << setfill(' ') << endl;
            cout.unsetf(ios_base::fixed);
        }
    }

    if(!searchHit){
        cout << "No Items Found in Shipments! Try Again" << endl;
    }
}
