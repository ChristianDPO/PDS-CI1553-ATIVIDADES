#include "RegexExpressoes.hpp"
#include <regex>

using namespace frota;

const std::regex frota::RegexExpressoes::regexPlaca{std::regex("^[A-Z]{3}[0-9]{1}[[A-Z]{1}[0-9]{2}$")};