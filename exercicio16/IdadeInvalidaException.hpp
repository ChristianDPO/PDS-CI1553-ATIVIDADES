#ifndef IDADE_INVALIDA_EXCEPTION
#define IDADE_INVALIDA_EXCEPTION

#include <stdexcept>

class IdadeInvalidaException : public std::runtime_error{
    public:
        unsigned short int idade;

        IdadeInvalidaException(const unsigned short int idade);
        virtual ~IdadeInvalidaException() = default;
};
#endif