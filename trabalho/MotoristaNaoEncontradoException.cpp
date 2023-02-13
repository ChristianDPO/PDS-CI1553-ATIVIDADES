#include "MotoristaNaoEncontradoException.hpp"

using namespace frota;

MotoristaNaoEncontradoException::MotoristaNaoEncontradoException(const std::string& cpf)
    :std::runtime_error{"Motorista especificado não está cadastrado."}, cpf{cpf}{
}