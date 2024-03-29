#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <string>
#include <list>

#include "Pessoa.hpp"
#include "ConteudoMinistrado.hpp"

class SalaAula;//Forward Declaration

class Disciplina{
	public:
		Disciplina(std::string nome);
		Disciplina(std::string nome, SalaAula* sala);
		~Disciplina();

		std::string getNome() const;
		void setNome(std::string nome);
		
		int getCargaHoraria() const;
		void setCargaHoraria(unsigned int carga);

		Pessoa* getProfessor() const;
        void setProfessor(Pessoa* prof);

		void setSalaAula(SalaAula* sala);
        SalaAula* getSalaAula();

		void imprimirDados(const std::string& cabecalho, unsigned int cargaTotalCurso);

		void adicionarConteudoMinistrado(std::string conteudo, unsigned short cargaHorariaConteudo);
        void imprimirConteudosMinistrados() const;
		const std::list<ConteudoMinistrado*>& getConteudos() const;

		void removeConteudoMinistrado(unsigned long id);
		void limpaCountedos();

	private:
		std::string nome;
		unsigned short int cargaHoraria;
		Pessoa* professor;
		SalaAula* sala;

		std::list<ConteudoMinistrado*> conteudos;
};
#endif