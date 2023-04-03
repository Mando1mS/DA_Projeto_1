
#include "../include/Grafo.h"


Estacao * Graph::findEstacao(const std::string &nome) const {
    for (auto e : estacoes)
        if (e->getNome() == nome)
            return e;
    return nullptr;
}

bool Graph::addEstacao(Estacao &e) {
    if(findEstacao(e.getNome()) == nullptr) {
        estacoes.push_back(&e);
        return true;
    }
    return false;
}

bool Graph::addLinha(const std::string &A, const std::string &B, int c) {
    auto e1 = findEstacao(A);
    auto e2 = findEstacao(B);
    if (e1 == nullptr || e2 == nullptr)
        return false;
    e1->addLinha(e2, c);
    e2->addLinha(e1, c);
    return true;
}

std::vector<Estacao *> Graph::getEstacoes() const{
    return estacoes;
}

int Graph::getNumEstacoes() const{
    return estacoes.size();
}

