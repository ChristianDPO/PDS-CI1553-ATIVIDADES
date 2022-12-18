#include "Console.hpp"

#include<iostream>

void Console::imprimirDadosDisciplina(const Disciplina& disciplina){
	std::cout << "Disicplina: "<< disciplina.getNome() << std::endl;
	if(disciplina.getProfessor() != nullptr)
		std::cout << "Professor: " << disciplina.getProfessor()->getNome() << std::endl;
	else
		std::cout << "Sem professor" << std::endl;

	std::cout << "Conteudos Ministrados" << std::endl;

        std::list<ConteudoMinistrado*>::const_iterator it;
        for(it = disciplina.getConteudos().begin(); it!=disciplina.getConteudos().end(); it++){
                std::cout << "Id: " << (*it)->getId() << std::endl
                        << "Conteudo: " << (*it)->getDescricao() << std::endl
                        << "Carga: " << (*it)->getCargaHorariaConteudo() << std::endl << std::endl;

        }

        std::cout << "Alunos:" << std::endl;

        std::list<Aluno*>::const_iterator it_al;
        for(it_al = disciplina.getAlunos().begin(); it_al != disciplina.getAlunos().end(); it_al++){
                std::cout << "Nome: " << (*it_al)->getNome() << std::endl
                        << "GRR: " << (*it_al)->getGRR() << std::endl
                        << "IRA: " << (*it_al)->getIRA() << std::endl << std::endl;

        }

}