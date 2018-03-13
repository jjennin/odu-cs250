#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

#include "manager.h"
#include "salesmen.h"
#include "clients.h"

void displayHierarchy (managerList man, int place);
void operationRemoveWeakestLink (managerList& man, int place);


int main(){
    cout << "-------------------------------" << endl
         << "      CS250 - Assignment 7     " << endl
         << "         Jason Jennings        " << endl
         << "           11/04/2017          " << endl
         << " Fires lowest producing worker " << endl
         << "and redistributes their clients" << endl
         << "-------------------------------" << endl << endl;
    fstream inFile;
    inFile.open("input.txt"); /// opens input file
    if(!inFile){
        cout << "Failure"; /// checks for failure
        return 0;
    }
    managerList man; /// creates Manager vector
    int manCount = 1; /// sets mananger Count (if file had it, then I'd input from that....)
    read(inFile, man, manCount); /// reads in managers, salesmen, and clients
    for(int i = 0; i < manCount; i++){ /// runs as many times as managers
        displayHierarchy(man,i); /// displays everything
        operationRemoveWeakestLink(man,i); /// deletes slacker salesman
        displayHierarchy(man,i); /// displays everything again
    }

    return 0;
}
/**
** This displays all the information provided before with managers, salesmen, and clients
**/
void displayHierarchy (managerList man, int place){
    cout << "============================Manager "<<place+1<<"==============================" << endl;
    cout << "Manager: " << left << setw(29) << man[place].getName()  << " Salary: $" << setw(8) << man[place].getSalary() << endl;
    for(int k = 0; k < man[place].getSalesSize(); k++){
        cout << "-------------------------------------------------------------------" << endl;
        salesmen Sales = man[place].get_sales()[k];
        cout << "Salesman: " << left << setw(20) << Sales.getName() << " ID: "<< setw(9)<< Sales.getID() << " Total Sales: $" << Sales.getTotalSales() << endl;
        for(int j = 0; j < Sales.getClientsSize(); j++){
            clients Cli = Sales.get_clients()[j];
            cout << setw(10) << " " << left << "- Customer: " << setw(28) << Cli.getName() << " Sales: $" << setw(10) << Cli.getMoney() << endl;
        }
    }
    cout << "===================================================================" << endl;

}
/**
** It seems that some of the workers are not holding up their end of the bargon,
** so I was requested to create an algorithm that will fire the weakest link to the company
**** This compares all the total sales and finds the salesman who has collected the least amount
**** of money and fires them, once fired, redistributes all the clients the salesman had to
**** other more efficient workers.
**/
void operationRemoveWeakestLink(managerList& man, int place){
    cout << endl;
    cout << "\tcalculating firing algorithm . . . " << endl;
    double leastSales=man[place].get_sales()[0].getTotalSales(); // placeholder
    for(int k = 0; k < man[place].getSalesSize(); k++){
        if(man[place].get_sales()[k].getTotalSales() < leastSales){ // checks if current salesman has less sales than the current least
            leastSales = man[place].get_sales()[k].getTotalSales(); // refer to salesman.h
            cout << "\tFound slacker: (ID:" << man[place].get_sales()[k].getID() << ") -  " << man[place].get_sales()[k].getName() << endl;
            cout << "\trelocating customers . . ." << endl << endl;
            cout << "   \t" << man[place].get_sales()[k].getName() << " has been fired with only $" << man[place].get_sales()[k].getTotalSales()
            << " sales. \n   \tPlease empty your desk, " << man[place].get_sales()[k].getID() << ", asap!" << endl << endl;
            man[place].distributeClients(k); // refer to manager.h
            man[place].deleteSalesman(k); // refer to manager.h


        }
    }

}
