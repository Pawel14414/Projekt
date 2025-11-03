#ifndef NODE_H
#define NODE_H

// Klasa reprezentująca pojedynczy element listy (węzeł)
class node {
public:
    int data;        // wartość przechowywana w węźle
    node* next;      // wskaźnik na następny element
    node* previous;  // wskaźnik na poprzedni element

    node(int value); // konstruktor
};

#endif