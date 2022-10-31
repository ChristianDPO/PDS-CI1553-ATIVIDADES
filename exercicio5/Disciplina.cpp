#include "Disciplina.hpp"

Disciplina::Disciplina(std::string nomeDisciplina, Pessoa *novoProfessor)
	:nome{nomeDisciplina}, professor{novoProfessor}, tamAlunos{0}{
}

std::string Disciplina::getNome(){
	return nome;
}

void Disciplina::setNome(std::string novoNome){
	nome = novoNome;
}

int Disciplina::getCargaHoraria(){
	return cargaHoraria;
}

void Disciplina::setCargaHoraria(unsigned int novaCarga){
	cargaHoraria = novaCarga;
}

Pessoa* Disciplina::getProfessor(){
	return professor;
}

void Disciplina::setProfessor(Pessoa *novoProfessor){
	professor = novoProfessor;
}

std::string Disciplina::getNomeProfessor(){
	return professor->getNome();
}

bool Disciplina::adicionarAluno(Pessoa* aluno){
	if(tamAlunos < 50){
		alunos[tamAlunos] = aluno;
		tamAlunos++;
		return true;
	}

	return false;
}

Pessoa** Disciplina::getVetorAlunos(){
	return alunos;
}

int Disciplina::getTamAlunos(){
	return tamAlunos;
}