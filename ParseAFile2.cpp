#include <iostream>
#include <cctype>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    char thisByte;
    string thisWord;        // We use string, not char

    int RetVal = 0;
    
    bool wordStarted = 0; 
    bool CheckLetter = true;
    bool CheckSpace = true;
    bool CheckPunct = true;
    bool hasMoreCharacter;

    ifstream inFile("ReservedWordList.txt");
    if(inFile.fail())
    {
        cout << "Unable to open your Text File\n";
        cout << "You should check your name (without space) or location that you put in Document\n";
        RetVal = 9;

    }
    else
    {
      
        while(inFile.get(thisByte))
        {
            CheckLetter = isalpha(thisByte);
            CheckSpace = isspace(thisByte);
            CheckPunct = ispunct(thisByte);

            if(CheckLetter == true)
            {
                thisByte = tolower(thisByte);
                thisWord += thisByte;           // Append (nối thêm vào) thisByte to string thisWord
                wordStarted = true;
            }
            else if(CheckSpace == true)
            {
                if(wordStarted == true)
                {
                    // We don't need to put \0 at the end because we already declare 'string' for thisWord above
                    cout << thisWord <<"\n";
                    thisWord.clear();
                    wordStarted = false;
                   
                }
            }
            else if(CheckPunct == true)
            {
                if(thisByte == '\'' || thisByte == '-') 
                {
                    // doing nothing if we encounter apostrophe (..') or hyphen (-)
                }
                else if(wordStarted == true)
                {
                    cout << thisWord << "\n";
                    thisWord.clear();
                    wordStarted = false;
                }
            }
        }
        // Print the last word whenever we encounter EOF
        if(wordStarted == true)
        {
            cout << thisWord << endl;
            
        }
        cout << ">>>>> That's all we can parse in your Text File <<<<<<" << endl;
    }

    if(inFile.is_open())
    {
        inFile.close();
    
    }
    return(RetVal);

}