#ifndef ORDERS_H_INCLUDED
#define ORDERS_H_INCLUDED
#include "extra.h"

struct Orders{
    std::string customerName; // Customer name
    std::string itemName; // Item name
    int numberOfBoxes; // Number of Boxes
    double costofitem; // Cost of each box
    Date orderDate; // The order date
    Orders(); ///Default constructor
    bool comparing(Orders name);///Member comparing function
};
/// Sort the data
void sortOrderData(Orders * orders, int totalOrders);
/// allows data pass through
Orders* getDataOrders(Orders * orders, int totalOrders, ifstream& inFile, ofstream& outFile);


#endif // ORDERS_H_INCLUDED
