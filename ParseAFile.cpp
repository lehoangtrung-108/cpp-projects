#include <iostream>
#include <cctype>
#include <fstream>

using namespace std;

int main()
{
    int RetVal = 0;
    ifstream inFile ("ReservedWordList.txt");
    if(inFile.fail())
    {
        cout << "Unable to open our Text File to parse\n";
        cout << "You should check your name or location of file just in case\n";
        RetVal = 9;
    }
    else
    {
        char thisByte;
        char thisWord[20];          // Forget to create the size for string

        int wordIndex = 0;
        int wordStarted = 0;

        bool GotIt = true;
        bool CheckLetter = true;
        bool CheckSpace = true;
        bool CheckPunct = true;

        while (GotIt == true)
        {
            thisByte = inFile.get();

            CheckLetter = isalpha(thisByte);
            CheckSpace = isspace(thisByte);
            CheckPunct = ispunct(thisByte);


            if(CheckLetter == true)
            {
                thisByte = tolower(thisByte);
                thisWord[wordIndex++] = thisByte;
                wordStarted = 1;
            }
            else if(CheckSpace == true)
            {
                if(wordStarted > 0)
                {
                    thisWord[wordIndex] = '\0';
                    cout << thisWord << "\n";
                    wordIndex = 0;
                    wordStarted = 0;
                
                }
            }
            else if(CheckPunct == true)
            {
                if(thisByte == '\'' || thisByte == '-')
                {
                    // Doing nothing
                }
                else if(wordStarted > 0)
                {
                    thisWord[wordIndex] = '\0';
                    cout << thisWord << "\n";
                    wordIndex = 0;
                    wordStarted = 0;
                }

            }
            else if(inFile.eof())
            {
                if(wordStarted > 0)
                {
                    thisWord[wordIndex] = '\0';
                    cout << thisWord;           // print the last word in our file
                }
            }

    

        }
   

    }
    if (inFile.is_open())
    {
        inFile.close();
    }
    return(RetVal);
}