#include <iostream>
#include <iomanip>

using namespace std;
void isALeapYear(int year, bool& leapyear);
void dateIsValid (int year, int month, int day, bool& validInput);
int numberOfDaysInMonth(int month, int year);
void dayOfTheYear(int year, int month, int day);

int main()
{
    int month=0, day=0, year=0, dayNum=0, sum=0;
    bool leapyear, valid;
    char garbage;
    cout << "***** Assignment 0 ******" << endl;
    cout << "**** Jason Jennings *****" << endl;
    cout << "Enter a date in the form YYYY-MM-DD: ";
    cin >> year >> garbage >> month >> garbage >> day;
    dateIsValid(year, month, day, valid);
    if(valid == true){
    dayOfTheYear(year,month,day);
    }

}

void isALeapYear(int year, bool& leapyear){
    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)){
            leapyear = true;
            cout << "This is a leap year!" << endl;
    }
    else {
            leapyear = false;
    }
}
void dateIsValid (int year, int month, int day, bool& validInput){
        if (year < 1582)
			validInput= false;
		else if (year == 1582 && month < 10)
			validInput = false;
		else if (year == 1582 && month == 10 && day < 15)
			validInput = false;
		// Months must be in the range 1..12
		else if (month < 1 || month > 12)
			validInput = false;
		else
            validInput = true;
		if (!validInput)
		{
			cout << "Sorry, that is not a valid date" << endl;
			string garbage;
			getline (cin, garbage); // discard the rest of the input line
		}
}
int numberOfDaysInMonth(int month, int year){
// Days must be in the range 1..K where K is the number of
		// days in that month.
            bool leapyear;
            isALeapYear(year,leapyear);

			int numDaysMonth = 0;
			switch (month)
			{
				case 1:
				case 3:
				case 5:
				case 7:
				case 8:
				case 10:
				case 12:
					numDaysMonth = 31;
					break;
				case 4:
				case 6:
				case 9:
				case 11:
					numDaysMonth = 30;
					break;
				case 2:
                    if(leapyear == true){
                        numDaysMonth = 29;
                    }
                    else {
                        numDaysMonth = 28;
                    }
			}
			return numDaysMonth;
}
void dayOfTheYear(int year, int month, int day){
    int sum = 0;
	for (int m = 1; m < month; ++m)
	{
		int monthLength = numberOfDaysInMonth(m,year);


		sum += monthLength;
	}
	int dayNum = sum + day;
	cout << setw(2) << setfill('0') << month
			 << "/" << setw(2) << setfill('0') << day << "/"
			 << setw(4) << year;
	cout << " is day #" << dayNum << " of that year." << endl;

}
