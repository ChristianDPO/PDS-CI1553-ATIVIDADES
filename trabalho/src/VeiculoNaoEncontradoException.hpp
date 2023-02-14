#ifndef VEICULO_NAO_ENCONTRADO_EXCEPTION
#define VEICULO_NAO_ENCONTRADO_EXCEPTION

#include <string>
#include <stdexcept>

namespace frota{
class VeiculoNaoEncontradoException : public std::runtime_error{
    public:
        std::string placa;
        
        VeiculoNaoEncontradoException(const std::string& placa);
        virtual ~VeiculoNaoEncontradoException() = default;
};
}
#endif