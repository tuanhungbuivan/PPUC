#include <iostream>

void stackDirection(int* p) {
    int local;
    if (p < &local) {
        std::cout << "Stack grows downwards\n";
    } else {
        std::cout << "Stack grows upwards\n";
    }
}

void heapDirection(int* p) {
    int* q = new int;
    if (p < q) {
        std::cout << "Heap grows upwards\n";
    } else {
        std::cout << "Heap grows downwards\n";
    }
    delete q;
}

int main() {
    int main_local;
    int* p = &main_local;

    stackDirection(p);
    heapDirection(p);

    return 0;
}
