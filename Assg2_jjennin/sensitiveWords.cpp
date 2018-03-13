#include <iostream>
#include <fstream>
#include <string>
#include "sensitiveWords.h"
#include "message.h"

/*checks to see if a word is in the list of
*sensitive words
*/
bool isSensitive(string& wordFromMessage, int numSensitiveWords, string sensitiveWords[])
{
  string word = toLowerCase(wordFromMessage);
  for (int i = 0; i < numSensitiveWords; ++i)
    if (word == sensitiveWords[i])
      return true;
  return false;
}

/*
*adds a word to the list of sensitive words, if it is not already
*in the list of Sensitive words
*/
void addSensitiveWord (string& wordFromMessage, int& numSensitiveWords, string sensitiveWords[])
{
  string word = toLowerCase(wordFromMessage);
  if (!isSensitive(word,numSensitiveWords,sensitiveWords))
    {
      sensitiveWords[numSensitiveWords] = word;
      ++numSensitiveWords;
    }
}
