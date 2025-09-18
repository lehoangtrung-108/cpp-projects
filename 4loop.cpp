#include <iostream>
#include <cstring>
#include <limits>       // using for cin.ignore(numeric_limits<streamsize>::max(), '\n)
#include <string>

using namespace std;

int main()
{
    
    int Number, RetVal = 0;
    int dowhileCounter = 1;
    int whileCounter = 1;
    int forCounter = 1;
    int gotoCounter = 1;
    int Exit;

    string Input;

    bool CheckNumber = true;
    /* Some other ways that they usually use for checking without using boolean

    const int VALID_INPUT = 1;
    const int INVALID_INPUT = 0;


    or:
    bool isValidInput(int number) 
    {
        return number > 0;
    }

    or:
    int status = isValidInput(number) ? VALID_INPUT : INVALID_INPUT;

    */


    while(CheckNumber)
    {

        cout << "Enter a number (or type exit to quit the loop): ";
        cin >> Input;

        if(Input == "exit")
        {
            cout << "@Loading----Successful\n";
            break;
            goto EOP;
        }



        else
        {
        
        //Convert input to an integer for further processing
        Number = stoi(Input);
        

        if(cin.fail())
        {
            cin.clear();

            RetVal = 9;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');        // the same as while(getchar() != '\n);

            cout << "!!!! Invalid Input. What we need is a number. You should try it again!!!\n\n ";
            continue;
        }
        if(Number < 1)
        {
            cout << "\tWe cannot accept any value smaller than or equal to 1 in this assignment !!!\n";
            cout << "\tYou should try again\n";
            continue;
        }
       break;
    }

    


    // Do-While Loop 
    cout << "-----DO-WHILE LOOP-----\n";
    do
    {
       cout <<"\t" << dowhileCounter<<"\n";
       dowhileCounter ++;
        
    }
    while(dowhileCounter < Number);

    // While loop
    cout << "-----WHILE LOOP-----\n";
    while(whileCounter < Number)
    {
        cout <<"\t" << whileCounter << "\n";
        whileCounter ++;
    }

    // For Loop
    cout << "-----FOR LOOP-----\n";
    for(forCounter = 1; forCounter < Number; forCounter ++)
    {
        cout << "\t" << forCounter <<"\n";

    }

    //Goto Loop
    
    cout << "-----Goto Loop-----\n";
    Begin:
    cout << "\t" << gotoCounter << "\n";
    gotoCounter ++ ;
    if(gotoCounter < Number)
    {
        goto Begin;
    }
    }

    EOP:
    return(RetVal);
}