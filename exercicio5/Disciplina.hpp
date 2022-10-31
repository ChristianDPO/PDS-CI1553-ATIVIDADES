#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <string>
#include "Pessoa.hpp"

class Disciplina{
	public:
		Disciplina(std::string nomeDisciplina, Pessoa *novoProfessor);

		std::string getNome();
		void setNome(std::string novoNome);
		
		int getCargaHoraria();
		void setCargaHoraria(unsigned int novaCarga);

		Pessoa *getProfessor();
		void setProfessor(Pessoa *novoProfessor);

		std::string getNomeProfessor();

		bool adicionarAluno(Pessoa* aluno);
		Pessoa **getVetorAlunos();
		int getTamAlunos();
		
		bool removerAluno(Pessoa* aluno);
		bool removerAluno(unsigned long cpfAluno);
		
	private:
		std::string nome;
		unsigned short int cargaHoraria;
		Pessoa *professor;

		Pessoa *alunos[50];
		int tamAlunos;
};
#endif
