#include <iostream>
#include <list>
#include <stdlib.h>
#include <iomanip>
#include <time.h>
using namespace std;

struct contact {
    string fname = "Noone";
    string lname = "Noone";
    double phone = 0;
    string address = "No Where";
    string notes = "Nothing";
};

int main()
{
    list<int> integers;
    list<float> floaters (1000,78.15);
    list<string> stringers;
    list<contact> contacts;
    list<int>::iterator it;
    list<int>::iterator it3;
    list<int>::iterator it4;
    list<string>::iterator it2;
    srand(time(0));
//    integers.insert(integers.begin(),10);
//    it = integers.begin();
//
//    cout << *it;
    string k;
    cout << "Generating integers between 1 and 6 in list integers . . ." << endl;
    for(int i = 1; i < 7; i++){
        integers.push_back(i);
    }
    cout << "Generating strings between A and F in list stringers . . ." << endl;
    cout << endl;
    for(char ks = 65; ks < 71; ks++){
        k = "";
        k = k + ks;
        stringers.push_back(k);
    }
    cout << "Displaying integers . . ." << endl;
    for(it = integers.begin(); it != integers.end(); it++){
        cout << *it << "  ";
    }
    cout << endl;
    cout << "Displaying stringers . . ." << endl;
    for(it2 = stringers.begin(); it2 != stringers.end(); it2++){
        cout << *it2 << "  ";
    }
    cout << endl;
    cout << endl;

    cout << "Added 0 to the end of integers . . ." << endl << "Added 15 to the end of integers list . . ." << endl;
    integers.push_front(0);
    integers.push_back(15);
    cout << "Displaying integers . . ." << endl;
    for(it = integers.begin(); it != integers.end(); it++){
        cout << *it << "  ";
    }
    cout << endl;
    cout << endl;

    int stringersMiddle = (stringers.size()/2);
    string name = "Jason";
    it2 = stringers.begin();
    advance(it2,stringersMiddle);
    cout << "Inserting " << name << " into stringers position " << stringersMiddle << " . . ." << endl;
    stringers.insert(it2,name);
    cout << "Displaying stringers . . ." << endl;
    for(it2 = stringers.begin(); it2 != stringers.end(); it2++){
        cout << *it2 << "  ";
    }
    cout << endl << endl;
    cout << "Adding 2 to the first integer in the list and subtracting 4 from the last . . ." << endl;
    integers.front() = integers.front() + 2;
    integers.back() = integers.back() - 4;

    cout << "Displaying integers . . ." << endl;
    for(it = integers.begin(); it != integers.end(); it++){
        cout << *it << "  ";
    }
    string temp;
    char letter;
    contact tempContact;

    for(int i = 0; i < 500; i++){
    tempContact.fname = "";
    tempContact.lname = "";
    tempContact.phone;
        for(int i = 0; i < 1; i++){
            letter = rand()%24+65;
            tempContact.fname = tempContact.fname + letter;
        }
        for(int i = 0; i < 4; i++){
            letter = rand()%24+97;
            tempContact.fname = tempContact.fname + letter;
        }
        for(int i = 0; i < 1; i++){
            letter = rand()%24+65;
            tempContact.lname = tempContact.lname + letter;
        }
        for(int i = 0; i < 4; i++){
            letter = rand()%24+97;
            tempContact.lname = tempContact.lname + letter;
        }
        for(int i = 0; i < 7; i++){
            tempContact.phone = rand()%10000000+7571111111;
        }
        contacts.push_back(tempContact);
//        cout << contacts.back().fname << " " << contacts.back().lname << " ";
//        cout << fixed << setprecision(0) << contacts.back().phone << " " << contacts.back().notes << " " << contacts.back().address << endl;

    }

    cout << endl << endl;
    integers.sort();
    cout << "Sorting integers . . ." << endl;
    cout << "Displaying integers . . ." << endl;
    for(it = integers.begin(); it != integers.end(); it++){
        cout << *it << "  ";
    }
    cout << endl << endl;
    integers.reverse();
    cout << "Reversing integers . . ." << endl;
    cout << "Displaying integers . . ." << endl;
    for(it = integers.begin(); it != integers.end(); it++){
        cout << *it << "  ";
    }

    return 0;
}
