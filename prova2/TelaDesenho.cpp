#include "TelaDesenho.hpp"

using namespace christian;
TelaDesenho::TelaDesenho(){}

void TelaDesenho::adicionarForma(const Forma* const forma){
    this->formas.push_back(forma);
}

double TelaDesenho::calcularAreaTotal() const{
    std::list<const Forma*>::const_iterator it{this->formas.begin()};
    double soma{0};
    for( ;it != this->formas.end(); ++it)
        soma+= (*it)->calcularArea();
    return soma;
}