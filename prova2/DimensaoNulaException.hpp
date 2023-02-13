#ifndef DIMENSAO_NULA_EXCEPTION
#define DIMENSAO_NULA_EXCEPTION

#include <stdexcept>

namespace christian{
class DimensaoNulaException : public std::runtime_error{
    public:
        DimensaoNulaException();
        virtual ~DimensaoNulaException() = default;
};
}
#endif