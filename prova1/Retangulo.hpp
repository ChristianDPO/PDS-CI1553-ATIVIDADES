#ifndef RETANGULO_H
#define RETANGULO_H

#include "Forma.hpp"

class Retangulo: public Forma{
	public:
		Retangulo(const float largura, const float altura);
		virtual ~Retangulo() = default;

		virtual float calcularArea() const override;
	protected:
        float largura;
		float altura;
};
#endif