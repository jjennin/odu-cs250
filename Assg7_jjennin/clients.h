#ifndef CLIENTS_H
#define CLIENTS_H
#include <iostream>
#include <string>
#include <vector>
#include "clients.h"

class clients
{
    std::string fName, lName;
    double money;
public:
    clients();

    /// SETTERS
    void setfName(string first){fName = first;} /// sets first name for client
    void setlName(string last){lName = last;} /// sets last name for client
    void setMoney(double imoney){money = imoney;} /// sets last name for client

    /// GETTERS
    std::string getfName(){return fName;} /// gets first name for client
    std::string getlName(){return lName;} /// gets last name for client
    std::string getName(){return (fName+" "+lName);} /// gets full name
    double getMoney(){return money;} /// gets money

    /// FUNCTIONS
    void read(std::istream& in); /// reads in clients from file into vector


};

/** typedef vector of clients type **/
typedef std::vector<clients> clientList;
/// accessor to run readin clientList from file
void readC (std::istream& in, clientList& inClients, int counter);

#endif // CLIENTS_H
