#include <iostream>
#include <string>

using namespace std;

int main()
{
    int Number1, Number2;
    double Sale;
    char firstCharacter;
    string Sentence;

    Number1 = 4;
    cout <<"First Number we got here:>> " << Number1 << endl;

    Number2 = 4 * 5 - 11;
    cout << "Second Number we got here:>> " << Number2 << endl;

    Sale = 0.02 * 1000; 
    cout << "This product is currently on sale:>> " << Sale << endl;

    firstCharacter = 'D';
    cout << "First Character of my friend's name is:>> " << firstCharacter << endl;

    Sentence = "It is a sunny day.";
    cout << "My message to you was:>> "<< Sentence << endl;

    return(0);

}