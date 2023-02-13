#include "VeiculoNaoEncontradoException.hpp"

using namespace frota;

VeiculoNaoEncontradoException::VeiculoNaoEncontradoException(const std::string& placa)
    :std::runtime_error{"Veiculo especificado não está cadastrado."}, placa{placa}{
}