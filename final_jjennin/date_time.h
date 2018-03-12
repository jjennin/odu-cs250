#ifndef DATE_TIME_H
#define DATE_TIME_H
#include <iostream>
#include <string>
#include <vector>


class Date_Time
{
private:
    int id;
    int day;
    int month;
    int year;
    int hour;
    int minute;
    char AM_PM;
public:
    Date_Time();
    int Getid()
    {
        return id;
    }
    void Setid(int val)
    {
        id = val;
    }
    int Getday()
    {
        return day;
    }
    void Setday(int val)
    {
        day = val;
    }
    int Getmonth()
    {
        return month;
    }
    void Setmonth(int val)
    {
        month = val;
    }
    int Getyear()
    {
        return year;
    }
    void Setyear(int val)
    {
        year = val;
    }
    int Gethour()
    {
        return hour;
    }
    void Sethour(int val)
    {
        hour = val;
    }
    int Getminute()
    {
        return minute;
    }
    void Setminute(int val)
    {
        minute = val;
    }
    char GetAM_PM()
    {
        return AM_PM;
    }
    void SetAM_PM(char val)
    {
        AM_PM = val;
    }
    void read(std::ifstream&); /// readin DateTimeList from file
    void display();
    void add();

};

/** typedef vector of date_time type **/
typedef std::vector<Date_Time> date_timeList;

/// accessor to run readin date_timeList from file
void read (std::ifstream&, date_timeList&);
bool operator>(const Date_Time&, const Date_Time&);

#endif // DATE_TIME_H
