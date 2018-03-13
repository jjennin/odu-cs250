#include <string>
#include <fstream>
#include <iostream>

using namespace std;

#include "manager.h"
#include "salesmen.h"

/**Default Constructor**/
manager::manager(){}

/// reads in managerList from file
void manager::read(istream& in){
    in >> ID;
    string name;
    char line;
    in >> line >> name;
    fName = line + name;
    in >> lName;
    in >> salary;
    readS(in, m_sales, 5);
}

/// accessor to run readin managerList from file
void read (istream& in, managerList& mans, int counter){
    mans.clear();
    for (int i = 0; i < counter; i++){
        manager m;
        m.read(in);
        mans.push_back(m);
    }
}
/// deletes salesman in specified location
void manager::deleteSalesman(int place){
    m_sales.erase(m_sales.begin()+place);
}
/// redistributes clients
void manager::distributeClients(int place){
    unsigned unsignedPlace = place;
    double lowestSales = m_sales[0].getTotalSales();
    for(int i = 0; i < m_sales[0].getClientsSize(); i++){
        for(unsigned k = 0; k < m_sales.size(); k++){
            if(m_sales[k].getTotalSales() < lowestSales && k!=unsignedPlace){
                lowestSales = m_sales[k].getTotalSales();
                m_sales[k].addclient(m_sales[place].get_clients()[i]);
                m_sales[place].removeclient(i);

            }

        }
    }
}

