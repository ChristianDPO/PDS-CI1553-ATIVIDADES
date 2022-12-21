#ifndef TELA_DESENHO_H
#define TELA_DESENHO_H

#include <iostream>
#include <list>

#include "Forma.hpp"

class TelaDesenho{
    
    public:
        virtual ~TelaDesenho() = default;

        void adicionarForma(Forma* const forma);
        float calcularAreaTotal() const;
    
    protected:
        std::list<Forma*> lista_formas;
};

#endif