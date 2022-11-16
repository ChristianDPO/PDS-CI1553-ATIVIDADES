#include<iostream>
#include<list>

#include "Pessoa.hpp"

int main(){
    std::list<Pessoa*> pessoas;
    pessoas.push_back(new Pessoa{"Joao", 11111111111, 15});
    pessoas.push_back(new Pessoa{"Maria", 22222222222, 16});
    Pessoa* p3{new Pessoa{"Pedro", 33333333333, 20}};
    pessoas.push_back(p3);

    std::list<Pessoa*>::iterator it{pessoas.begin()};
    //removendo todas referências a Pedro
    while(it != pessoas.end()){
        if((*it)->getNome() == "Pedro"){
            delete *it;
            it = pessoas.erase(it);//it recebe o próximo item válido da lista
        }else{
            it++;
        }
    }

    return 0;
}