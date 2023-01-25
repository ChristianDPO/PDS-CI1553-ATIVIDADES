#ifndef CPF_HPP
#define CPF_HPP

#include <iostream>

namespace ufpr{
class CPF{
    friend std::ostream& operator<<(std::ostream& stream, const CPF& cpf);

    public:
        CPF(const unsigned long numero);
        virtual ~CPF() = default;
        unsigned long getNumero() const;
        void setNumero(const unsigned long numero);

        bool operator==(const CPF& outro) const;
        bool operator!=(const CPF& outro) const;

        bool operator<(const CPF& outro) const;
        bool operator>(const CPF& outro) const;
        bool operator<=(const CPF& outro) const;
        bool operator>=(const CPF& outro) const;

        const CPF& operator=(const CPF& outro);
        const CPF& operator=(const unsigned long numero);
    private:
        bool validarCPF(unsigned long cpfTeste) const;
        unsigned long numero;
};
}
#endif