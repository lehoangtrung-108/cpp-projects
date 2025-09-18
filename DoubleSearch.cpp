#include <iostream>
#include <cstring>
#include <fstream>
#include <limits>
#include <cctype>

#define MAXWORDS 50
#define MAXLENGTH 20

using namespace std;

int main()
{
    int RetVal = 0;
    ifstream TextFile ("ReservedWordList.txt");
    if(TextFile.fail())
    {
        cout << "Unable to open Text File\n";
        cout << "You should ensure your file has proper name or put in the right place so that we can open easily\n";

        RetVal = 9;

    }
    else
    {
        // Declare variables
        char Words[MAXWORDS][MAXLENGTH];
        char Holder[MAXLENGTH];

        int LCount = 0, firstLoop = 0, secondLoop = 0, wordCount = 0;

        bool firstCharacter = true, hasStrangeElement = false, didSwap = false;


        // Avoid non-string elements in our array to easily print all eventually
        for(LCount = 0; LCount < MAXWORDS; LCount ++)
        {
            Words[LCount][0] = '\0';
        }


        while(TextFile >> Words[wordCount])
        {
            firstCharacter = isalpha(Words[wordCount][0]);
            if(firstCharacter == false)
            {
                cout << "!!! Warning !!! We found some words got started with strange characters, maybe numeric ones\n";
                cout << "We just accept our WORD array for this assignment\n";
                hasStrangeElement = true;
                RetVal = 2;
                break;
            }
            wordCount ++;

            if(wordCount > MAXWORDS)
            {
                cout << "Exceed the maximum of words that we defined before\n";
                RetVal = 3;
                break;
            }

            if(TextFile.eof())
            {
                break;
            }
        }

        if(hasStrangeElement == false && wordCount <= MAXWORDS)
        {
            

            cout << "----Here is our array BEFORE SORTING----\n";
            for(LCount = 0; LCount < wordCount; LCount ++)
            {
                if(Words[LCount][0] != '\0')
                {
                    cout <<"\t"<< Words[LCount] << "\n";

                }
            }


            
            for(firstLoop = 0; firstLoop < wordCount - 1; firstLoop ++)
            {
                didSwap = false;
                for(secondLoop = 0; secondLoop < wordCount - firstLoop - 1; secondLoop ++)      // !!! Forget add "++" after secondLoop in condition
                {
                    if(strcmp(Words[secondLoop], Words[secondLoop + 1]) < 0)
                    {
                        strcpy(Holder, Words[secondLoop]);
                        strcpy(Words[secondLoop], Words[secondLoop + 1]);
                        strcpy(Words[secondLoop +1], Holder);
                        didSwap = true;
                    }
                }
                if(didSwap == false)
                {
                    break;
                }
            }
            cout << "----Here is our array AFTER SORTING----\n";
            for(LCount = 0; LCount < wordCount; LCount ++)
            {
                if(Words[LCount][0] != '\0')
                {
                    cout <<"\t"<<Words[LCount] << "\n";

                }
            }
            for(LCount = 0; LCount < wordCount; LCount ++)
            {
                if(Words[LCount][0] >= 'A' && Words[LCount][0] <= 'Z')
                {
                    Words[LCount][0] = tolower(Words[LCount][0]);
                }
            }
        

        // Binary Search
        char Target[MAXLENGTH];

        int Top = 0, Bottom = wordCount - 1, Middle, Exit, BiComparison, binaryCompares = 0;


        bool foundBinary = false, GotIt = true;

        while(GotIt == true)
        {
            cout << "Enter any word in our array that you want to find (or type 'exit' to quit): ";
            cin >> Target;
            
            Target[0] = tolower(Target[0]);


            if(cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize> :: max(), '\n');
                RetVal = 4;
            }

            

            Exit = strcmp(Target, "exit");
            if(Exit == 0)
            {
                cout << "\n\tExiting ---- @Loading---- Successful\n";
                break;

            }



            // Reset variables to loop as many times as we want
            binaryCompares = 0;             // !!! Forget this
            Top = 0;
            Bottom = wordCount - 1;
            foundBinary = false;





            while(Top <= Bottom)
            {
                binaryCompares ++;
                Middle = Top + (Bottom - Top) /2;
                BiComparison = strcmp(Words[Middle], Target);
                if(BiComparison == 0)
                {
                    foundBinary = true;
                    RetVal = 0;         // !!! forget this 
                    break;
                }
                else if (BiComparison > 0)                  // !! BiComparison > 0 in this step because it's related to "Top" and "this array is from larger to smaller"
                {
                    Top = Middle + 1;
                    Middle = Top + (Bottom - Top) /2 ;


                }
                else
                {
                    Bottom = Middle - 1;
                    Middle = Top + (Bottom - Top) /2 ;
                
                }
            }
            
            if(foundBinary)
            {
                cout << "We found " << Target << " at index " << Middle << "  (binary search: " << binaryCompares << ")\n";     // index ~ Middle 
            }
            else
            {
                cout << Target << " cannot be found in our array\n";
                cout << "\t\t >>>>> Try again <<<<<<<<\n";
            }

            // Declare variable for Sequential Search
            int SeComparison, sequentialCompares = 0;
            bool foundSequential = false;

            // Reset variables
            sequentialCompares = 0;
            foundSequential = false;

            for(LCount = 0; LCount < wordCount && GotIt == true; LCount ++)
            {
                sequentialCompares ++;
                SeComparison = strcmp(Words[LCount], Target);           // Words[LCount], not Words[Midlle]
                if(SeComparison == 0)
                {
                    foundSequential = true;
                    RetVal = 0;
                    break;
                }
                else
                {
                    foundSequential = false;
                }
            }
            if(foundSequential == true)
            {
                cout <<"We found " << Target << " at index " << LCount << " (sequential compares: "<< sequentialCompares <<")\n";
            }
            else
            {
                cout << Target <<" cannot be found\n";
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