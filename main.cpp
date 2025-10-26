#include "List.h"
#include <iostream>

int main() {

List removeAtTest;

removeAtTest.addBack(10);
removeAtTest.addBack(20);
removeAtTest.addBack(30);
removeAtTest.addBack(40);
removeAtTest.addBack(50);

std::cout << "\n=============================================" << std::endl;
std::cout << "--- TESTY removeAt (Siodmy Commit) ---" << std::endl;
std::cout << "Stan poczatkowy: ";
removeAtTest.display(); 

removeAtTest.removeAt(2);
std::cout << "Po usunieciu Index 2 (30): ";
removeAtTest.display();

removeAtTest.removeAt(0);
std::cout << "Po usunieciu Index 0 (10): ";
removeAtTest.display();

removeAtTest.removeAt(2);
std::cout << "Po usunieciu Index 2 (50): ";
removeAtTest.display();

removeAtTest.removeAt(10);

removeAtTest.removeAt(-1);

removeAtTest.removeAt(0);
removeAtTest.removeAt(0);
removeAtTest.removeAt(0);


}