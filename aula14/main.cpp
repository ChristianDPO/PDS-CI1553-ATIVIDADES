#include <iostream>

#include "ProfessorAdjunto.hpp"
#include "Professor.hpp"

int main(){
    Professor* p{new ProfessorAdjunto{"Maria", 11111111111, 100, 40}};
    std::cout << p->getSalario() << std::endl;
    delete p;
    return 0;
}