#include <iostream>

#include "Disciplina.hpp"
#include "EnumTipoDisciplina.hpp"
#include "CargaHorariaInvalidaException.hpp"

using namespace ufpr;

int main(){
    
    std::cout << "Disciplina OPTATIVA com carga horaria 100\n#####\n";
    Disciplina d1{"Programacao", nullptr, EnumTipoDisciplina::OPTATIVA};
    d1.setCargaHoraria(100);

    std::cout << d1.getNome() << std::endl;
    std::cout << d1.getCargaHoraria() << std::endl;

    std::cout << "Disciplina MANDATORIA com carga horaria 100\n#####\n";
    Disciplina d2{"Grafos", nullptr, EnumTipoDisciplina::MANDATORIA};
    d2.setCargaHoraria(100);

    std::cout << d2.getNome() << std::endl;
    std::cout << d2.getCargaHoraria() << std::endl;

    std::cout << "Disciplina MANDATORIA com carga horaria 29\n#####\n";
    Disciplina d3{"Redes 2", nullptr, EnumTipoDisciplina::MANDATORIA};
    
    //exemplo da excecao ser capturada
    std::cout << d3.getNome() << std::endl;
    try{    
        d3.setCargaHoraria(29);
        std::cout << d3.getCargaHoraria() << std::endl;
    }catch(CargaHorariaInvalidaException &caie){
        std::cout << "Erro de carga horaria: " << caie.what() << " " << caie.cargaHoraria << std::endl;
    }

    return 0;
}