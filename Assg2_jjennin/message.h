#ifndef MESSAGE_H_INCLUDED
#define MESSAGE_H_INCLUDED
using namespace std;

void censorSentenceAt (string& msg, int pos); // Finds where to censor sentence
string extractWord (const string& fromMessage, int beginningAt); // Grabs individual words out of a string.
bool wordBeginsAt (const string& message, int pos); // Makes sure its the beginning of a word
string toLowerCase (string word); // Ensures no issues with caps.

#endif // MESSAGE_H_INCLUDED
