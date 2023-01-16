#include "Engenheiro.hpp"

#include<iostream>

const unsigned int Engenheiro::SALARIO_PADRAO{9405};

Engenheiro::Engenheiro(const std::string& nome, const unsigned long cpf,
		const unsigned short int idade, const unsigned int numeroCrea)
	:Pessoa{nome, cpf, idade}, numeroCrea{numeroCrea}{
}

Engenheiro::~Engenheiro(){}

unsigned int Engenheiro::getSalario() const{
        return Engenheiro::SALARIO_PADRAO;
}
unsigned int Engenheiro::getNumeroCrea() const{
	return this->numeroCrea;
}

void Engenheiro::setNumeroCrea(const unsigned int numeroCrea){
	this->numeroCrea = numeroCrea;
}
