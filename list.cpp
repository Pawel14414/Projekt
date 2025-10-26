#include "List.h"
#include <iostream>

List::List() : head(nullptr), tail(nullptr) {
    std::cout << "Lista zostala utworzona." << std::endl;
}

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

void List::addFront(int val) {
    Node* newNode = new Node(val);
    
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } 
    else {
        newNode->next = head; 
        head->prev = newNode; 
        head = newNode;       
    }
}

void List::addBack(int val) {
    Node* newNode = new Node(val);
    
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } 
    else {
        newNode->prev = tail; 
        tail->next = newNode; 
        tail = newNode;       
    }
}

void List::removeFront() {
    if (head == nullptr) {
        std::cout << "Lista jest pusta, nie mozna usunac elementu z przodu." << std::endl;
        return; 
    }
    
    Node* temp = head;
    
    if (head == tail) {
        head = nullptr;
        tail = nullptr;
    } 
    else {
        head = head->next; 
        if (head != nullptr) {
            head->prev = nullptr;
        }
    }
    
    delete temp;
}

void List::removeBack() {
    if (head == nullptr) {
        std::cout << "Lista jest pusta, nie mozna usunac elementu z konca." << std::endl;
        return; 
    }
    
    Node* temp = tail;

    if (head == tail) {
        head = nullptr;
        tail = nullptr;
    } 
    else {
        tail = tail->prev; 
        tail->next = nullptr;
    }
    
    delete temp;
}

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

void List::removeAt(int index) {
    if (index < 0) {
        std::cout << "Blad: Indeks nie moze byc ujemny." << std::endl;
        return;
    }
    
    if (head == nullptr) {
        std::cout << "Lista jest pusta, nie mozna usunac elementu." << std::endl;
        return;
    }
    
    if (index == 0) {
        removeFront();
        return;
    }
    
    Node* current = head;
    int current_index = 0;

    while (current != nullptr && current_index < index) {
        current = current->next;
        current_index++;
    }

    if (current == nullptr) {
        std::cout << "Blad: Indeks " << index << " poza zakresem listy." << std::endl;
        return;
    }

    if (current == tail) {
        removeBack();
        return;
    }

    current->prev->next = current->next;
    current->next->prev = current->prev;
    
    delete current;
}

