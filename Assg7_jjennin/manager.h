#ifndef MANAGER_H
#define MANAGER_H
#include <iostream>
#include <string>
#include <vector>
#include "salesmen.h"

class manager
{
    std::string fName, lName;
    int ID, salary;
    salesList m_sales;
public:
    /** Default constructor */
    manager();

    /// SETTERS
    void setfName(string first){fName = first;} /// sets first name for manager
    void setlName(string last){lName = last;} /// sets last name for manager
    void setID(int iID){ID = ID;} /// sets id for manager
    void setSalary(int isalary){salary = isalary;} /// sets salary for manager

    /// GETTERS
    std::string getfName(){return fName;} /// outputs first name of manager
    std::string getlName(){return lName;} /// outputs last name of manager
    std::string getName(){return (fName+" "+lName);} /// outputs full name of manager
    int getID(){return ID;} /// outputs Id for manager
    int getSalary(){return salary;} /// outputs the salary for manager
    int getSalesSize() {return m_sales.size();} /// outputs the size of salesmen vector
    salesList& get_sales() {return m_sales;} /// outputs the salesmen for manager

    /// FUNCTIONS
    void deleteSalesman(int place); /// deletes salesman in specified location
    void distributeClients(int place); /// redistributes clients
    void read(std::istream& in); /// readin managerList from file



};

/** typedef vector of manager type **/
typedef std::vector<manager> managerList;
/// accessor to run readin managerList from file
void read (std::istream& in, managerList& mans, int counter);

#endif // MANAGER_H
