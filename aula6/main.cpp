#include<iostream>

#include "Pessoa.hpp"

int main(){
    Pessoa* p1{new Pessoa{"Joao", 11111111111, 20}};
    Pessoa p2{"Maria"};

    p1->imprimirEnderecoMemoria();
    p2.imprimirEnderecoMemoria();

    delete p1;

    return 0;
}