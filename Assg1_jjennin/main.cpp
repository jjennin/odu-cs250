#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;


struct shipments {
    string name, itemWeight;
    string expireDate;
    string dateRecv;
    string itemSize;
    char sMethod;
    double itemPrice;
};
struct orders {
    string name, itemName;
    string datePlaced;
    int numberBoxes;
    double totalCost;
};
struct customers {
    string name, location;
    int distance;
};
void readShipments(fstream &inFile, int &shipmentCount, shipments fileShipments[20]);
void readCustomers(fstream &inFile);
void readOrders(fstream &inFile);
void searchShipments(fstream &inFile, int shipmentCount, shipments fileShipments[20]);


int main()
{
    fstream inFile;
    int shipmentCount = 20;
    shipments fileShipments[shipmentCount];

    cout << "******Assignment 1*******" << endl;
    cout << "*****Jason Jennings******" << endl;
    readShipments(inFile, shipmentCount, fileShipments);
    readCustomers(inFile);
    readOrders(inFile);
    searchShipments(inFile, shipmentCount, fileShipments);


    return 0;
}

void readShipments(fstream &inFile, int &shipmentCount, shipments fileShipments[20]){
    string fileName = "Shipments.txt";
    inFile.open(fileName.c_str(),ios::in);
    inFile >> shipmentCount;
    fileShipments[shipmentCount];
    cout << "============================================================================="<< endl;
    cout << "                                  Shipments                                   "<< endl;
    cout << "============================================================================="<< endl;
    cout << left << setw(9) << "Food Item " << setw(9) << "| Exp Date   " << setw(9) << "| Box Size  " << setw(9) << "| Weight" << setw(9) << "| Storage " << setw(9) << "| Received Date " << setw(9) << "| Price" << endl;
    cout << "-----------------------------------------------------------------------------"<< endl;
    for(int i = 0; i < shipmentCount; i++){
        inFile
        >> fileShipments[i].name
        >> fileShipments[i].expireDate
        >> fileShipments[i].itemSize
        >> fileShipments[i].itemWeight
        >> fileShipments[i].sMethod
        >> fileShipments[i].dateRecv
        >> fileShipments[i].itemPrice;
    }
    for (int j = 0; j < shipmentCount; j++){
        cout << left << setw(9)
        << fileShipments[j].name << " | " << setw(9)
        << fileShipments[j].expireDate << " | " << setw(9)
        << fileShipments[j].itemSize << " | " << setw(6)
        << fileShipments[j].itemWeight << " | " << setw(7)
        << fileShipments[j].sMethod << " | " << setw(13)
        << fileShipments[j].dateRecv << " | " << showpoint << setprecision(4)
        << fileShipments[j].itemPrice << endl;
    }
    inFile.close();
}
void readCustomers(fstream &inFile){
    string fileName = "Customers.txt";
    inFile.open(fileName.c_str(),ios::in);
    int customerCount;
    inFile >> customerCount;
    customers fileCustomers[customerCount];
    cout << "========================================================="<< endl;
    cout << "                        Customers                        "<< endl;
    cout << "========================================================="<< endl;
    cout << left << setw(9) << "Customer Name " << setw(15) << "| City " << setw(9) << "| Distance  " << endl;
    cout << "---------------------------------------------------------"<< endl;
    for(int i = 0; i < customerCount; i++){
        inFile
        >> fileCustomers[i].name
        >> fileCustomers[i].location
        >> fileCustomers[i].distance;
    }
    for (int j = 0; j < customerCount; j++){
        cout << left << setw(13)
        << fileCustomers[j].name << " | " << setw(12)
        << fileCustomers[j].location << " | " << setw(9)
        << fileCustomers[j].distance << endl;
    }
    inFile.close();
}
void readOrders(fstream &inFile){
    string fileName = "Orders.txt";
    inFile.open(fileName.c_str(),ios::in);
    int orderCount;
    inFile >> orderCount;
    orders fileOrders[orderCount];
    cout << "========================================================="<< endl;
    cout << "                          Orders                         "<< endl;
    cout << "========================================================="<< endl;
    cout << left << setw(9) << "Customer Name " << setw(11) << "| Item Name " << setw(8) << "| #Boxes  " << setw(7) << "| Cost  " << setw(9) << "| Order Date  " << endl;
    cout << "---------------------------------------------------------"<< endl;
    for(int i = 0; i < orderCount; i++){
        inFile
        >> fileOrders[i].name
        >> fileOrders[i].itemName
        >> fileOrders[i].numberBoxes
        >> fileOrders[i].totalCost
        >> fileOrders[i].datePlaced;
    }
    for (int j = 0; j < orderCount; j++){
        cout << left << setw(13)
        << fileOrders[j].name << " | " << setw(9)
        << fileOrders[j].itemName << " | " << setw(7)
        << fileOrders[j].numberBoxes << " | " << setw(5)
        << fileOrders[j].totalCost << " | " << setw(8)
        << fileOrders[j].datePlaced << endl;
    }
    inFile.close();
}
void searchShipments(fstream &inFile, int shipmentCount, shipments fileShipments[20]){
    fileShipments[shipmentCount];
    string userSearch;
    int searchItems = 0;
        cout << endl << "You Want to Search in Shipments" << endl << "1. Yes" << endl << "2. No" << endl << endl;
        cout << "Enter Option (1-2): ";
        cin >> searchItems;
    while(searchItems == 1){
    cout << "Please enter item name you wish to search: ";
    cin >> userSearch;
    cout << endl;
    int matchedCount = 0;
    cout << "============================================================================="<< endl;
    cout << "                                Search Results                               "<< endl;
    cout << "============================================================================="<< endl;
    cout << left << setw(9) << "Food Item " << setw(9) << "| Exp Date   " << setw(9) << "| Box Size  " << setw(9) << "| Weight" << setw(9) << "| Storage " << setw(9) << "| Received Date " << setw(9) << "| Price" << endl;
    cout << "-----------------------------------------------------------------------------"<< endl;
    for(int j = 0; j < shipmentCount; j++){
        if(userSearch == fileShipments[j].name){
            cout << left << setw(9)
            << fileShipments[j].name << " | " << setw(9)
            << fileShipments[j].expireDate << " | " << setw(9)
            << fileShipments[j].itemSize << " | " << setw(6)
            << fileShipments[j].itemWeight << " | " << setw(7)
            << fileShipments[j].sMethod << " | " << setw(13)
            << fileShipments[j].dateRecv << " | " << showpoint << setprecision(4)
            << fileShipments[j].itemPrice << endl;
            matchedCount++;
        }
    }
    if(matchedCount == 0) {
            cout << "No matches were found in the shipments!" << endl;
     }
        cout << endl << "You Want to Search in Shipments" << endl << "1. Yes" << endl << "2. No" << endl << endl;
        cout << "Enter Option (1-2): ";
        cin >> searchItems;
    }
}

