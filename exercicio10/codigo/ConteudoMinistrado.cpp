#include "ConteudoMinistrado.hpp"

unsigned int ConteudoMinistrado::proxId{0};

ConteudoMinistrado::ConteudoMinistrado(std::string descricao, unsigned short cargaHorariaConteudo):
    descricao(descricao), cargaHorariaConteudo(cargaHorariaConteudo), id{ConteudoMinistrado::proxId}{
        ConteudoMinistrado::proxId++;
}

ConteudoMinistrado::~ConteudoMinistrado(){
	std::cerr << "Destruindo o ConteudoMinistrado " << this->descricao << "\n";
	//ao destruir, seta o proximo id como o id do conteudo destruido, que agora esta disponivel
	ConteudoMinistrado::proxId = this->id;
}

std::string& ConteudoMinistrado::getDescricao(){
	return descricao;
}

unsigned short ConteudoMinistrado::getCargaHorariaConteudo(){
	return cargaHorariaConteudo;
}

unsigned int ConteudoMinistrado::getId(){
	return id;
}