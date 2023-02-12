#include "ModelSistemaFrota.hpp"

#include "Moto.hpp"
#include "Carro.hpp"
#include "Van.hpp"
#include "Caminhao.hpp"

#include "VeiculoJaCadastradoException.hpp"
#include "MotoristaJaCadastradoException.hpp"

using namespace frota;

ModelSistemaFrota::ModelSistemaFrota()
    :lista_motoristas{new std::list<frota::Motorista *>}, lista_veiculos{new std::list<frota::Veiculo *>}{
} 

ModelSistemaFrota::~ModelSistemaFrota(){
}

/**
 * Retorna uma versao nao editavel da lista de veiculos
 * 
 * @return const std::list<Veiculo*>* const Ponteiro para lista de veiculos (somente leitura)
 */
const std::list<Veiculo*>* const ModelSistemaFrota::getVeiculos() const {
    const std::list<Veiculo*>* const lista{this->lista_veiculos};
    return lista;
}

/**
 * Retorna uma versao nao editavel da lista de motoristas
 * 
 * @return const std::list<Motorista*>* const Ponteiro para lista de motoristas (somente leitura)
 */
const std::list<Motorista*>* const ModelSistemaFrota::getMotoristas() const {
    const std::list<Motorista*>* const lista{this->lista_motoristas};
    return lista;
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
 * Verifica se um motorista com o mesmo cpf/cnh ja esta cadastrado no sistema
 * 
 * @param motorista Motorista motorista para verificar
 * @return bool True se o motorista eh duplicado, False caso contrario
 */
const bool ModelSistemaFrota::verificarMotoristaDuplicado(const Motorista& motorista) const{
    
    std::list<frota::Motorista *>::const_iterator it;

	for(it = this->lista_motoristas->begin(); it != this->lista_motoristas->end(); ++it)
		if (**it == motorista)
            return true;
	return false;
}

/**
 * Cadastra um motorista
 * @param nome string Nome do Motorista
 * @param cpf string CPF do Motorista (11 caracteres). Armazenado como um unsigned long
 * @param idade unsigned short int Idade do Motorista (entre 18 e 120)
 * @param cnh string Numero da Carteira Nacional de Habilitacao do Motorista (9 digitos)
 * @param cargaHoraria unsigned short int Carga horaria mensal do Motorista (entre 1 e 250 horas)
 * @param valorHora float Valor por hora trabalhada do Motorista em reais (entre 1 e 1000 reais por hora). 
 * 
 * @return *Motorista cadastrado
 * 
 * @throws std::invalid_argument Se algum dos parametros passados nao corresponde a validacao
 * @throws frota::MotoristaJaCadastradoException Se ja existe um motorista com o cpf/cnh cadastrado 
 */
Motorista *ModelSistemaFrota::cadastrarMotorista(const std::string& nome, const std::string& cpf, const unsigned short int idade,
    const std::string& cnh, unsigned short int cargaHoraria, float valorHora
){
    //aqui ja valida os campos
    Motorista* motorista{new Motorista{nome, cpf, idade, cnh, cargaHoraria, valorHora}};

    if(this->verificarMotoristaDuplicado(*motorista))
        throw MotoristaJaCadastradoException{cpf, cnh};
    
    this->lista_motoristas->push_back(motorista);

    return motorista;
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
Veiculo *cadastrarVeiculo(const std::string& modelo, const unsigned int ano, const std::string& placa, 
    const std::string& chassi, const std::string& renavam, const float valorVenda,
    const EnumTipoCarro tipoCarro
);

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
    const std::string& chassi, const std::string& renavam, const float valorVenda,
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
    const std::string& chassi, const std::string& renavam, const float valorVenda,
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
    const std::string& chassi, const std::string& renavam, const float valorVenda,
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
    const std::string& chassi, const std::string& renavam, const float valorVenda,
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