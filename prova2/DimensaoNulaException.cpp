#include "DimensaoNulaException.hpp"

using namespace christian;

DimensaoNulaException::DimensaoNulaException()
    :std::runtime_error{"As dimensões especificadas para a forma não podem ser nulas."}{
}