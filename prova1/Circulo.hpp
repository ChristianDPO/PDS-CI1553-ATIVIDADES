#ifndef Circulo_H
#define Circulo_H

#include "Forma.hpp"

class Circulo: public Forma{
	public:
		Circulo(const float raio);
		virtual ~Circulo() = default;

		virtual float calcularArea() const override;
	protected:
        float raio;
};
#endif