#ifndef VAN_HPP
#define VAN_HPP

#include "Carro.hpp"
#include "EnumTipoCarro.hpp"

using namespace frota;

namespace frota{
class Van: public Carro{
    
    protected:

        unsigned int capacidade;

        /**
         * Imprime os dados especificos do determinado tipo do veiculo
         * 
         * @return void
         */
        virtual void imprimeDadosPorTipoVeiculo() const override;

    public:
        
        Van(const std::string& modelo, const unsigned int ano, const std::string& placa, 
            const std::string& chassi, const unsigned long renavam, const float valorVenda,
            const frota::EnumTipoCarro tipoCarro, unsigned int capacidade
        );
        
        virtual ~Van() = default;
    


};

}

#endif