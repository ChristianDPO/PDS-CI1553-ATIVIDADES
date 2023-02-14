#ifndef REGEX_EXPRESSOES_HPP
#define REGEX_EXPRESSOES_HPP

#include <regex>

namespace frota{
/**
 * Classe responsavel por armazenar expressoes regex
 */
class RegexExpressoes{
    public:
        const static std::regex regexPlaca;
        const static std::regex regexChassi;
        const static std::regex regexOnzeDigitos;
        const static std::regex regexCNH;

        RegexExpressoes() = delete;
        virtual ~RegexExpressoes() = default;
};
}

#endif