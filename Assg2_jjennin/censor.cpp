#include <iostream>
#include <fstream>
#include <string>
#include "message.h"
#include "sensitiveWords.h"
using namespace std;
//**************************
//Assignment 2 - CS250
//Jason Jennings - 01057777
//**************************
string readMessage (fstream& in);
void readSensitiveWords (fstream& in, int& numSensitiveWords, string sensitiveWords[]);
void censorMessage (string& msg, int numSensitiveWords, string sensitiveWords[]);



int main()
{
    /// Sensitive word counter
  int numSensitiveWords = 0;
  int MaxSensitiveWords = 5000;
  /// InFile /begin
  fstream inFile;
  ofstream outFile;
  string fileName = "input.txt";
  string outFileName = "output.txt";
  inFile.open(fileName.c_str(),ios::in);
    if (!inFile){
        cout << "Failure to open " << fileName << "! Please check the directory!" << endl;
        return 0;
    }
  /// InFile /end
  std::string sensitiveWords[MaxSensitiveWords]; // Creates array of censor words
  readSensitiveWords(inFile,numSensitiveWords,sensitiveWords); // reads more in.
  string msg = readMessage(inFile); // reads message
  censorMessage (msg,numSensitiveWords,sensitiveWords); // censors message.
  /// outFile /begin
  outFile.open(outFileName.c_str(),ios::out);
    if (!outFile){
        cout << "Failure to open " << outFileName << "! Please check the directory!" << endl;
        return 0;
    }
  /// outFile /end
  outFile << msg << flush; // outputs to file
  cout << msg << flush; // outputs to screen
  inFile.close(); // CLOSE inFILE
  outFile.close(); // CLOSE outFILE
  return 0;
}
/*
*censors message in msg
*/
void censorMessage (string& msg, int numSensitiveWords, string sensitiveWords[])
{
  for (int i = 0; i < msg.length(); ++i){
      if (wordBeginsAt(msg, i)){
        string word = extractWord(msg, i);
        if (isSensitive(word,numSensitiveWords,sensitiveWords)){
            censorSentenceAt(msg, i);
        }
	  }
    }
}


/*
*reads sensitive words from file stream in
*/
void readSensitiveWords (fstream& in, int& numSensitiveWords, string sensitiveWords[])
{
  string word;
  while ((in >> word) && (word != "===")){
    addSensitiveWord (word,numSensitiveWords,sensitiveWords);
  }
  getline (in, word);
}

/*
*reads message from file stream in
*/
string readMessage (fstream& in)
{
  string msg;
  string line;
  getline (in, line);
  while (in)
    {
      msg = msg + line + "\n";
      getline (in, line);
    }
  return msg;
}
