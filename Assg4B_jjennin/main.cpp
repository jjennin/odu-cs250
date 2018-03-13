#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <algorithm>
#include "extra.h"
#include "shipments.h"
#include "orders.h"

using namespace std;
/// My Part B is changing Shipments sorting member function to a independent function! "bool shipmentcomparing" in shipments.h
int main(){
    cout << "Assignment 4B - Jason Jennings";
    ifstream inDataShipments; // Infile shipments.txt
    ifstream inDataOrders; // infile orders.txt
    ofstream SequencedOrders; // outfile organized orders
    ofstream SequencedShipments; // outfile organized shipments

    int totalShipments = 0; // filler for total
    int totalOrders = 0; // filler for total

    inDataShipments.open("Shipments.txt"); // assigns infile
    inDataOrders.open("Orders.txt"); // assigns infile
    SequencedOrders.open("SequencedOrders.txt"); // assigns outfile
    SequencedShipments.open("SequencedShipments.txt"); // assigns outfile

    /// ENSURES FILES CAN BE READ
    if (!inDataShipments)
    {
        cout << "The Shipments input file does not exist. Program terminates!" << endl;
        return 1;
    }
    if (!inDataOrders)
    {
        cout << "The Orders input file does not exist. Program terminates!" << endl;
        return 1;
    }
    if (!SequencedOrders)
    {
        cout << "The Orders input file does not exist. Program terminates!" << endl;
        return 1;
    }
    if (!SequencedShipments)
    {
        cout << "The Orders input file does not exist. Program terminates!" << endl;
        return 1;
    }
    /// END OF FILE CHECK
    inDataShipments >> totalShipments; // gets counter for shipments
    inDataOrders >> totalOrders; // gets counter for orders
    Shipment * shipments; // creates pointer to shipments
    Orders * orders; // creates pointer to orders
    shipments = new Shipment[totalShipments]; // create shipments array
    orders = new Orders[totalOrders]; // creates orders array
    getDataShipments(shipments, totalShipments, inDataShipments,SequencedShipments); // processes shipment information
    getDataOrders(orders, totalOrders, inDataOrders,SequencedOrders); // processes orders information

    int searchOption; // search number option

    /// SEARCHES SHIPMENTS
    do{
        cout << "\n\n\nDo You Want to Search in Shipments \n"
         << "1. Yes \n"
         << "2. No \n"
         << "\n"
         << "Enter Option (1-2): ";
        cin >> searchOption;

        if(searchOption == 1){
            string itemName;

            cout << "Enter the Item to Search:" << endl;
            cin >> itemName;
            searchShipments(shipments,itemName,totalShipments);
        }

    }while(searchOption != 2);

    if(searchOption == 2){
        exit(0);
    }
    /// END SEARCH
}

