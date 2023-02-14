#ifndef VEICULO_JA_CADASTRADO_EXCEPTION
#define VEICULO_JA_CADASTRADO_EXCEPTION

#include <string>
#include <stdexcept>

namespace frota{
class VeiculoJaCadastradoException : public std::runtime_error{
    public:
        std::string renavam;
        std::string placa;

        VeiculoJaCadastradoException(const std::string& renavam, const std::string& placa);
        virtual ~VeiculoJaCadastradoException() = default;
};
}
#endif