#include "IdadeInvalidaException.hpp"


IdadeInvalidaException::IdadeInvalidaException(const unsigned short int idade)
    :std::runtime_error{"Idade Invalida."}, idade{idade}{
}