#include "List.h"
#include <iostream>

int main() {
    List myList;

    std::cout << "Test 1: Dodanie 5, 10, 15 na poczatek (powinno byc 15, 10, 5)" << std::endl;
    myList.addFront(20);
    myList.display();

    std::cout << "Test 2: Dodanie 20 na poczatek (powinno byc 20, 15, 10, 5)" << std::endl;
    myList.addBack(100);
    myList.addBack(200);
    myList.display();
    // Destruktor zostanie wywołany automatycznie, czyszcząc listę
    return 0;
}