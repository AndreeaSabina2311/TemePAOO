#include "hello/hello_config.hpp"
#include "hello/hello.hpp"
#include <iostream>
#include <utility>

int main() {
    std::cout << "=== Aplicație " << HELLO_VERSION << " ===\n\n";

    std::cout << "--- Creare obiect simplu ---\n";
    HelloResource res1(500); 
    
    std::cout << "\n--- Apel Copy Constructor ---\n";
    HelloResource res2 = res1; // Copiază toată memoria sigur, fără risc de Double Free
    
    std::cout << "\n--- Apel Move Constructor ---\n";
    HelloResource res3 = std::move(res1); // Transferă instantaneu memoria către res3
    
    std::cout << "\n--- Starea obiectelor ---\n";
    std::cout << "Res1:"; res1.afiseazaStare(); // Nu mai deține memoria
    std::cout << "Res2:"; res2.afiseazaStare();
    std::cout << "Res3:"; res3.afiseazaStare();

    std::cout << "\n--- Ieșire din program (apel destructori) ---\n";
    return 0;
}