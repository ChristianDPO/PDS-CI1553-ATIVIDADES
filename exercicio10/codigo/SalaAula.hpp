#ifndef SALA_AULA_H
#define SALA_AULA_H

#include <iostream>
#include <string>
#include <list>

#include "Disciplina.hpp"

class SalaAula{
	friend void Disciplina::setSalaAula(SalaAula* salaAula);

	public:
		SalaAula(std::string nome, unsigned int capacidade);
		~SalaAula();
		
		std::string getNome();
		void setNome(std::string nome);

		unsigned int getCapacidade();
		void setCapcidade(unsigned int capacidade);

        std::list<Disciplina*>& getDisciplinas();
	private:
		std::string nome;
		unsigned int capacidade;
		std::list<Disciplina*> disciplinasMinistradas;
};
#endif