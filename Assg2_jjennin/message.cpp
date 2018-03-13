#include <iostream>
#include <fstream>
#include <string>
#include "message.h"

/*
*returns a string converted to lowercase
*/
std::string toLowerCase (std::string word)
{
  string result = word;
  for (int i = 0; i < word.length(); ++i)
    if (word[i] >= 'A' && word[i] <= 'Z')
      result[i] = result[i] + 'a' - 'A';
  return result;
}

/*
*Return true if char is alpha numeric
*/
bool isAlphanumeric (char c)
{
  return (c >= 'A' && c <= 'Z')
    || (c >= 'a' && c <= 'z')
    || (c >= '0' && c <= '9');
}

/*
*returns true if character is punctuation
*/
bool sentencePunctuation (char c)
{
  return c == '.' || c == '?' || c == '!';
}



/*
 * Return true if the character at position pos is the first character
 * of a word.
 */
bool wordBeginsAt (const std::string& message, int pos)
{
if(pos == 0){ // If at beginning of paragraph, instant word.
    return true;
  }

  if(!isAlphanumeric(message[pos-1]) || sentencePunctuation(message[pos-1])){ // Ensures that other options are included in word count.
    return true;
  }
  else{
    return false;
  }
}


/*
 * Return the word that begins at
 * position beginningAt as a string
 */
std::string extractWord (const std::string& fromMessage, int beginningAt)
{
  int i = 0;
  while (((beginningAt + i) < fromMessage.length()) && (isAlphanumeric(fromMessage[beginningAt + i]))){
    i++;
  }
  string result = fromMessage.substr(beginningAt, i);
  return result;
}

/*
 * Returns true if pos is the index of the beginning of the message
 *or if pos is the index of the beginning of a paragraph.
 */
bool paragraphStart  (const string& msg, int pos)
{
  if (pos == 0)
    return true;
  if (pos == 1)
    return false;
  return msg[pos-1] == '\n' && msg[pos-2] == '\n';
}


/*
 * Returns the index of the first character of the sentence containing
 *the index pos
 */
int findSentenceStart (const string& msg, int pos)
{
  while (pos > 0 && !paragraphStart(msg,pos) && !sentencePunctuation(msg[pos]))
    --pos;
  if (sentencePunctuation(msg[pos]))
    ++pos;
  return pos;
}

/*returns true if the index pos has reached the end of a paragraph
*or the end of the message
*/
bool paragraphEnd  (const string& msg, int pos)
{
  if (pos == msg.length())
    return true;
  if (pos == msg.length()-1)
    return false;
  return msg[pos] == '\n' && msg[pos+1] == '\n';
}



/*
 * Returns the index of the last character of the sentence
 *containing the index of pos
 */
int findSentenceStop (const string& msg, int pos)
{
  while (pos < msg.length()
	 && !paragraphEnd(msg,pos)
	 && !(pos > 0 && sentencePunctuation(msg[pos-1])))
    ++pos;
  return pos;
}


/*
 * Replace all characters of a sentence containing the index pos with '@'
 * except for '/n'.
 */
void censorSentenceAt (string& msg, int pos)
{
  int endp = findSentenceStart(msg, pos);
  int start =  findSentenceStop(msg, pos);
  for(int i = endp; i < start; ++i){
    if(msg[i] != '\n'){
        msg[i] = '@';
    }
  }
}

