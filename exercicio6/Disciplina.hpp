#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <string>
#include "Pessoa.hpp"
#include "Curso.hpp"

class Disciplina{
	public:
		Disciplina(std::string nome, Pessoa *professor, Curso curso);

		std::string getNome();
		void setNome(std::string nome);
		
		int getCargaHoraria();
		void setCargaHoraria(unsigned int cargaHoraria);

		Pessoa *getProfessor();
		void setProfessor(Pessoa *professor);

		std::string getNomeProfessor();

		bool adicionarAluno(Pessoa* aluno);
		Pessoa **getVetorAlunos();
		int getTamAlunos();
		
		bool removerAluno(Pessoa* aluno);
		bool removerAluno(unsigned long cpfAluno);
		
		Curso getCurso();

	private:
		std::string nome;
		unsigned short int cargaHoraria;
		Pessoa *professor;

		Pessoa *alunos[50];
		int tamAlunos;

		Curso& curso;
};
#endif
