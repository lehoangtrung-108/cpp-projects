#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>

#define MAXWORDS 30
#define MAXLENGTH 20

using namespace std;
int main() 
{
    int RetVal = 0;

    fstream TextFile;
    TextFile.open("ReservedWordList.txt", ios::in);
    if (TextFile.fail()) 
    {
        cout << "Warning: Unable to open the file.\n";
        cout << ">>>> You should take more time to check your Text File\n";
        RetVal = 9;

    }

    char Words[MAXWORDS][MAXLENGTH];
    char Holder[MAXLENGTH];
    int LCount, firstLoop, secondLoop;
    bool didSwap, hasNumericElement = false, firstCharacter = true;

    
    

    for (LCount = 0; LCount < MAXWORDS; LCount++) 
    {
        Words[LCount][0] = '\0';
    }

    for (LCount = 0; LCount < MAXWORDS; LCount++) 
    {
        TextFile >> Words[LCount];                  // The same as: itemRead = fscanf(TextFile, "%s", Words[LCount])
        if (TextFile.eof())          
        {
            break;
        }
        
        firstCharacter = isalpha(Words[LCount][0]);
        if (firstCharacter == false) 
        {
            cout << "\n !!!! Warning: Numeric element found at the beginning of any word in your array. !!!!\n";
            cout << ">>>> Please check your array in Text File again <<<<\n\n";
            hasNumericElement = true;
            RetVal = 3;
        }
    }
   
    if (hasNumericElement == false) 
    {
        cout << "----Here are the words before sorting----\n";
        for (LCount = 0; LCount < MAXWORDS; LCount ++) 
        {
            if (Words[LCount][0] != '\0') 
            {
                cout << Words[LCount] << endl;
            }
        }

        for (firstLoop = 0; firstLoop < MAXWORDS - 1; firstLoop ++) 
        {
            didSwap = false;
            for (secondLoop = 0; secondLoop < MAXWORDS - firstLoop - 1; secondLoop ++) 
            {
                if (strcmp(Words[secondLoop], Words[secondLoop + 1]) > 0) 
                {
                    strcpy(Holder, Words[secondLoop]);
                    strcpy(Words[secondLoop], Words[secondLoop + 1]);
                    strcpy(Words[secondLoop + 1], Holder);
                    didSwap = true;
                }
            }
            if (didSwap == false) 
            {
                break;
            }
        }
    

    cout << "----Here are the words after sorting----\n";
    for (LCount = 0; LCount < MAXWORDS; LCount++) 
    {
        if (Words[LCount][0] != '\0') 
        {
            cout << Words[LCount] << endl;
        }
    }
    }
    if(TextFile.is_open())          // NOT TextFile.open() - STILL MISSING 'is_'
    {
        TextFile.close();
    }
        return (RetVal);
}
