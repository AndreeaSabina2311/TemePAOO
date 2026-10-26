#include "hello/hello.hpp"
#include <iostream>

using namespace std;

//  Inițializarea membrilor din constructor folosind lista de inițializare
HelloResource::HelloResource(int s) : size(s), buffer(new int[s]) {
    cout << "[Constructor Default] S-a alocat pe heap un buffer de " << size << " elemente.\n";
}

//  Eliberarea heap-ului în cadrul destructorului
HelloResource::~HelloResource() {
    delete[] buffer; 
    cout << "[Destructor] S-a dealocat buffer-ul de " << size << " elemente.\n";
}

// Suprascrierea copy constructor-ului (Deep Copy)
HelloResource::HelloResource(const HelloResource& other) : size(other.size), buffer(new int[other.size]) {
    for (int i = 0; i < size; i++) {
        buffer[i] = other.buffer[i];
    }
    cout << "[Copy Constructor] Copiere profunda a " << size << " elemente in memorie noua.\n";
}

// Crearea unui move constructor
HelloResource::HelloResource(HelloResource&& other) noexcept : size(other.size), buffer(other.buffer) {
    other.buffer = nullptr;
    other.size = 0;
    cout << "[Move Constructor] S-a preluat proprietatea memoriei fara realocare.\n";
}

void HelloResource::afiseazaStare() const {
    if (buffer) cout << " - Resursa valida, dimensiune: " << size << "\n";
    else cout << " - Resursa goala (mutata).\n";
}