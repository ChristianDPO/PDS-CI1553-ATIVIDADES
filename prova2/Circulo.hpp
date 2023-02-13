#ifndef CIRCULO_HPP
#define CIRCULO_HPP

#include "Forma.hpp"
#include <iomanip>

namespace christian{
class Circulo : public Forma{
    public:
        Circulo(const double raio);
        virtual ~Circulo() =  default;

        void setRaio(const double raio);
        double getRaio() const;

        virtual double calcularArea() const override;

        friend std::ostream& operator<<(std::ostream& stream, const Circulo& circulo);

    private:
        double raio;
};
}
#endif