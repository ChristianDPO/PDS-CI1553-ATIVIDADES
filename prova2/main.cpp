#include <iostream>

#include "Retangulo.hpp"
#include "Circulo.hpp"
#include "TelaDesenho.hpp"
#include "DimensaoNulaException.hpp"

int main(){

    christian::TelaDesenho tela;

    christian::Retangulo* r2{new christian::Retangulo{10,2}};
    tela.adicionarForma(r2);
    std::cout << *r2;
    
    christian::Retangulo* r3{new christian::Retangulo{10,3}};
    tela.adicionarForma(r3);
    std::cout << *r3;

    christian::Circulo* c1{new christian::Circulo{1}};
    tela.adicionarForma(c1);
    std::cout << *c1;

    christian::Circulo* c2{new christian::Circulo{2}};
    tela.adicionarForma(c2);
    std::cout << *c2;

    christian::Circulo* c3{new christian::Circulo{3}};
    tela.adicionarForma(c3);
    std::cout << *c3;

    std::cout << "*** Tentando construir um Circulo com raio 0\n";
    try{
        christian::Circulo cinv{0};
    }catch(christian::DimensaoNulaException& dnex){
        std::cout << "$$$ ERRO ao construir Circulo: " << dnex.what() << "\n";
    }

    std::cout << "*** Tentando construir um Retangulo largura ou altura como 0\n";
    try{
        christian::Retangulo rinv{0,0};
    }catch(christian::DimensaoNulaException& dnex){
        std::cout << "$$$ ERRO ao construir Retangulo: " << dnex.what() << "\n";
    }

    std::cout << "Area Total: " << tela.calcularAreaTotal() << '\n';

    return 0;
}