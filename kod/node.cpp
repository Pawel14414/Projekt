#include "node.h"

// Konstruktor inicjalizujący węzeł
node::node(int value) {
    data = value;
    next = nullptr;
    previous = nullptr;
}
