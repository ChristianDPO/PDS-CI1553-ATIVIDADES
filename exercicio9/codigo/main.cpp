#include <iostream>

#include "Pessoa.hpp"
#include "Disciplina.hpp"
#include "ConteudoMinistrado.hpp"
#include "Console.hpp"

int main(){
    Pessoa prof1{"João", 11111111111, 40};
    Disciplina dis1{"C++", nullptr};
    dis1.setProfessor(&prof1);

    dis1.adicionarConteudoMinistrado("Ponteiros", 4);
    dis1.adicionarConteudoMinistrado("Referencias", 2);
    dis1.adicionarConteudoMinistrado("Dados estáticos", 6);

    Console::imprimirDadosDisciplina(dis1);

    std::cout << "--- Removendo conteúdo ministrado de id == 1\n";
    dis1.removeConteudoMinistrado(1);

    Console::imprimirDadosDisciplina(dis1);

    std::cout << "--- Limpando todos os conteúdos ministrados\n";
    dis1.limpaCountedos();
    Console::imprimirDadosDisciplina(dis1);

    return 0;
}