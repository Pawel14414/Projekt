#include "List.h"
#include "Node.h"
#include <iostream>

// Konstruktor: Inicjuje pustą listę
List::List() : head(nullptr), tail(nullptr) {
    std::cout << "Lista zostala utworzona." << std::endl;
}

// Destruktor: Zwalnia pamięć wszystkich węzłów
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

// Dodaj element na początek listy
void List::addFront(int val) {
    Node* newNode = new Node(val);
    
    if (head == nullptr) {
        // Lista jest pusta
        head = newNode;
        tail = newNode;
    } 
    else {
        // Lista nie jest pusta
        newNode->next = head; 
        head->prev = newNode; 
        head = newNode;       
    }
}

// Dodaj element na koniec listy
void List::addBack(int val) {
    Node* newNode = new Node(val);
    
    if (head == nullptr) {
        // Lista jest pusta
        head = newNode;
        tail = newNode;
    } 
    else {
        // Lista nie jest pusta
        newNode->prev = tail; 
        tail->next = newNode; 
        tail = newNode;       
    }
}

// Usuń element z początku listy (Piąty Commit)
void List::removeFront() {
    if (head == nullptr) {
        // Lista jest pusta - nic nie rób
        std::cout << "Lista jest pusta, nie mozna usunac." << std::endl;
        return; 
    }
    
    Node* temp = head; // Wskaźnik na węzeł do usunięcia
    
    // Jeśli jest tylko jeden element
    if (head == tail) {
        head = nullptr;
        tail = nullptr;
    } 
    // Jeśli jest więcej niż jeden element
    else {
        head = head->next; 
        if (head != nullptr) {
            head->prev = nullptr; // Nowa głowa musi mieć prev = nullptr
        }
    }
    
    delete temp; // Zwolnienie pamięci
}

// WYŚWIETLANIE (od początku)
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