#include <string>
#include <fstream>
#include <iostream>

using namespace std;

#include "salesmen.h"
#include "clients.h"

/**Default Constructor**/
salesmen::salesmen(){}

/// reads in salesList from file
void salesmen::read(istream& in){
    in >> ID;
    string name;
    char line;
    in >> line >> name;
    fName = line + name;
    in >> lName;
    in >> gender;
    in >> custCount;
    readC(in, s_clients, custCount);
}

/// accessor to run readin salesList from file
void readS(istream& in, salesList& sales, int counter){
    sales.clear();
    for (int i = 0; i < counter; i++){
        salesmen s;
        s.read(in);
        sales.push_back(s);
    }
}

/// Totals up the amount of sales the salesman has
double salesmen::getTotalSales(){
    totalSales = 0.0;
    for(int i = 0; i < custCount; i++){
        totalSales += s_clients[i].getMoney();
    }
    return totalSales;
}

/// removes client by name
void salesmen::removeclient(string fname){
    for(int i = 0; i < custCount; i++){
        if(fname == s_clients[i].getfName()){
            s_clients.erase(s_clients.begin()+i);
        }
    }
}
/// removes client by place
void salesmen::removeclient(int place){
    s_clients.erase(s_clients.begin()+place);

}
