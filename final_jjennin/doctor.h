#ifndef DOCTOR_H
#define DOCTOR_H
#include <iostream>
#include <string>
#include <vector>


class doctor
{
private:
    int id;
    std::string username;
    std::string password;
    std::string name;
    std::string phone;
    std::string skill;
public:
    doctor();
    int getID()
    {
        return id;
    }
    void setID(int const& val)
    {
        id = val;
    }
    std::string getUsername()
    {
        return username;
    }
    void setUsername(std::string const& val)
    {
        username = val;
    }
    std::string getPassword()
    {
        return password;
    }
    void setPassword(std::string const& val)
    {
        password = val;
    }
    std::string getName()
    {
        return name;
    }
    void setName(std::string const& val)
    {
        name = val;
    }
    std::string getPhone()
    {
        return phone;
    }
    void setPhone(std::string const& val)
    {
        phone = val;
    }
    std::string getSkill()
    {
        return skill;
    }
    void setSkill(std::string const& val)
    {
        skill = val;
    }
    void read(std::ifstream&); /// readin doctorList from file
    void display();
    void updateEntry();
    void add();
};

/** typedef vector of doctor type **/
typedef std::vector<doctor> doctorList;
/// accessor to run readin patientList from file
void read (std::ifstream&,doctorList&);
int searchEntries(doctorList,std::string);
void showAllEntries(doctorList&);
void addEntry(doctorList&);
void deleteEntry(doctorList&,int);

#endif // DOCTOR_H
