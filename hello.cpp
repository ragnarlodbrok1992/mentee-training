#include "pch.h"
#include <stdio.h>

int main() {
    std::cout << "Hello, World!" << std::endl;

    // Explicit segfault to test the debugger
    int a = 123;
    int* p = nullptr;

    printf("Wartosc (int) A -->   %d\n", a);
    printf("Wskaznik A na int --> %p\n", &a);

    printf("Wartosc P (wskaznika na int) --> %d\n", p);
    printf("Wskaznik P na int -->            %p\n", &p);
    *p = 420;
    std::cout << "This line will not be printed" << std::endl;

    return 0;
}
