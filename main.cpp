#pragma warning(disable : 4996)

#include "string_basic.h"
#include <iostream>

int main()
{
    string_basic example;

    string_basic example2("This is text!");

    std::cout << "Enter something: ";
    std::cin  >> example;
    std::cout << example << '\n';

    std::cout << example2 << '\n';

    return 0;
}