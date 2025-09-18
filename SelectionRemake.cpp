#include <iostream>
#include <limits> // use for cin.ignore(numeric_limits<streamsize>::max, "\n")

using namespace std;

int main()
{
    // Declare variable
    int Prefer;
    int RetVal = 0;

    bool NumberCheck = false;

    Begin:
    cout << "On the scale from 1 to 10, how happy are you right now: ";
    cin >> Prefer;
    
    if(cin.fail())
    {
        NumberCheck = false;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
    }
    else
    {
        NumberCheck = true;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }





    if(NumberCheck = true && Prefer >= 1 && Prefer <= 10)
    {
        if(Prefer >= 9)
        {
        cout << "Great for you! Things are going well for you\n";
        }
        else if(Prefer >= 6)
        {
            cout << "Better than average, right?\n";
        }
        else if (Prefer >= 4)
        {
            cout << "Sorry you're feeling not so great. \n";
        }
        else if (Prefer = 3)
        {
            cout << "Hope things turn around soon...\n";
        }
        else 
        {
            cout << "Hang in there -- things have to improve, right? \n";
        }
    

    switch(Prefer)          // Inside switch function was INPUT VARIABLE
    {
        case(10):           // Using ':' after case
        case(9):
            cout << "You seem to be ecstatic right now! Good for you, my friend.\n";
            break;
        case(8):
        case(7):
        case(6):
            cout << "You are feeling quite content\n";
            break;
        case(5):
        case(4):
            cout << "You are feeling a bit down. Have a seat and tell me what happened\n";
            break;
        case(3):
            cout << "You look so exhausted. You need to spend more time relaxing.\n";
            break;
        default:
            cout << "Hang on! I'll be there with you just in a few minutes.\n";
            break;
    }

    // Tenary Operator:

    (Prefer >= 7) ? cout << "Look at you! What made you feel over the moon like that?\n" : cout << "Don't be sad! Everything'd be fine, my friend\n";
    }
    else 
    {
        cout << "This is not a number on the scale that we need, is it?\n";
        goto Begin;
    }

    return(0);
}