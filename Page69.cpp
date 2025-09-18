#include <iostream> 

using namespace std;

int main()
{
    int count, temp;
    double length, width, area;
    char ch;
    string name;


    // Also, suppose that the following statements excute in the order given

    count = 1;
    count = count + 1;
    cin >> length >> width;
    area = length + width; 

    cin >> name;

    length = length + 2;
    width = 2 * length - 5 * width;

    area = length + width;
    cin >> ch;

    temp = count + static_cast <int>(ch);

    return(0);




}