#ifndef LIST_H
#define LIST_H

#include "node.h"
#include <iostream>

class list {
private:
    node* head;  // początek listy
    node* tail;  // koniec listy

public:
    list();

    // Operacje dodawania
    void push_front(int number);
    void push_back(int number);
    void push_at(int number, int index);

    // Operacje usuwania
    void pop_front();
    void pop_back();
    void pop_at(int index);

    // Wyświetlanie listy
    void show();
    void showReverse();
    void show_next(int index);
    void show_previous(int index);

    // Czyszczenie i destrukcja
    void clear();
    ~list();
};

#endif
