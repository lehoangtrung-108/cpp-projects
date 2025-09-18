#include <iostream>
#include <fstream>

using namespace std;

#define MAXIMUM 100

/****************************************************************


TAKE A LOOK WORD FILE TO SEE HOW C & C++ LOOK ALIKE TO EACH OTHER 



!!! I need to figure other ways to avoid repeating TextFile (pointer) in my program to make it more readable


******************************************************************/

int main() 
{                                           // Start of main code block
    int ReVal = 0; 
    int Nums[MAXIMUM];
    int LCount = 0, firstLoop, secondLoop, Holder, itemRead;
    int LCount1 = 0; 
    bool didSwap, hasNonNumericElement = false; 

    ifstream TextFile("NumbersToSort.txt");        
    /***************************************
     * fstream TextFile;
     * TextFile.open("NumbersToSort.txt", ios::in);
     * 
     *********************************************/





    if (!TextFile)  // We can use TextFile.fail() as well        // As a way to prompt the user to check the file again if file failed to open
    {
        cout << "!!!! FILE failed to open !!!!\n";
        cout << ">> You should check your Text File again <<<<\n";
        ReVal = 9; 
        goto EOP;
    }

    
    for (LCount = 0; LCount < MAXIMUM; LCount++) 
    {                                                                                          // Start of "for loop" function
        TextFile >> Nums[LCount];           
        if (TextFile.eof()) 
        {
            break; // End of file reached
        }
        if (TextFile.fail())                       // While reading the file, we can make sure that we would not have any non-numeric element(s).
        {                                                                                      // Start of if statement
            cout << "Warning: Encountered non-numeric character or empty line in the file.\n"; 
            cout << ">>>> You should take time to check your Text File carefully <<<<\n";
            hasNonNumericElement = true;    
            break;                                                                              // Do not want to make the prompt on console as a matrix (Leave the for loop)
        }  
    }                                                                                     // End of if statement
  

    if (hasNonNumericElement == false)                                                                                               
    {                                                                      // Start of if statement
        cout << "-----Here is the list BEFORE the sort ---------\n";
        for (LCount1 = 0; LCount1 < LCount; LCount1 ++) 
        {
            cout << Nums[LCount1] << endl;                                 // Print all unsorted input on terminal to let us easily compare with sorted output eventually
        }
        for (firstLoop = 0; firstLoop < LCount - 1; firstLoop++)                   // This outer loop ensures the passes that the entire array is iterated over multiple times.
        {                                                                  // Start of OuterLoop
            didSwap = false;                                                                    
            for (secondLoop = 0; secondLoop < LCount - firstLoop - 1; secondLoop ++)             // Iterates through the unsorted part of the array in each pass, ensuring the unsorted largest element at the end of array
            {                                                              // Start of InnerLoop
                if (Nums[secondLoop] > Nums[secondLoop + 1]) 
                {
                    /*The swapping of variables inside the second Loop part*/
                    Holder = Nums[secondLoop];
                    Nums[secondLoop] = Nums[secondLoop + 1];
                    Nums[secondLoop + 1] = Holder;
                    didSwap = true;
                }
            }                                                               // End of InnerLoop
            if (didSwap) 
            {
                continue;
            }
            else
            {
                break;                                                      // If no swaps were made, it means that the array is already sorted => Don't need to continue    
            }
        }                                                                   // End of OuterLoop

        cout << "\n ----Here is the list AFTER the sort-----\n";
        for (LCount1 = 0; LCount1 < LCount; LCount1++) 
        {
            cout << Nums[LCount1] << endl;                                   // To let us see and easily compare array before and after sorting easier on our console
        }   
    }                                                                       // End of if statement
    
EOP:
                                                                            // End of "For loop" function
    TextFile.close();
    return (ReVal);
}                                                                           // End of main code block 


