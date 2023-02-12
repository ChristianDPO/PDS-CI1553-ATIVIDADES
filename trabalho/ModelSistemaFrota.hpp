#ifndef MODEL_SISTEMA_FROTA_HPP
#define MODEL_SISTEMA_FROTA_HPP

#include "Veiculo.hpp"
#include "Motorista.hpp"

#include "EnumTipoVeiculo.hpp"
#include "EnumTipoCarro.hpp"
#include "EnumTipoMoto.hpp"
#include "EnumTipoCaminhao.hpp"


#include <list>

namespace frota{
class ModelSistemaFrota{

    private:
        std::list<Motorista*>* const lista_motoristas;
        std::list<Veiculo*>* const lista_veiculos;
    
    public:
        ModelSistemaFrota(
            std::list<Motorista*>* const lista_motoristas,
            std::list<Veiculo*>* const lista_veiculos
        );
        virtual ~ModelSistemaFrota();

    /**
     * Verifica se um veiculo com a mesma placa/renavam ja esta cadastrado no sistema
     * 
     * @param veiculo Veiculo veiculo para verificar
     * @return bool True se o veiculo eh duplicado, False caso contrario
     */
    const bool verificarVeiculoDuplicado(const Veiculo& veiculo) const;

    /**
     * Cadastra um veiculo (Carro)
     * 
     * @param modelo string Nome/modelo do veiculo
     * @param ano unsigned int Ano de fabricacao do veiculo (1886 ate 2023)
     * @param placa string Numero da placa do veiculo (string com 7 digitos alfanumericos)
     * @param chassi string Numero do chassi do veiculo (string com 17 digitos alfanumericos)
     * @param renavam string Numero do Renavam do veiculo (string com 11 digitos numericos). Armazenado em um unsigned long
     * @param valorVenda float Valor da venda do veiculo (em reais). Armazenado em um unsigned int em centavos
     * @param tipoCarro EnumTipoCarro Tipo do Carro
     * 
     * @return *Veiculo Veiculo cadastrado
     * 
     * @throws std::invalid_argument Se algum dos parametros passados nao corresponde a validacao
     * @throws frota::VeiculoJaCadastradoException Se ja existe um veiculo com a placa/renavam cadastrado 
     */
    Veiculo *cadastrarVeiculo(const std::string& modelo, const unsigned int ano, const std::string& placa, 
        const std::string& chassi, const std::string renavam, const float valorVenda,
        const EnumTipoCarro tipoCarro
    );
    /**
     * Cadastra um veiculo (Van)
     * 
     * @param modelo string Nome/modelo do veiculo
     * @param ano unsigned int Ano de fabricacao do veiculo (1886 ate 2023)
     * @param placa string Numero da placa do veiculo (string com 7 digitos alfanumericos)
     * @param chassi string Numero do chassi do veiculo (string com 17 digitos alfanumericos)
     * @param renavam string Numero do Renavam do veiculo (string com 11 digitos numericos). Armazenado em um unsigned long
     * @param valorVenda float Valor da venda do veiculo (em reais). Armazenado em um unsigned int em centavos
     * @param tipoCarro EnumTipoCarro Tipo do Carro
     * @param capacidade unsigned int Capacidade da Van
     * 
     * @return *Veiculo Veiculo cadastrado
     * 
     * @throws std::invalid_argument Se algum dos parametros passados nao corresponde a validacao
     * @throws frota::VeiculoJaCadastradoException Se ja existe um veiculo com a placa/renavam cadastrado 
     */
    Veiculo *cadastrarVeiculo(const std::string& modelo, const unsigned int ano, const std::string& placa, 
        const std::string& chassi, const std::string renavam, const float valorVenda,
        const EnumTipoCarro tipoCarro, const unsigned int capacidade
    );
    /**
     * Cadastra um veiculo (Moto)
     * 
     * @param modelo string Nome/modelo do veiculo
     * @param ano unsigned int Ano de fabricacao do veiculo (1886 ate 2023)
     * @param placa string Numero da placa do veiculo (string com 7 digitos alfanumericos)
     * @param chassi string Numero do chassi do veiculo (string com 17 digitos alfanumericos)
     * @param renavam string Numero do Renavam do veiculo (string com 11 digitos numericos). Armazenado em um unsigned long
     * @param valorVenda float Valor da venda do veiculo (em reais). Armazenado em um unsigned int em centavos
     * @param tipoMoto EnumTipoMoto Tipo da Moto
     * 
     * @return *Veiculo Veiculo cadastrado
     * 
     * @throws std::invalid_argument Se algum dos parametros passados nao corresponde a validacao
     * @throws frota::VeiculoJaCadastradoException Se ja existe um veiculo com a placa/renavam cadastrado 
     */
    Veiculo *cadastrarVeiculo(const std::string& modelo, const unsigned int ano, const std::string& placa, 
        const std::string& chassi, const std::string renavam, const float valorVenda,
        const EnumTipoMoto tipoMoto
    );
    /**
     * Cadastra um veiculo (Caminhao)
     * 
     * @param modelo string Nome/modelo do veiculo
     * @param ano unsigned int Ano de fabricacao do veiculo (1886 ate 2023)
     * @param placa string Numero da placa do veiculo (string com 7 digitos alfanumericos)
     * @param chassi string Numero do chassi do veiculo (string com 17 digitos alfanumericos)
     * @param renavam string Numero do Renavam do veiculo (string com 11 digitos numericos). Armazenado em um unsigned long
     * @param valorVenda float Valor da venda do veiculo (em reais). Armazenado em um unsigned int em centavos
     * @param tipoCarro EnumTipoCarro Tipo do Carro
     * @param capacidade unsigned int Capacidade da Van
     * 
     * @return *Veiculo Veiculo cadastrado
     * 
     * @throws std::invalid_argument Se algum dos parametros passados nao corresponde a validacao
     * @throws frota::VeiculoJaCadastradoException Se ja existe um veiculo com a placa/renavam cadastrado 
     */
    Veiculo *cadastrarVeiculo(const std::string& modelo, const unsigned int ano, const std::string& placa, 
        const std::string& chassi, const std::string renavam, const float valorVenda,
        const EnumTipoCaminhao tipoCaminhao, unsigned int capacidade
    ); 

};
}

#endif