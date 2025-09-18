#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cctype>

#define MAXWORDS 30 
#define MAXLENGTH 20

using namespace std;

int main()
{
    int RetVal = 0;
    fstream inFile;
    inFile.open("ReservedWordList.txt",ios::in);
    if(inFile.fail())
    {
        cout << "Unable to open your TextFile\n" << endl;
        cout << "You should check your name or location of your file carefully\n" << endl;
        RetVal = 9;             // special return at the end

    }

    char Words[MAXWORDS][MAXLENGTH];
    char Holder [MAXLENGTH];
    
    int LCount = 0, firstLoop = 0, secondLoop = 0, wordCount = 0;

    bool firstCharacter = true, hasStrangeElement = false, didSwap; 

    // Read TextFile after successfully opening the TextFile
    for(LCount = 0; LCount < MAXWORDS; LCount ++)
    {   
        Words[LCount][0] = '\0';
    }


    for(LCount = 0; LCount < MAXWORDS; LCount ++)               // After reading data from file, we should analyze the problem immediately
    {
        inFile >> Words[LCount];
    
        if(inFile.eof())
        {
            break;
        }
        wordCount ++;
        
        firstCharacter = isalpha(Words[LCount][0]);
        if(firstCharacter == false)
        {
            cout << "!!! Warning !!!! We found some strange characters at the beginning in a few words in your array, maybe numeric elements\n" << endl;
            hasStrangeElement = true;
            RetVal = 3;         // Other special return

        } 
        if(wordCount > MAXWORDS)
        {
            cout << ">>>> Exceed already <<<<" << endl;
        }
    
    }


    if(hasStrangeElement == false)
    {
        cout << "----Here is our array BEFORE SORTING -----" << endl;
        for(LCount = 0; LCount < MAXWORDS ; LCount ++ )
        {
            if(Words[LCount][0] != '\0')
            {
                cout << "\t" << Words[LCount] << endl;

            }
        }

        cout << "----Here is our array AFTER SORTING ------" << endl;
        for(firstLoop = 0; firstLoop < wordCount - 1; firstLoop ++)
        {
            didSwap = false;
            for(secondLoop = 0; secondLoop < wordCount - firstLoop - 1; secondLoop ++)
            {
                if(strcmp(Words[secondLoop], Words[secondLoop + 1])  > 0)
                {
                    strcpy(Holder, Words[secondLoop]);
                    strcpy(Words[secondLoop], Words[secondLoop +1]);
                    strcpy(Words[secondLoop +1], Holder);
                    didSwap = true;
                }
                if(didSwap = false)
                {
                    break;
                }
            }
        }

        for(LCount = 0; LCount < MAXWORDS; LCount ++)
        {
            if(Words[LCount][0] != '\0')
            {
                cout << "\t" << Words[LCount] << endl;

            }
        }
    }

    if(inFile.is_open())
    {
        inFile.close();

    }
    return(RetVal);
}