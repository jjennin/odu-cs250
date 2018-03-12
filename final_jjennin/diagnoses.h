#ifndef DIAGNOSES_H
#define DIAGNOSES_H
#include <iostream>
#include <string>
#include <vector>

class diagnoses
{
private:
    int id;
    std::string disease_name;
public:
    diagnoses();
    int Getid()
    {
        return id;
    }
    void Setid(int val)
    {
        id = val;
    }
    std::string Getdisease_name()
    {
        return disease_name;
    }
    void Setdisease_name(std::string val)
    {
        disease_name = val;
    }
    void read(std::ifstream&,int); /// readin diagnosesList from file
    void display();
};

/** typedef vector of diagnoses type **/
typedef std::vector<diagnoses> diagnosesList;

/// accessor to run readin diagnosesList from file
void read (std::ifstream&, diagnosesList&);

int searchEntries(diagnosesList,std::string);

#endif // DIAGNOSES_H
