
#ifndef DA_PROJETO_1_GRAFO_H
#define DA_PROJETO_1_GRAFO_H

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <string>


#include "../include/Estacao.h"

class Graph {
public:
    Graph();
    Estacao *findEstacao(const std::string &nome) const;
    bool addEstacao(Estacao &e);
    bool addLinha(const std::string &A, const std::string &B, int c);
    int getNumEstacoes() const;
    std::vector<Estacao *> getEstacoes() const;
protected:
    std::vector<Estacao *> estacoes;
};


#endif //DA_PROJETO_1_GRAFO_H
