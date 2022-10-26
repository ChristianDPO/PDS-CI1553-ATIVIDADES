#ifndef RETANGULO_H
#define RETANGULO_H

class Retangulo{
	public:

		Retangulo();
		Retangulo(float novaBase, float novaAltura);

		float getBase();
		void setBase(float novaBase);

		float getAltura();
		void setAltura(float novaAltura);

		float getArea();
		float getPerimetro();
	
	private:
        float base;
		float altura;
		float area;
		float perimetro;
};
#endif