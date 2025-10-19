#pragma once

// Używamy int jako typu danych
class Node {
public:
    int data;
    Node* next;
    Node* prev;

    // Konstruktor
    Node(int val);
    ~Node();
};