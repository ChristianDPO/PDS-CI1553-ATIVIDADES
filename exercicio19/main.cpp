#include <iostream>
#include <list>

#include "Livro.hpp"
#include "Ementa.hpp"
#include "Disciplina.hpp"
#include "SalaAula.hpp"
#include "EnumTipoDisciplina.hpp"
#include "ConteudoMinistrado.hpp"

int main(){
    ufpr::Livro l1{"C++ How To Program", 2017};
    l1.addAutor("Paul Deitel");
    l1.addAutor("Harvey Deitel");

    ufpr::Livro l2{"The C++ Programming Language", 2013};
    l1.addAutor("Bjarne Stroustrup ");

    ufpr::Ementa* ementa1{new ufpr::Ementa{"Curso de C++. Aulas de Orientação a Objetos."}};
    ementa1->addLivro(l1);
    ementa1->addLivro(l2);

    ufpr::SalaAula* sala{new ufpr::SalaAula{"PA06", 40}};
    ufpr::Professor* prof{new ufpr::Professor{"Renato", 33333333333, 2000, 60}};
    ufpr::Pessoa* p1{new ufpr::Pessoa{"Aluno1", 11111111111}};
    ufpr::Pessoa* p2{new ufpr::Pessoa{"Aluno2", 22222222222}};


    ufpr::Disciplina* dis{new ufpr::Disciplina{"Grafos", sala, ufpr::EnumTipoDisciplina::MANDATORIA, *ementa1}};
    dis->setCargaHoraria(100);
    dis->setProfessor(prof);
    
    dis->adicionarConteudoMinistrado("Conteudo1", 30);
    dis->adicionarConteudoMinistrado("Conteudo2", 40);

    dis->adicionarAluno(p1);
    dis->adicionarAluno(p2);

    dis->imprimirDados("####Disciplina Original", 2000);

    ufpr::Disciplina disCopia{*dis};

    disCopia.imprimirDados("####Disciplina Cópia", 2000);

    //     std::cout << "Dados da Ementa Copia " << ementaCopia.getDescricao() << '\n';
    //     std::list<ufpr::Livro>::const_iterator it{ementaCopia.getLivros()->begin()};
    //     for( ; it != ementaCopia.getLivros()->end(); ++it){
    //         std::cout << it->getTitulo() << '\n';
    //     }

    std::cout << "Fim\n";
    return 0;
}

