#include<iostream>

#include"Pessoa.hpp"

int main(){
	unsigned short int idade;
	unsigned long cpf;
	std::string nome;

	std::cout << "Nome: ";
	std::cin >> nome;
	std::cout << "Idade: ";
	std::cin >> idade;
	std::cout << "CPF: ";
	std::cin >> cpf;
	
	Pessoa p1(nome, idade, cpf);

	std::cout << "Dados da pessoa: " << p1.getNome() << "\t" << p1.getIdade() << "\t" << p1.getCPF() << std::endl;

	return 0;
}
