#include "ModelSistemaFrota.hpp"
#include "Moto.hpp"
#include "Carro.hpp"
#include "Van.hpp"
#include "Caminhao.hpp"

#include "VeiculoJaCadastradoException.hpp"

using namespace frota;

ModelSistemaFrota::ModelSistemaFrota(
            std::list<Motorista*>* const lista_motoristas,
            std::list<Veiculo*>* const lista_veiculos
        ):lista_motoristas{lista_motoristas}, lista_veiculos{lista_veiculos}{
} 

ModelSistemaFrota::~ModelSistemaFrota(){
}

/**
 * Verifica se um veiculo com a mesma placa/renavam ja esta cadastrado no sistema
 * 
 * @param veiculo Veiculo veiculo para verificar
 * @return bool True se o veiculo eh duplicado, False caso contrario
 */
const bool ModelSistemaFrota::verificarVeiculoDuplicado(const Veiculo& veiculo) const {

    std::list<frota::Veiculo *>::const_iterator it;

	for(it = this->lista_veiculos->begin(); it != this->lista_veiculos->end(); ++it)
		if (**it == veiculo)
            return true;
	return false;

}

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
Veiculo *ModelSistemaFrota::cadastrarVeiculo(const std::string& modelo, const unsigned int ano, const std::string& placa, 
    const std::string& chassi, const std::string renavam, const float valorVenda,
    const EnumTipoCarro tipoCarro
){
    //aqui ja faz a validacao dos campos
    Carro* carro{new Carro{modelo, ano, placa, chassi, renavam, valorVenda, tipoCarro}};

    //aqui valida a duplicata
    if(this->verificarVeiculoDuplicado(*carro))
        throw VeiculoJaCadastradoException{placa, renavam};

    //insere
    this->lista_veiculos->push_back(carro);

    return carro;
}

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
Veiculo *ModelSistemaFrota::cadastrarVeiculo(const std::string& modelo, const unsigned int ano, const std::string& placa, 
    const std::string& chassi, const std::string renavam, const float valorVenda,
    const EnumTipoCarro tipoCarro, const unsigned int capacidade
){

    //aqui ja faz a validacao dos campos
    Van* van{new Van{modelo, ano, placa, chassi, renavam, valorVenda, tipoCarro, capacidade}};

    //aqui valida a duplicata
    if(this->verificarVeiculoDuplicado(*van))
        throw VeiculoJaCadastradoException{placa, renavam};

    //insere
    this->lista_veiculos->push_back(van);

    return van;
}

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
Veiculo *ModelSistemaFrota::cadastrarVeiculo(const std::string& modelo, const unsigned int ano, const std::string& placa, 
    const std::string& chassi, const std::string renavam, const float valorVenda,
    const EnumTipoMoto tipoMoto
){

    //aqui ja faz a validacao dos campos
    Moto* moto{new Moto{modelo, ano, placa, chassi, renavam, valorVenda, tipoMoto}};

    //aqui valida a duplicata
    if(this->verificarVeiculoDuplicado(*moto))
        throw VeiculoJaCadastradoException{placa, renavam};

    //insere
    this->lista_veiculos->push_back(moto);

    return moto;
}

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
Veiculo *ModelSistemaFrota::cadastrarVeiculo(const std::string& modelo, const unsigned int ano, const std::string& placa, 
    const std::string& chassi, const std::string renavam, const float valorVenda,
    const EnumTipoCaminhao tipoCaminhao, unsigned int capacidade
){
    //aqui ja faz a validacao dos campos
    Caminhao* cam{new Caminhao{modelo, ano, placa, chassi, renavam, valorVenda, tipoCaminhao, capacidade}};

    //aqui valida a duplicata
    if(this->verificarVeiculoDuplicado(*cam))
        throw VeiculoJaCadastradoException{placa, renavam};

    //insere
    this->lista_veiculos->push_back(cam);

    return cam;
} 