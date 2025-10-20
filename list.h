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
    void display();
    void insertAt(int val, int index);        
};