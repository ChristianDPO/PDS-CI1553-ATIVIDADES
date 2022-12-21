#include <iostream>

#include "TelaDesenho.hpp"
#include "Forma.hpp"
#include "Circulo.hpp"
#include "Retangulo.hpp"

int main(){
	
	TelaDesenho tela;

	std::cout << "A area total da tela no momento eh: " << tela.calcularAreaTotal() << "\n";

	std::cout << "### Adicionado Formas a tela\n";

	std::cout << "## Adicionado retangulos com as areas:\n";

	Retangulo r1{2.0, 2.0};
	std::cout << r1.calcularArea() << "\n";
	tela.adicionarForma(&r1);

	Retangulo r2{3.0, 3.0};
	std::cout << r2.calcularArea() << "\n";
	tela.adicionarForma(&r2);

	Retangulo r3{4.0, 4.0};
	std::cout << r3.calcularArea() << "\n";
	tela.adicionarForma(&r3);

	std::cout << "A area total da tela no momento eh: " << tela.calcularAreaTotal() << "\n";

	std::cout << "## Adicionando circulos com as areas:\n";

	Circulo c1{2.0};
	std::cout << c1.calcularArea() << "\n";
	tela.adicionarForma(&c1);
	
	Circulo c2{3.0};
	std::cout << c2.calcularArea() << "\n";
	tela.adicionarForma(&c2);

	Circulo c3{4.0};
	std::cout << c3.calcularArea() << "\n";
	tela.adicionarForma(&c3);
	
	std::cout << "A area total da tela no momento eh: " << tela.calcularAreaTotal() << "\n";

	return 0;
}
