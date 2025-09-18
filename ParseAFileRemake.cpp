#include <iostream>
#include <cctype>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    int RetVal = 0;
    ifstream inFile("ReservedWordList.txt");
    if (inFile.fail())
    {
        cout << "Unable to open our Text File to parse\n";
        cout << "You should check your name or location of file just in case\n";
        RetVal = 9;
    }
    else
    {
        char thisByte;
        int wordIndex = 0;
        string thisWord;                    // Use a string to store the word
        bool wordStarted = false;

        bool CheckLetter = true;
        bool CheckSpace = true;
        bool CheckPunct  = true;


        while (inFile.get(thisByte))    // Read each character from the file              // Get a single character from TextFile and store it into 'thisByte' variable
        {
            CheckLetter = isalpha(thisByte);
            CheckSpace = isspace(thisByte);
            CheckPunct = ispunct(thisByte);


            if (CheckLetter == true)    // Check if the character is a letter
            {
                thisByte = tolower(thisByte);
                thisWord += thisByte;  // Append the character to the word
                wordStarted = true;
            }
            else if (CheckSpace == true)  // Check if the character is a space
            {
                if (wordStarted)            // If a word has started, print it
                {

                    /*You don't need to add '\0' to the end of thisWord because the std::string class already ensures that the string is null-terminated.
                     The operator<< for std::string will correctly print the entire string.*/

                    cout << thisWord << "\n";      
                    thisWord.clear();       // Clear the word for the next one
                    wordStarted = false;
                }
            }
            else if (CheckPunct == true)     // Check if the character is a punctuation
            {
                if (thisByte == '\'' || thisByte == '-')
                {
                    // Do nothing, handle special cases like apostrophes or hyphens
                }
                else if (wordStarted)
                {
                    cout << thisWord << "\n";
                    thisWord.clear();
                    wordStarted = false;
                }
            }
        }

        // Print the last word if the file ends with a letter
        if (wordStarted)
        {
            cout << thisWord << "\n";
        }
    }

    inFile.close();
    return RetVal;
}
