#include <iostream>
#include "Calculator.hpp"

int main() {
    std::cout << "=== 1. TESTARE OPERATII DE BAZA (ADUNARE, SCADERE, INMULTIRE, IMPARTIRE) ===\n";
    Calculator calc(10.0);
    calc.afiseazaStare("calc initial");

    calc.aduna(5.0);      // 10 + 5 = 15
    calc.scade(3.0);      // 15 - 3 = 12
    calc.inmulteste(4.0); // 12 * 4 = 48
    calc.imparte(6.0);    // 48 / 6 = 8
    calc.afiseazaStare("calc dupa cele 4 operatii");

    // Verificare protectie la impartirea cu zero
    calc.imparte(0.0);
    calc.afiseazaStare("calc dupa incercarea de impartire la 0");

    std::cout << "\n=== 2. TESTARE ITEM 10: RETURNAREA REFERINTEI LA *this ===\n";
    Calculator c1(1.0);
    Calculator c2(2.0);
    Calculator c3(100.0);

    // Atribuire inlantuita
    c1 = c2 = c3;
    c1.afiseazaStare("c1 dupa c1 = c2 = c3");
    c2.afiseazaStare("c2 dupa c1 = c2 = c3");
    c3.afiseazaStare("c3 dupa c1 = c2 = c3");

    // Inlantuirea operatorilor compusi (+=, -=, *=, /=) si a metodelor
    ((c1 += 20.0) -= 5.0) /= 5.0; // ((100 + 20) - 5) / 5 = 23
    c1.afiseazaStare("c1 dupa ((c1 += 20) -= 5) /= 5");

    c2.aduna(50.0).imparte(3.0).inmulteste(2.0); // ((100 + 50) / 3) * 2 = 100
    c2.afiseazaStare("c2 dupa apeluri inlantuite");

    std::cout << "\n=== 3. TESTARE ITEM 11: AUTO-ATRIBUIREA (SELF-ASSIGNMENT) ===\n";
    // Cazul 1: Auto-atribuire directa (explicita)
    c1 = c1;
    c1.afiseazaStare("c1 dupa auto-atribuire directa (c1 = c1)");

    // Cazul 2: Auto-atribuire indirecta prin pointeri (aliasing)
    Calculator* ptrA = &c1;
    Calculator* ptrB = &c1;
    *ptrA = *ptrB;
    c1.afiseazaStare("c1 dupa auto-atribuire prin pointeri (*ptrA = *ptrB)");

    std::cout << "\n=== 4. TESTARE ITEM 12: COPIEREA TUTUROR PARTILOR UNUI OBIECT ===\n";
    CalculatorCuMemorie cm1(20.0, 0.0);
    cm1.aduna(30.0);         
    cm1.salveazaInMemorie(); 
    cm1.imparte(2.0);        
    cm1.afiseazaStare("cm1 (original)");

    // Testare Copy Constructor: trebuie sa copieze rezultat, numarOperatii SI memorieSalvata
    CalculatorCuMemorie cm2(cm1);
    cm2.afiseazaStare("cm2 (copiat prin Copy Constructor din cm1)");

    // Testare Copy Assignment Operator: trebuie sa copieze atat clasa de baza, cat si clasa derivata
    CalculatorCuMemorie cm3(999.0, 888.0);
    cm3.afiseazaStare("cm3 (inainte de atribuire)");

    cm3 = cm1;
    cm3.afiseazaStare("cm3 (dupa cm3 = cm1)");

    // Modificare cm1 pentru a demonstra ca cm2 si cm3 au propria memorie pe heap (deep copy)
    cm1.inmulteste(10.0);
    std::cout << "\nDupa modificarea lui cm1 (inmultire cu 10):\n";
    cm1.afiseazaStare("cm1");
    cm2.afiseazaStare("cm2 (ramane neschimbat)");
    cm3.afiseazaStare("cm3 (ramane neschimbat)");

    return 0;
}