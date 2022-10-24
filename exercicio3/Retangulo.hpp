#ifndef RETANGULO_H
#define RETANGULO_H

class Retangulo{
	public:
		float getBase();
		void setBase(float novaBase);

		float getAltura();
		void setAltura(float novaAltura);

		float getArea();
		float getPerimetro();
	
	private:
        float base = 0;
		float altura = 0;
		float area = -1;
		float perimetro = -1;
};
#endif