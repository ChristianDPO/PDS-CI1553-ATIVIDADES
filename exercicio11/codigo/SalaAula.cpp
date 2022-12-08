#include "SalaAula.hpp"

SalaAula::SalaAula(std::string nome, unsigned int capacidade)
	:nome{nome}, capacidade{capacidade}{
}

SalaAula::~SalaAula(){
	std::cerr << "Destruindo a sala " << this->nome << "\n";
	//deixar a sala de aula nula para todas as disciplinas
	std::list<Disciplina*>::iterator it;

	for(it=this->disciplinasMinistradas.begin(); it != this->disciplinasMinistradas.end(); ){		
		//remove a sala de aula das disciplinas que a contem
		(*it)->setSalaAula(nullptr);
		it = this->disciplinasMinistradas.begin();
	}
}

std::string SalaAula::getNome() const{
	return this->nome;
}

void SalaAula::setNome(std::string nome){
	this->nome = nome;
}

unsigned int SalaAula::getCapacidade() const{
	return this->capacidade;
}

void SalaAula::setCapcidade(unsigned int capacidade){
	this->capacidade = capacidade;
}

const std::list<Disciplina*>& SalaAula::getDisciplinas() const{
    return disciplinasMinistradas;
}