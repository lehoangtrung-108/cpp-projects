#include <iostream> 

using namespace std; // avoid repeating std:: for each line of code later

int main()
{
    // Declare variables
    /***********************************************
     *              Difference between "float" and "double"
     * 

     *                                  Float:
    Số bits biểu diễn:          32 bits.
    Độ chính xác:               single precision.
   
    Float chứa                  7 chữ số thập phân.
    !!! >>> Thường được sử dụng khi cần tiết kiệm bộ nhớ hoặc độ chính xác không quá cao. <<< !!!!!
                                        
                                        
                                        Double:
    Số bits biểu diễn:                  64 bits.
    Độ chính xác:                       double precision
  
    Double chứa                         15 đến 16 chữ số thập phân.
    !!!!! >>>> Thường được sử dụng khi cần độ chính xác cao hơn và không quan trọng về bộ nhớ. <<<<< !!!!!
     * 
     * 
     * 
     * ********************************************
     */

    double length;
    double width;
    double perimeter;
    double area;

    cout << "Program to compute and output the perimeter and area of a rectangle.\n";

    length = 6.0;
    width = 4.0;
    perimeter = 2 * (length + width);
    area = length * width;

    cout << "Length = " << length /* location of length above */ << endl;    // endl = \n in C
    cout << "Width = " << width << endl;
    cout << "Perimeter = " << perimeter << endl;
    cout << "Area = " << area << endl;

    return(0);
}