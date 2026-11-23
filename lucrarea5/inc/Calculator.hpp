#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include <iostream>

// CLASA DE BAZA: Calculator
class Calculator {
private:

    double* rezultat;
    int numarOperatii;

public:
    explicit Calculator(double valoareInitiala = 0.0)
        : rezultat(new double(valoareInitiala)), numarOperatii(0) {
    }

    virtual ~Calculator() {
        delete rezultat;
    }

    // COPY CONSTRUCTOR 
    Calculator(const Calculator& rhs)
        : rezultat(new double(*rhs.rezultat)), numarOperatii(rhs.numarOperatii) {
    }

    // COPY ASSIGNMENT OPERATOR (Item 10, Item 11, Item 12)
    Calculator& operator=(const Calculator& rhs) {
        // ITEM 11
        double* vechiulRezultat = rezultat;

        rezultat = new double(*rhs.rezultat);

        delete vechiulRezultat;

        // ITEM 12
        numarOperatii = rhs.numarOperatii;

        // ITEM 10
        return *this;
    }

    Calculator& operator+=(double valoare) {
        *rezultat += valoare;
        numarOperatii++;
        return *this;
    }

    Calculator& operator-=(double valoare) {
        *rezultat -= valoare;
        numarOperatii++;
        return *this;
    }

    Calculator& operator*=(double valoare) {
        *rezultat *= valoare;
        numarOperatii++;
        return *this;
    }

    Calculator& operator/=(double valoare) {
        if (valoare == 0.0) {
            std::cout << "[Eroare] Impartirea la 0 nu este permisa! Valoarea ramane neschimbata.\n";
            return *this;
        }
        *rezultat /= valoare;
        numarOperatii++;
        return *this;
    }

    Calculator& aduna(double valoare) {
        return (*this += valoare);
    }

    Calculator& scade(double valoare) {
        return (*this -= valoare);
    }

    Calculator& inmulteste(double valoare) {
        return (*this *= valoare);
    }

    Calculator& imparte(double valoare) {
        return (*this /= valoare);
    }

    double getRezultat() const {
        return *rezultat;
    }

    int getNumarOperatii() const {
        return numarOperatii;
    }

    virtual void afiseazaStare(const char* numeObiect) const {
        std::cout << numeObiect
                  << " -> Rezultat: " << *rezultat
                  << " | Operatii efectuate: " << numarOperatii << "\n";
    }
};

// CLASA DERIVATA: CalculatorCuMemorie
class CalculatorCuMemorie : public Calculator {
private:
    double memorieSalvata;

public:
    explicit CalculatorCuMemorie(double valoareInitiala = 0.0, double memorieInitiala = 0.0)
        : Calculator(valoareInitiala), memorieSalvata(memorieInitiala) {
    }

    // COPY CONSTRUCTOR IN CLASA DERIVATA (Item 12)
    CalculatorCuMemorie(const CalculatorCuMemorie& rhs)
        : Calculator(rhs), memorieSalvata(rhs.memorieSalvata) {
    }

    // COPY ASSIGNMENT OPERATOR IN CLASA DERIVATA (Item 10, Item 11, Item 12)
    CalculatorCuMemorie& operator=(const CalculatorCuMemorie& rhs) {
        // ITEM 12: Apelam operatorul= al clasei de baza pentru a copia partea comuna
        Calculator::operator=(rhs);

        // ITEM 12: Copiem membrul propriu al clasei derivate
        memorieSalvata = rhs.memorieSalvata;

        // ITEM 10: Returnam referinta la *this
        return *this;
    }

    void salveazaInMemorie() {
        memorieSalvata = getRezultat();
    }

    double getMemorieSalvata() const {
        return memorieSalvata;
    }

    void afiseazaStare(const char* numeObiect) const override {
        std::cout << numeObiect
                  << " -> Rezultat: " << getRezultat()
                  << " | Operatii efectuate: " << getNumarOperatii()
                  << " | Memorie salvata: " << memorieSalvata << "\n";
    }
};

#endif 