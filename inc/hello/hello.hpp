#pragma once

class HelloResource {
private:
    int* buffer; // Memorie alocată pe heap
    int size;

public:
    HelloResource(int s);                       //  Constructor
    ~HelloResource();                           //  Destructor
    HelloResource(const HelloResource& other);  //  Copy Constructor
    HelloResource(HelloResource&& other) noexcept; //  Move Constructor

    void afiseazaStare() const;
};