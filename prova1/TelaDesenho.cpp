#include "TelaDesenho.hpp"

void TelaDesenho::adicionarForma(Forma* const forma){
    this->lista_formas.push_back(forma);
}

float TelaDesenho::calcularAreaTotal() const{
    
    float area_total = 0;
    
    std::list<Forma*>::const_iterator it;
    for(it=lista_formas.begin(); it != lista_formas.end(); it++){
        area_total += (*it)->calcularArea();
    }

    return area_total;
}