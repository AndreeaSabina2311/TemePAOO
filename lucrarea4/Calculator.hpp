#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include <iostream>
#include <stdexcept>

class Calculator {
private:
    
    // variabila constanta care reprezinta un identificator unic pentru fiecare obiect Calculator.
    const int id_calculator;
    
    // variabila interna in care pastram ultimul rezultat calculat in urma operatiilor.
    double rezultat_curent;

public:
    //  lista de initializare a membrilor (member initialization list) 
    Calculator(int id, double valoare_initiala)
        : id_calculator(id), 
          rezultat_curent(valoare_initiala) 
    {
        std::cout << "Calculatorul cu ID-ul " << id_calculator << " a fost initializat corect.\n";
    }

    // interzice in mod explicit utilizarea functiilor generate de compilator pe care nu le doresti
    Calculator(const Calculator& alt_calculator) = delete;
    Calculator& operator=(const Calculator& alt_calculator) = delete;

    double efectueaza_operatie(int cod_operatie, double operand1, double operand2) {
        switch (cod_operatie) {
            case 0:
                rezultat_curent = operand1 + operand2;
                break;
            case 1:
                rezultat_curent = operand1 - operand2;
                break;
            case 2:
                rezultat_curent = operand1 * operand2;
                break;
            case 3:
                if (operand2 == 0.0) {
                    throw std::runtime_error("Eroare fatala: Impartirea la zero este interzisa.");
                }
                rezultat_curent = operand1 / operand2;
                break;
            default:
                throw std::invalid_argument("Cod de operatie necunoscut. Va rugam introduceti 0, 1, 2 sau 3.");
        }
        return rezultat_curent;
    }

};

#endif 