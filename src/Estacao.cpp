#include "../include/Estacao.h"

Estacao::Estacao(const std::string nome, const std::string distrito, const std::string municipio,
                 const std::string freguesia, const std::string linha):nome_(nome),distrito_(distrito),municipio_(municipio),freguesia_(freguesia),linha_(linha) {
}

std::string Estacao::getNome() const {
    return nome_;
}

std::string Estacao::getDistrito() const {
    return distrito_;
}

std::string Estacao::getMunicipio() const {
    return municipio_;
}

std::string Estacao::getFreguesia() const {
    return freguesia_;
}

std::string Estacao::getLinha() const {
    return linha_;
}

bool Estacao::operator==(const Estacao &est) const {
    return  nome_==est.getNome();
}