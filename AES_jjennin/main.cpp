#include <iostream>
#include <string>
#include <sstream>

using namespace std;
string converttobinary(char c);

int main()
{
    cout << "Hello world!" << endl;
    cout << converttobinary('a');
    return 0;
}

string converttobinary(char c)
{
    string s = "";
    ostringstream ss;
    ss.clear();
	int bits[8], i;


	for(i = 0; i < 8; i++)
		bits[i] = ((1<<i) & c) != 0 ? 1:0;
	for(i = 7; i >= 0; i--){
        ss << bits[i];
		s = s + ss.str();
	}
    return s;
}
