#include "List.h"
#include <iostream>

// Konstruktor
List::List() : head(nullptr), tail(nullptr) {
    std::cout << "Lista zostala utworzona." << std::endl;
}

// Destruktor (ważny! musimy zwolnić całą pamięć)
List::~List() {
    Node* current = head;
    Node* next;
    while (current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    tail = nullptr;
    std::cout << "Lista zostala wyczyszczona i usunieta." << std::endl;
}

// Implementacja: Dodaj element na początek listy
void List::addFront(int val) {
    Node* newNode = new Node(val);
    
    // 1. Jeśli lista jest pusta
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } 
    // 2. Jeśli lista nie jest pusta
    else {
        newNode->next = head; // Nowy węzeł wskazuje na starego heada
        head->prev = newNode; // Stary head wskazuje wstecz na nowy węzeł
        head = newNode;       // Aktualizujemy wskaźnik heada
    }
}

// Implementacja: Wyświetl całą listę
void List::display() {
    std::cout << "--- Zawartosc listy (od poczatku) ---" << std::endl;
    Node* current = head;
    if (current == nullptr) {
        std::cout << "Lista jest pusta." << std::endl;
        return;
    }
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
    std::cout << "-------------------------------------" << std::endl;
}