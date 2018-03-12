#include "date_time.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

// Default constructor
Date_Time::Date_Time()
{
    id = 0;
    day = 0;
    month = 0;
    year = 0;
    hour = 0;
    minute = 0;
    AM_PM = 'A';
}

// reads in slotList from file
void Date_Time::read(ifstream& in)
{
    in >> id
       >> month
       >> day
       >> year
       >> hour
       >> minute
       >> AM_PM;
    if(year > 2000)
    {
        year -= 2000;
    }
    AM_PM = std::toupper(AM_PM);

}


// accessor to run readin slotList from file
void read (ifstream& in, date_timeList& dtList)
{
    in.open("Date_Time.txt");
    if(!in)
    {
        cout << "Failed to open datefile file" << endl;
    }
    else
    {
        dtList.clear();
        int c;
        in >> c;
        for (int i = 0; i < c; i++)
        {
            Date_Time dt;
            dt.read(in);
            dtList.push_back(dt);
        }
    }
}

// display for datetime
void Date_Time::display()
{
    cout << "Date: " << month
         << "/" << day
         << "/" << year
         << " Time: " << hour
         << ":" << minute
         << " " << AM_PM;
}
// add new date
void Date_Time::add()
{
    char g;
    cout << "(MM/DD/YY): ";
    cin >> month >> g >> day >> g >> year;
    while(month > 12 || month < 1 || day > 31 || day < 1 || year < 0 || year > 99)
    {
        cout << "Please enter a valid date (MM/DD/YY): ";
        cin >> month >> g >> day >> g >> year;
    }
    cout << "(HH:MM A/P): ";
    cin >> hour >> g >> minute >> AM_PM;
    while((hour > 12 || hour < 1 || minute > 60 || minute < 0) && (AM_PM != 'A' || AM_PM != 'P'))
    {
        cout << "Please enter a valid time (HH:MM A/P): ";
        cin >> hour >> g >> minute >> AM_PM;
    }
}
