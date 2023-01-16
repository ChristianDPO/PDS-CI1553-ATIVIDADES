#include <iostream>

#include "Pessoa.hpp"
#include "ProfessorEngenheiro.hpp"

int main(){
	ProfessorEngenheiro pe{"Maria", 11111111111,85, 40, 1234};

	std::cout << pe.getNome() << std::endl;

	Pessoa* p{&pe};
	std::cout << p->getNome() << std::endl;


	return 0;
}
