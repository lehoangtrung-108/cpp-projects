#include <iostream>
#include <string>


using namespace std;

int main()
{
    string firstName;
    string lastName;

    int myAge;
    double myWeight;

    cout << "Enter first, last name, age, and your weight, seperated by space>> " << endl;
    cin >> firstName >> lastName;
    cin >> myAge >> myWeight;

    cout << "My name is  " << firstName << " " << lastName << endl;
 
    cout << "I am " << myAge << " years old" << endl;                       // FOCUS ON THIS LINE: 
    
    cout << "The last time I scale myself was " << myWeight << endl;

    return(0);

}


/********************************************************************************
 * 
 * TRYING TO PROTECT MY C++ FROM THE USER'S INPUT ABOVE LIKE WE USED TO DO IN C 
 * 
 * ******************************************************************************
 */
