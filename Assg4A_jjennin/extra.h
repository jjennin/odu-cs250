#ifndef EXTRA_H_INCLUDED
#define EXTRA_H_INCLUDED
#include <string>
using namespace std;

///Easy date store struct
struct Date{
	int day;
	int month;
	int year;
};
///Easy size of box struct
struct SizeOfBox{
    int length;
    int	width;
    int height;
};
/// prints header
void printHeading(string title, int width);



#endif // EXTRA_H_INCLUDED
