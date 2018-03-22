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
    int getID()
    {
        return id;
    }
    void setID(int const& val)
    {
        id = val;
    }
    std::string getDiseaseName()
    {
        return disease_name;
    }
    void setDiseaseName(std::string const& val)
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
