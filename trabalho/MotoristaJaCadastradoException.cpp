#include "MotoristaJaCadastradoException.hpp"

using namespace frota;

MotoristaJaCadastradoException::MotoristaJaCadastradoException(const std::string& cpf, const std::string& cnh)
    :std::runtime_error{"Motorista especificado ja está cadastrado."}, cpf{cpf}, cnh{cnh}{
}