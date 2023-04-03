#include "../include/Estacao.h"

Estacao::Estacao(const std::string nome, const std::string distrito, const std::string concelho,
                 const std::string localidade, const std::string linha):nome_(nome),distrito_(distrito),concelho_(concelho),localidade_(localidade),linha_(linha) {
}

std::string Estacao::getNome() const {
    return nome_;
}

std::string Estacao::getDistrito() const {
    return distrito_;
}

std::string Estacao::getConcelho() const {
    return concelho_;
}

std::string Estacao::getLocalidade() const {
    return localidade_;
}

std::string Estacao::getLinha() const {
    return linha_;
}


bool Estacao::operator==(const Estacao &est) const {
    return  nome_==est.getNome();
}


