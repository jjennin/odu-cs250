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
    int getID()
    {
        return id;
    }
    void setID(int const& val)
    {
        id = val;
    }
    int getDay()
    {
        return day;
    }
    void setDay(int const& val)
    {
        day = val;
    }
    int getMonth()
    {
        return month;
    }
    void setMonth(int const& val)
    {
        month = val;
    }
    int getYear()
    {
        return year;
    }
    void setYear(int const& val)
    {
        year = val;
    }
    int getHour()
    {
        return hour;
    }
    void setHour(int const& val)
    {
        hour = val;
    }
    int getMinute()
    {
        return minute;
    }
    void setMinute(int const& val)
    {
        minute = val;
    }
    char getAMPM()
    {
        return AM_PM;
    }
    void setAMPM(char const& val)
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
