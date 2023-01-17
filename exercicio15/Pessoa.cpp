#include "Pessoa.hpp"

#include<iostream>

/*Pessoa::Pessoa(){
	std::cout << "Construtor default de pessoa" << std::endl;
}*/

Pessoa::Pessoa(std::string nome)
		:nome{nome}{
	std::cout << "Construtor de pessoa com nome " <<  std::endl;
}

Pessoa::Pessoa(std::string nome,  unsigned short int idade)
		:nome{nome},idade{(unsigned char)idade}{
	std::cout << "Construtor de pessoa com nome e idade " <<  std::endl;
}

Pessoa::Pessoa(std::string nome, unsigned long cpf, unsigned short int idade)
		:Pessoa{nome, idade}{
	if(validarCPF(cpf))
		this->cpf = cpf;
	else
		this->cpf = 0;
	std::cout << "Construtor de pessoa com nome idade e cpf" <<  std::endl;
}

Pessoa::~Pessoa(){
	//std::cout << "Destrutor de Pessoa " << std::endl;
}

unsigned long Pessoa::getCpf(){
	//retorna uma cópia do cpf
	return this->cpf;
}

bool Pessoa::setCpf(unsigned long cpf){
	if(validarCPF(cpf)){
		this->cpf = cpf;
		return true;
	}
	return false;
}

std::string Pessoa::getNome() const{
	return this->nome;
}

void Pessoa::setNome(const std::string& nome){
	this->nome = nome;
}

unsigned short int Pessoa::getIdade(){
	return (unsigned short int)idade;
}

void Pessoa::setIdade(unsigned short int idade){
	this->idade = (unsigned char)idade;
}

void Pessoa::imprimirEnderecoMemoria(){
	std::cout << this << std::endl;
}

bool Pessoa::validarCPF(unsigned long cpfTeste){
	int somatorioValidaUltimo;
	int modulo;
	int somatorioValidaPenultimo = 0;
	int ultimo = cpfTeste%10;
	cpfTeste = cpfTeste/10;
	int penultimo = cpfTeste%10;
	cpfTeste = cpfTeste/10;
	
	somatorioValidaUltimo = penultimo*2;
	for(int i=2; i <= 11; i++){
		modulo = cpfTeste%10;
		cpfTeste = cpfTeste/10;
		somatorioValidaPenultimo += modulo*i;
		somatorioValidaUltimo += modulo*(i+1);
	}
	modulo = somatorioValidaPenultimo%11;
	if(modulo < 2){
		if(!penultimo)
			return false;//cpf invalido
	}else{
		if(penultimo != 11 - modulo)
			return false;//cpf invalido
	}
	modulo = somatorioValidaUltimo%11;
	if(modulo < 2){
		if(!ultimo)
			return false;//cpf invalido
	}else{
		if(ultimo != 11-modulo)
			return false;//cpf invalido
	}
	return true;//cpf valido
}
