#include <string>
#include <fstream>
#include <iostream>

using namespace std;

#include "clients.h"

/** Default Constructor **/
clients::clients(){
}

/// Reads in clients from file to vector clientList
void clients::read(istream& in){
    string name;
    char line;
    in >> line >> name;
    fName = line + name;
    in >> lName;
    in >> money;
}

/// accessor for read-in to clientList
void readC (istream& in, clientList& cli, int counter){
    cli.clear();
    for (int i = 0; i < counter; i++){
        clients c;
        c.read(in);
        cli.push_back(c);
    }
}
