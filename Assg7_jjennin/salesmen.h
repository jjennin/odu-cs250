#ifndef SALESMEN_H
#define SALESMEN_H
#include <iostream>
#include <string>
#include <vector>
#include "clients.h"

class salesmen
{
    std::string fName, lName, gender;
    int ID,custCount;
    clientList s_clients;
    double totalSales;
public:
    /** Default constructor */
    salesmen();

    /// SETTERS
    void setfName(string first){fName = first;} /// sets first name for salesman
    void setlName(string last){lName = last;} /// sets last name for salesman
    void setID(int iID){ID = ID;} /// sets id for salesman
    void setGender(int iGender){gender = iGender;} /// sets gender for salesman

    /// GETTERS
    std::string getfName(){return fName;} /// returns first name
    std::string getlName(){return lName;} /// returns last name
    std::string getName(){return (fName+" "+lName);} /// returns full name
    std::string getGender(){return gender;} /// returns gender
    int getID(){return ID;} /// returns ID
    clientList& get_clients() {return s_clients;} /// returns entire client list for salesman
    int getClientsSize() {return s_clients.size();} /// displays client size (vector size)
    double getTotalSales(); /// displays total sales for salesman

    /// FUNCTIONS
    void addclient(clients x){s_clients.push_back(x); custCount++;}; /// Adds client to end of vector
    void removeclient(string fname); /// removes client by name
    void removeclient(int place); /// removes client by place
    void read(std::istream& in); /// readin salesList from file


};

/** typedef vector of salesmen type **/
typedef std::vector<salesmen> salesList;
/// accessor to run readin salesList from file
void readS(std::istream& in, salesList& sales, int counter);

#endif // SALESMEN_H
