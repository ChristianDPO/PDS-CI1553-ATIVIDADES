#ifndef FORMA_H
#define FORMA_H

class Forma{
	public:
        virtual ~Forma() = default;
        
		virtual float calcularArea() const = 0;
};
#endif