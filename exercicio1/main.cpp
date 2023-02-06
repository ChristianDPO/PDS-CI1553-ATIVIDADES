#include<iostream>

#include"Pessoa.hpp"

int main(){
	Pessoa p1;
	int idade;
	std::cout << "Nome: ";
	std::cin >> p1.nome;
	std::cout << "Idade: ";
	std::cin >> idade;
	
	unsigned long cpf;

	p1.idade = idade;
	bool valido = false;
	
	std::cout << "CPF: ";
	std::cin >> cpf;
	valido = p1.validarCPF(cpf);
	
	if(!valido){
		std::cout << "CPF invalido:" << cpf << std::endl;
		return -1;
	}

	p1.cpf = cpf;
	std::cout << "Dados da pessoa: " << p1.nome << "\t" << (unsigned short int)p1.idade << "\t" << p1.cpf << std::endl;

	return 0;
}
