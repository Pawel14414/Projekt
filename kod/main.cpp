#include <iostream>
#include "list.h"
using namespace std;

int main() {
    list* lista = new list();

    cout << "--- Dodawanie elementów na początek i koniec ---" << endl;
    lista->push_front(10);
    lista->push_back(5);
    lista->show();

    cout << "--- Dodawanie elementu w środku (push_at) ---" << endl;
    lista->push_at(15, 1);
    lista->show();

    cout << "--- Wyświetlanie listy od końca ---" << endl;
    lista->showReverse();

    cout << "--- Wyświetlenie sąsiadów dla indexu 1 ---" << endl;
    lista->show_previous(1);
    lista->show_next(1);

    cout << "--- Usuwanie elementów ---" << endl;
    lista->pop_front();
    lista->pop_back();
    lista->show();

    cout << "--- Dodanie kilku elementów i usunięcie ze środka ---" << endl;
    lista->push_front(20);
    lista->push_back(25);
    lista->push_at(30, 1);
    lista->show();
    lista->pop_at(1);
    lista->show();

    cout << "--- Czyszczenie listy ---" << endl;
    lista->clear();
    lista->show();

    delete lista;
    cout << "Lista usunięta z pamięci." << endl;

    return 0;
}
