#include <iostream>
#include <list>

#include "Ementa.hpp"
#include "Disciplina.hpp"
#include "Console.hpp"
#include "ProfessorAdjunto.hpp"
#include "Professor.hpp"

void funcao(ufpr::Pessoa* p){
   ufpr::ProfessorAdjunto* pa{dynamic_cast<ufpr::ProfessorAdjunto*>(p)};
   if(pa != nullptr){
       std::cout << pa->getNome() << '\n';
       std::cout << "Professor adjunto. Posso chamar funcoes especificas a partir de pa agora\n";
       return;
   }
   ufpr::Professor* pr{dynamic_cast<ufpr::Professor*>(p)};
   if(pr != nullptr){
       std::cout << pr->getNome() << '\n';
       std::cout << "Professor. Posso chamar funcoes especificas a partir de pr agora\n";
       return;
   }
   std::cout << p->getNome() << '\n';
   std::cout << "Classe base\n";
   return;
}

int main(void) {
   ufpr::Professor prof{"Joao", 11111111111, 100, 40};
   ufpr::ProfessorAdjunto profAd{"Maria", 22222222222, 120, 40};
   ufpr::Pessoa pessoa{"Pedro", 33333333333};

   funcao(&prof);
   funcao(&profAd);
   funcao(&pessoa);

   return 0;
}
