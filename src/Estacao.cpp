#include "../include/Estacao.h"

Estacao::Estacao(const std::string nome, District distrito, const std::string concelho,
                 const std::string localidade, const std::string linha):nome_(nome),distrito_(distrito),concelho_(concelho),localidade_(localidade),linha_(linha) {
}

std::string Estacao::getNome() const {
    return nome_;
}

District Estacao::getDistrito() const {
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

std::string District::getNome() {
    return nome_dist;
}

int District::getCapacidade() {
    return capacidade_total;
}

void District::setNome(std::string n) {
    nome_dist=n;
}

void District::setCapacidade(int n) {
    capacidade_total=n;
}

void District::updateCapacidade(int n) {
    capacidade_total+=n;
}