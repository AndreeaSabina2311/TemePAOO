#include <iostream>
#include "Calculator.hpp"

int main() {
    
    Calculator calculator_birou(1234, 0.0);

    int operatie_aleasa;
    double numar_a, numar_b;

    std::cout << "--- Interfata Mini-Calculator ---\n";
    std::cout << "Tasteaza 0 pentru Adunare\n";
    std::cout << "Tasteaza 1 pentru Scadere\n";
    std::cout << "Tasteaza 2 pentru Inmultire\n";
    std::cout << "Tasteaza 3 pentru Impartire\n";
    std::cout << "Alegerea ta: ";
    
    if (!(std::cin >> operatie_aleasa)) {
        std::cerr << "Eroare la citirea datelor de la tastatura.\n";
        return 1;
    }

    std::cout << "Introdu primul numar: ";
    std::cin >> numar_a;
    
    std::cout << "Introdu al doilea numar: ";
    std::cin >> numar_b;

    try {
        double rezultat_final = calculator_birou.efectueaza_operatie(operatie_aleasa, numar_a, numar_b);
        std::cout << "Rezultatul calculului este: " << rezultat_final << "\n";
    } catch (const std::exception& exceptie) {
        std::cerr << exceptie.what() << "\n";
    }

    
   // Calculator calculator_secundar = calculator_birou; // obiect prin copiere
   //  calculator_secundar = calculator_birou;     //atribuire; ar fi dat eroare si fara "= delete" din cauza membrului const

    return 0;
}