#include <iostream>

#include "ProfessorAdjunto.hpp"
#include "Professor.hpp"

int main(){
    ProfessorAdjunto p{"Joao", 11111111111, 8500, 40};

    Professor* ptr{&p};

    std::cout << p.getNome() << " " << p.getSalario() << std::endl;
    std::cout << ptr->getNome() << " " << ptr->getSalario() << std::endl;

    return 0;
}
