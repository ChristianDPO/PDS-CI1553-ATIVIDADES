#ifndef MOTORISTA_NAO_ENCONTRADO_EXCEPTION
#define MOTORISTA_NAO_ENCONTRADO_EXCEPTION

#include <string>
#include <stdexcept>

namespace frota{
class MotoristaNaoEncontradoException : public std::runtime_error{
    public:
        std::string cpf;
        
        MotoristaNaoEncontradoException(const std::string& cpf);
        virtual ~MotoristaNaoEncontradoException() = default;
};
}
#endif