#ifndef MOTORISTA_JA_CADASTRADO_EXCEPTION
#define MOTORISTA_JA_CADASTRADO_EXCEPTION

#include <string>
#include <stdexcept>

namespace frota{
class MotoristaJaCadastradoException : public std::runtime_error{
    public:
        std::string cpf;
        std::string cnh;

        MotoristaJaCadastradoException(const std::string& cpf, const std::string& cnh);
        virtual ~MotoristaJaCadastradoException() = default;
};
}
#endif