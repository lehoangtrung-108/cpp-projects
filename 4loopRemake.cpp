/****************************************************************
 * 
 *                     THIS IS CHATGPT VERSION 
 * 
 * ***************************************************************/
#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main() {
    int Number, RetVal = 0;
    int dowhileCounter = 1;
    int whileCounter = 1;
    int forCounter = 1;
    int gotoCounter = 1;

    string Input;

    while (true) {
        cout << "Enter a number (or type exit to quit the loop): ";
        cin >> Input;

        if (Input == "exit") {
            cout << "@Loading----Successful\n";
            break;  // Exit the loop if "exit" is entered
        }

        Number = stoi(Input);  // Convert input to an integer

        if (cin.fail()) {
            cin.clear();
            RetVal = 9;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid Input. Please enter a valid number.\n\n";
            continue;  // Continue to the next iteration of the loop
        }

        if (Number < 1) {
            cout << "\tWe cannot accept any value smaller than or equal to 1 in this assignment !!!\n";
            cout << "\tYou should try again\n";
            continue;  // Continue to the next iteration of the loop
        }

        // Do-While Loop 
        cout << "-----DO-WHILE LOOP-----\n";
        do {
            cout << "\t" << dowhileCounter << "\n";
            dowhileCounter++;
        } while (dowhileCounter < Number);

        // While loop
        cout << "-----WHILE LOOP-----\n";
        while (whileCounter < Number) {
            cout << "\t" << whileCounter << "\n";
            whileCounter++;
        }

        // For Loop
        cout << "-----FOR LOOP-----\n";
        for (forCounter = 1; forCounter < Number; forCounter++) {
            cout << "\t" << forCounter << "\n";
        }

        // Goto Loop
        cout << "-----Goto Loop-----\n";
        Begin:
        cout << "\t" << gotoCounter << "\n";
        gotoCounter++;
        if (gotoCounter < Number) {
            goto Begin;
        }
    }

    return RetVal;
}
