#include "../include/Estacao.h"
#include "../include/Graph.h"
#include <vector>

#ifndef DA_PROJETO_1_GESTOR_H
#define DA_PROJETO_1_GESTOR_H

class Gestor
{
private:
    Graph* network_;
    void LerFicheiros();
public:
    Gestor();
    void MostrarEstacoes();

};
#endif //DA_PROJETO_1_GESTOR_H
