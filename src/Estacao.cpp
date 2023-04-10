#include "../include/Estacao.h"

Estacao::Estacao(const std::string nome, District distrito, const Municipality concelho,
                 const std::string localidade, const std::string linha):nome_(nome),distrito_(distrito),concelho_(concelho),localidade_(localidade),linha_(linha) {
}

std::string Estacao::getNome() const {
    return nome_;
}

District Estacao::getDistrito() const {
    return distrito_;
}

Municipality Estacao::getConcelho() const {
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

bool District::operator<(const District &dist)
{
    return capacidade_total>dist.capacidade_total;
}

std::string Municipality::Mun_getNome() {
    return nome_mun;
}

int Municipality::Mun_getCapacidade() {
    return captotal;
}

void Municipality::Mun_setNome(std::string n) {
    nome_mun=n;
}

void Municipality::Mun_setCapacidade(int n) {
    captotal=n;
}

void Municipality::Mun_updateCapacidade(int n) {
    captotal+=n;
}

bool Municipality::operator<(const Municipality &mun)
{
    return captotal>mun.captotal;
}

bool Municipality::operator==(const Municipality &mun) {
    return nome_mun==mun.nome_mun;
}