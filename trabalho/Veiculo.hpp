#ifndef VEICULO_HPP
#define VEICULO_HPP

#include <string>

namespace frota {
class Veiculo{
    
    protected:
        // static float aliquotaPadrao

        std::string placa;
        unsigned int valor;//em centavos
        unsigned int kmRodados;
    
        
    public:
        virtual ~Veiculo() = default;

        const float calcularIPVA() const;
        virtual const float calculaTaxaVeiculo() const;

        
};
}


#endif
