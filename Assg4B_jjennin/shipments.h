#ifndef SHIPMENTS_H_INCLUDED
#define SHIPMENTS_H_INCLUDED
#include "extra.h"

/// Shipments Struct
struct Shipment {
    string foodName; //food name
    Date expdate; //expiration date
    SizeOfBox sizeofbox; // size of the box
    double weightOfBox; // weight of the box
    char storageMethod; // storage method
    Date shipmentrecieved; // when shipment was received
    double priceofitem; // price of the shipment
    Shipment(); /// Default Constructor
};

bool comparing(Shipment name, Shipment name2); /// CHANGED MEMBER FUNCTION TO INDEPENDENT FUNCTION! PART B!!!!!
///Search shipments
void searchShipments(Shipment * shipments, string itemName, int totalShipments);
///Allows the array of structs to be edited/used in the functions and pass other data.
Shipment * getDataShipments(Shipment * shipments, int totalShipments, ifstream& inFile, ofstream& outFile);


#endif // SHIPMENTS_H_INCLUDED
