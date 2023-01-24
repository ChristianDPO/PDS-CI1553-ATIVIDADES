#include <iostream>

#include "Disciplina.hpp"
#include "EnumTipoDisciplina.hpp"

using namespace ufpr;

int main(){
    Disciplina d1{"Programacao", nullptr, EnumTipoDisciplina::OPTATIVA};
    d1.setCargaHoraria(30);

    std::cout << d1.getNome() << '\n';

    return 0;
}