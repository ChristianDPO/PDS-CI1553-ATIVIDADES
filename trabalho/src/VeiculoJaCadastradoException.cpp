#include "VeiculoJaCadastradoException.hpp"

using namespace frota;

VeiculoJaCadastradoException::VeiculoJaCadastradoException(const std::string& renavam, const std::string& placa)
    :std::runtime_error{"Veiculo especificado ja está cadastrado."}, renavam{renavam}, placa{placa}{
}