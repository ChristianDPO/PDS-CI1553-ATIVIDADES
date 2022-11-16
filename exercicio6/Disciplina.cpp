#include "Disciplina.hpp"
#include "Curso.hpp"

Disciplina::Disciplina(std::string nomeDisciplina, Pessoa *professor, Curso curso)
	:nome{nomeDisciplina}, professor{professor}, tamAlunos{0}, curso{curso}{
}

std::string Disciplina::getNome(){
	return nome;
}

void Disciplina::setNome(std::string nome){
	this->nome = nome;
}

int Disciplina::getCargaHoraria(){
	return cargaHoraria;
}

void Disciplina::setCargaHoraria(unsigned int cargaHoraria){
	this->cargaHoraria = cargaHoraria;
}

Pessoa* Disciplina::getProfessor(){
	return professor;
}

void Disciplina::setProfessor(Pessoa *professor){
	this->professor = professor;
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

Curso Disciplina::getCurso(){
	return this->curso;
}