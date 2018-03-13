#ifndef SENSITIVEWORDS_H_INCLUDED
#define SENSITIVEWORDS_H_INCLUDED
using namespace std;

bool isSensitive(string& wordFromMessage, int numSensitiveWords, string sensitiveWords[]); // Checks from list of words for if sensitive
void addSensitiveWord (string& wordFromMessage, int& numSensitiveWords, string sensitiveWords[]); // Adds new word.

#endif // SENSITIVEWORDS_H_INCLUDED
