#ifndef TELA_DESENHO_HPP
#define TELA_DESENHO_HPP

#include <list>

#include "Forma.hpp"

namespace christian{
class TelaDesenho{
    public:
        TelaDesenho();
        virtual ~TelaDesenho() =  default;

        void adicionarForma(const Forma* const forma);

        double calcularAreaTotal() const;
    private:
        std::list<const Forma*> formas;
};
}
#endif