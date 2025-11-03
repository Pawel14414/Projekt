#include "list.h"
#include <iostream>
using namespace std;

// Konstruktor
list::list() {
    head = nullptr;
    tail = nullptr;
}

// Dodanie elementu na początek
void list::push_front(int number) {
    node* newEl = new node(number);
    if (head != nullptr) {
        head->previous = newEl;
        newEl->next = head;
    } else {
        tail = newEl;
    }
    head = newEl;
}

// Dodanie elementu na koniec
void list::push_back(int number) {
    node* newEl = new node(number);
    if (tail != nullptr) {
        tail->next = newEl;
        newEl->previous = tail;
    } else {
        head = newEl;
    }
    tail = newEl;
}

// Dodanie elementu w dowolnym miejscu
void list::push_at(int number, int index) {
    if (index <= 0) {
        push_front(number);
        return;
    }

    node* current = head;
    int pos = 0;

    while (current != nullptr && pos < index - 1) {
        current = current->next;
        pos++;
    }

    if (current == nullptr || current->next == nullptr) {
        push_back(number);
        return;
    }

    node* newEl = new node(number);
    newEl->next = current->next;
    newEl->previous = current;
    current->next->previous = newEl;
    current->next = newEl;
}

// Usunięcie pierwszego elementu
void list::pop_front() {
    if (head == nullptr) return;

    node* temp = head;
    head = head->next;

    if (head != nullptr)
        head->previous = nullptr;
    else
        tail = nullptr;

    delete temp;
}

// Usunięcie ostatniego elementu
void list::pop_back() {
    if (tail == nullptr) return;

    node* temp = tail;
    tail = tail->previous;

    if (tail != nullptr)
        tail->next = nullptr;
    else
        head = nullptr;

    delete temp;
}

// Usunięcie elementu o podanym indeksie
void list::pop_at(int index) {
    if (index < 0 || head == nullptr) return;

    node* current = head;
    int pos = 0;

    while (current != nullptr && pos < index) {
        current = current->next;
        pos++;
    }

    if (current == nullptr) return;

    if (current->previous != nullptr)
        current->previous->next = current->next;
    else
        head = current->next;

    if (current->next != nullptr)
        current->next->previous = current->previous;
    else
        tail = current->previous;

    delete current;
}

// Wyświetlenie listy od początku
void list::show() {
    node* current = head;
    if (current == nullptr) {
        cout << "Lista jest pusta." << endl;
        return;
    }

    cout << "Lista: ";
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Wyświetlenie listy od końca
void list::showReverse() {
    node* current = tail;
    if (current == nullptr) {
        cout << "Lista jest pusta." << endl;
        return;
    }

    cout << "Lista (od końca): ";
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->previous;
    }
    cout << endl;
}

// Wyświetlenie następnego elementu względem indeksu
void list::show_next(int index) {
    node* current = head;
    int pos = 0;

    while (current != nullptr && pos < index) {
        current = current->next;
        pos++;
    }

    if (current != nullptr && current->next != nullptr)
        cout << "Następny element po indexie " << index << ": " << current->next->data << endl;
    else
        cout << "Brak następnego elementu." << endl;
}

// Wyświetlenie poprzedniego elementu względem indeksu
void list::show_previous(int index) {
    node* current = head;
    int pos = 0;

    while (current != nullptr && pos < index) {
        current = current->next;
        pos++;
    }

    if (current != nullptr && current->previous != nullptr)
        cout << "Poprzedni element przed indexem " << index << ": " << current->previous->data << endl;
    else
        cout << "Brak poprzedniego elementu." << endl;
}

// Czyszczenie listy
void list::clear() {
    node* current = head;
    while (current != nullptr) {
        node* temp = current->next;
        delete current;
        current = temp;
    }
    head = nullptr;
    tail = nullptr;
}

// Destruktor
list::~list() {
    clear();
}
