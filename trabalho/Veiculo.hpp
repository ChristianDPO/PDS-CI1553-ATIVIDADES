#ifndef VEICULO_HPP
#define VEICULO_HPP

#include <string>

namespace frota {
class Veiculo{
    protected:
        std::string placa;
        unsigned int valor;
        unsigned int kmRodados;
    public:
        virtual ~Veiculo() = default;
};
}


#endif
