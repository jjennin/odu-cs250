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
    int Getid()
    {
        return id;
    }
    void Setid(int val)
    {
        id = val;
    }
    std::string Getusername()
    {
        return username;
    }
    void Setusername(std::string val)
    {
        username = val;
    }
    std::string Getpassword()
    {
        return password;
    }
    void Setpassword(std::string val)
    {
        password = val;
    }
    std::string Getname()
    {
        return name;
    }
    void Setname(std::string val)
    {
        name = val;
    }
    std::string Getphone()
    {
        return phone;
    }
    void Setphone(std::string val)
    {
        phone = val;
    }
    std::string Getskill()
    {
        return skill;
    }
    void Setskill(std::string val)
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
