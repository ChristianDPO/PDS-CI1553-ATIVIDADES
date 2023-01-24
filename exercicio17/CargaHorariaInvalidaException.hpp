#ifndef CARGA_HORARIA_INVALIDA_EXCEPTION
#define CCARGA_HORARIA_INVALIDA_EXCEPTION

#include <stdexcept>

namespace ufpr{
class CargaHorariaInvalidaException: public std::runtime_error {
    public:
        unsigned short int cargaHoraria;

        CargaHorariaInvalidaException(const unsigned short int cargaHoraria);
        virtual ~CargaHorariaInvalidaException() = default;

};
}
#endif