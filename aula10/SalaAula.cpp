#include "SalaAula.hpp"

#include <iostream>

SalaAula::SalaAula(std::string nome, unsigned int capacidade)
	:nome{nome}, capacidade{capacidade}{
}

SalaAula::~SalaAula(){
	std::cerr << "Destruindo a sala " << this->nome << "\n";
}
    
std::string SalaAula::getNome(){
	return this->nome;
}

void SalaAula::setNome(std::string nome){
	this->nome = nome;
}

unsigned int SalaAula::getCapacidade(){
	return this->capacidade;
}

void SalaAula::setCapcidade(unsigned int capacidade){
	this->capacidade = capacidade;
}

std::list<Disciplina*>& SalaAula::getDisciplinas(){
    return disciplinasMinistradas;
}