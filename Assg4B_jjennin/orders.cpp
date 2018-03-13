#include "orders.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
Orders::Orders(){ /// Default constructor, sets default values
    customerName="";
    itemName="";
    numberOfBoxes=0;
    costofitem=0.0;
}
/// Compares the orders in chronological order, with a tie breaker of the cost of item.
bool Orders::comparing(Orders name){
    if(name.orderDate.year > orderDate.year){
        return true; // if year is greater, return true
    }
    else if(name.orderDate.year < orderDate.year){
        return false; // if year is less, return false
    }
    if(name.orderDate.month > orderDate.month){
        return true; // if month is greater, return true
    }
    else if(name.orderDate.month < orderDate.month){
        return false; // if month is less, return false
    }
    if(name.orderDate.day > orderDate.day){
        return true; // if day is greater, return true
    }
    else if(name.orderDate.day < orderDate.day){
        return false; // if day is less, return false
    }
    /// TIE BREAKER
     if (name.costofitem < costofitem){
         return true; // if cost is greater, return true
     }
    else if (name.costofitem > costofitem){
         return false; // if cost is less, return false
    }
}


/// Sort order data
void sortOrderData(Orders * orderList, int totalOrders){
    for(int i = 0; i < totalOrders; ++i){ // LOOP 1
        for(int j = 0; j < totalOrders; ++j){ // LOOP 2
            if(orderList[i].comparing(orderList[j])){
                        Orders temp = orderList[i];
                        orderList[i] = orderList[j];
                        orderList[j] = temp;
            }
        }
    }
}
/// DISPLAY ORDER ONTO SCREEN AND FILE
void displayOrders(Orders * orders, int totalOrders, ofstream& outFile){
    cout << setw(10) << setfill(' ') << "Customer Name" << " | "
         << "Item Name" << "  | "
         << "#Boxes" << "  |  "
         << "Cost" << "  | "
         << "Order Date" << endl;
    // OUTPUT to FILE
    outFile << setw(10) << setfill(' ') << "Customer Name" << " | "
         << "Item Name" << "  | "
         << "#Boxes" << "  |  "
         << "Cost" << "  | "
         << "Order Date" << endl;
    for(int k = 0; k < 60; k++){
        cout << "-";
        outFile << "-";
    }
    cout << endl;
    outFile << endl; // OUTPUT TO FILE


    for(int i = 0; i < totalOrders; i++){
        cout << left << setw(10) << orders[i].customerName << "    | "
             << left << setw(10) << orders[i].itemName << " | "
             << right << setw(2) << setfill('0') << orders[i].numberOfBoxes << "      | "
             << right << setw(6) << setfill(' ') << fixed << setprecision(2) << orders[i].costofitem << " | "
             << right << setw(2) << setfill('0') << orders[i].orderDate.month <<":" << setw(2) << setfill('0') << orders[i].orderDate.day <<":" << setw(2) << setfill('0') << orders[i].orderDate.year << " "
             << setfill(' ') << endl;
        // OUTPUT TO FILE
        outFile << left << setw(10) << orders[i].customerName << "    | "
             << left << setw(10) << orders[i].itemName << " | "
             << right << setw(2) << setfill('0') << orders[i].numberOfBoxes << "      | "
             << right << setw(6) << setfill(' ') <<  fixed << setprecision(2) << "$" << orders[i].costofitem << " | "
             << right << setw(2) << setfill('0') << orders[i].orderDate.month <<":" << setw(2) << setfill('0') << orders[i].orderDate.day <<":" << setw(2) << setfill('0') << orders[i].orderDate.year << " "
             << setfill(' ') << endl;
    }
    outFile.close(); // CLOSE OUTPUT FILE
}


/// GRABS ALL THE INFORMATION FROM inFILE
Orders* getDataOrders(Orders * orderList, int totalOrders, ifstream& inFile, ofstream& outFile){
    char decimal; // middle character

    for(int i = 0; i < totalOrders; i++){
        inFile >> orderList[i].customerName;
        inFile >> orderList[i].itemName;
        inFile >> orderList[i].numberOfBoxes;
        inFile >> orderList[i].costofitem;
        inFile >> orderList[i].orderDate.month >> decimal >> orderList[i].orderDate.day >> decimal >> orderList[i].orderDate.year;
    }

    inFile.close(); // close infile

    printHeading("Orders", 60); // header

    sortOrderData(orderList, totalOrders); // calls sort function
    displayOrders(orderList, totalOrders, outFile); // displays order function
    return orderList;
}
