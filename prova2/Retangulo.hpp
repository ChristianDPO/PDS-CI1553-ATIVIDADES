#ifndef RETANGULO_HPP
#define RETANTULO_HPP

#include "Forma.hpp"

#include <iomanip>

namespace christian{
class Retangulo : public Forma{
    public:
        Retangulo(const double altura, const double largura);
        virtual ~Retangulo() =  default;

        friend std::ostream& operator<<(std::ostream& stream, const Retangulo& retangulo);

        void setAltura(const double altura);
        void setLargura(const double largura);

        double getAltura() const;
        double getLargura() const;

        virtual double calcularArea() const override;
    private:
        double altura;
        double largura;
};
}
#endif