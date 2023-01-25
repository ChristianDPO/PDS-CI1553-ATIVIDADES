#include <iostream>
#include "CPF.hpp"

int main(){
    //abra um gerador de cpf e coloque
    //um cpf que começa com 0
    ufpr::CPF cpf1{11111111111};
    std::cout << cpf1 << '\n';

    return 0;
}