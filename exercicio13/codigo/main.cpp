#include <iostream>

#include "Disciplina.hpp"
#include "Aluno.hpp"
#include "Professor.hpp"
#include "Console.hpp"

int main(){
 
    Professor* prof{new Professor{"Paulo", 11111111111, 1000, 60}};

    Aluno a1{"Christian", 22222222222, 21, "20186713", 85.6};
    Aluno a2{"Pedro", 33333333333, 22, "20186714", 86.6};
    Aluno a3{"Maria", 44444444444, 23, "20186715", 87.6};

    Disciplina d1{"Pratica em Desenvolvimento de Software"};

    d1.setProfessor(prof);

    d1.adicionarAluno(&a1);
    d1.adicionarAluno(&a2);
    d1.adicionarAluno(&a3);

    Console::imprimirDadosDisciplina(d1);

    return 0;
}
