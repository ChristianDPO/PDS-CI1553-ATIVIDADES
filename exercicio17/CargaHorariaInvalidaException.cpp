#include "CargaHorariaInvalidaException.hpp"

using namespace ufpr;

CargaHorariaInvalidaException::CargaHorariaInvalidaException(const unsigned short int cargaHoraria)
    :std::runtime_error{"Carga Horária Invalida."}, cargaHoraria{cargaHoraria}{
}
