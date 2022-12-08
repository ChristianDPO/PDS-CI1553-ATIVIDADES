#include <iostream>
#include <list>

#include "Disciplina.hpp"
#include "Pessoa.hpp"

int main(){
    Pessoa p1{"João"};
    Pessoa p2{"Maria"};

    const Pessoa* const ptr1{&p1};
    //ptr1->setNome("Pedro");

    std::cout << ptr1->getNome() << std::endl;
    //ptr1 = &p2;
    
    return 0;
}