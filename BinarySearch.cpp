#include <iostream>
#include <cstring>          // use for strcmp, strcpy
#include <cctype>
#include <limits>
#include <fstream>      // !!!!!! use for fstream or ifstream


#define MAXWORDS 30
#define MAXLENGTH 20
using namespace std;

int main()
{
    int RetVal = 0;

    ifstream TextFile("ReservedWordList.txt");
    /*******************
     * 
     *  or:
     * fstream TextFile("ReservedWordList.txt", ios::in;
     */
    if(TextFile.fail())
    {
        cout << "Unable to open Text File\n";
        cout << "You should check your file name or location that you placed before\n ";

        RetVal = 9;

    }
    else
    {
    char Words[MAXWORDS][MAXLENGTH];
    char Holder[MAXLENGTH];

    int LCount = 0, firstLoop = 0, secondLoop = 0, wordCount = 0;
    
    bool firstCharacter = true, hasStrangeElement = false, didSwap; 
    char Target [MAXLENGTH];
    
    int Top = 0, Middle, Bottom = wordCount - 1, Exit, BiComparison, binaryCompares = 0;
    bool GotIt = true, foundBinary = false;







    for(LCount = 0; LCount < MAXWORDS; LCount ++)
    {
        Words[LCount][0]  = '\0';
    }



    
    while(TextFile >> Words[wordCount])                          // As same as 'fscanf' in C  : fscanf(TextFile,"%d", Words[LCount])
    {
            
        firstCharacter = isalpha(Words[wordCount][0]);
        if(firstCharacter == false)
        {
            cout << "!!!! Warning !!!! We found some words get started with other characters, maybe numeric elements\n";
            cout << "You should take time to check your array in your text file again\n";
            RetVal = 3;
            hasStrangeElement = true;
                
        }
        wordCount ++;
            
        if (wordCount >= MAXWORDS)
        {
            cout << "Exceed word maximum that we defined before\n";
            RetVal = 2;
            break;
        }
            
        if(TextFile.eof())
        {
            break;
        }
            

    }
    if (hasStrangeElement == false && wordCount < MAXWORDS)
    {
        cout << "----Here is our array BEFORE SORTING-----\n";
        for (LCount = 0; LCount < wordCount; LCount++)
        {
            if (Words[LCount][0] != '\0')
            {
                cout << "\t" << Words[LCount] << "\n";
            }
        }
            
            
        cout << "----Here is our array AFTER SORTING---- \n";
        for (firstLoop = 0; firstLoop < wordCount - 1; firstLoop++)
        {
                didSwap = false;
            for (secondLoop = 0; secondLoop < wordCount - firstLoop - 1; secondLoop++)
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

        for (LCount = 0; LCount < wordCount; LCount++)
        {
            if (Words[LCount][0] != '\0')
            {
                    cout << "\t" << Words[LCount] << "\n";
            }
        }
        for (LCount = 0; LCount < wordCount; LCount++)
        {
            if (Words[LCount][0] >= 'A' && Words[LCount][0] <= 'Z')
            {
                Words[LCount][0] = tolower(Words[LCount][0]);
            }
        }





            // BINARY SEARCH

        while (GotIt == true)
        {
            cout << "Enter any word in our array (or type 'exit' to quit) => ";
            cin >> Target;

            Target[0] = tolower(Target[0]);

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                RetVal = 4;
            }

                Exit = strcmp(Target, "exit");
                if (Exit == 0)
                {
                    cout << "\n\tExiting ---> @Loading ---> Successful\n";
                    break; // I forgot to put 'break' in this step
                }

                // Reset variable for each time of looping
                binaryCompares = 0;
                Top = 0;
                Bottom = wordCount - 1;
                foundBinary = false;

                while (Top <= Bottom) // while, NOT 'if' in this step
                {
                    binaryCompares++;
                    Middle = Top + (Bottom - Top) / 2;
                    BiComparison = strcmp(Words[Middle], Target);
                    if (BiComparison == 0)
                    {
                        foundBinary = true;
                        RetVal = 0;
                        break;
                    }
                    else if (BiComparison < 0)
                    {
                        Top = Middle + 1;
                    }
                    else
                    {
                        Bottom = Middle - 1;
                    }
                }
                /********************************************
                 * This part should be outside of WHILE LOOP OF (TOP <= BOTTOM)
                 ********************************************/
                if (foundBinary)
                {
                    cout << "We found " << Target << " at index " << Middle << "  (binary search: " << binaryCompares << ")\n";
                }
                else
                {
                    cout << "Cannot find " << Target << ". Try again"
                         << "\n";
                }
            }
        }
    }


    

    if(TextFile.is_open())
    {
        TextFile.close();

    }
    
    return(RetVal);
    
}