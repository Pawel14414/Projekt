#pragma once
#include "Node.h"

class List {
private:
    Node* head;
    Node* tail;
    

public:
    List();
    ~List();

    void addFront(int val);
    void addBack(int val);
    void insertAt(int val, int index);
    void removeFront();
    void display();      
};