#include <iostream>

int main()
{   
    int a = 12 ;
    int b = 10 ;

    a = a^b ;
    b = a^b ;
    a = a^b ;

    std::cin.get();
}


