#ifndef EMENTA_HPP
#define EMENTA_HPP

#include <iostream>
#include <string>
#include <list>

#include "Livro.hpp"

namespace ufpr{
class Ementa{
    public:
        Ementa();
        Ementa(const std::string descricao);
        Ementa(const Ementa& ementa);//construtor de copia
        Ementa(Ementa&& ementa); //move asignment

        Ementa& operator=(Ementa&& ementa);
        const Ementa& operator=(const Ementa& ementa);

        virtual ~Ementa();

        void setDescricao(const std::string& descricao);
        const std::string& getDescricao() const;

        void addLivro(const Livro& livro);
        const std::list<Livro>* getLivros() const;

    private:
        std::string descricao;
        std::list<Livro>* livros;
};
}
#endif