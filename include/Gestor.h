#include "../include/Estacao.h"
#include <vector>

#ifndef DA_PROJETO_1_GESTOR_H
#define DA_PROJETO_1_GESTOR_H

class Gestor
{
private:
    std::vector<Estacao> testeVec_;
    void LerFicheiros();
public:
    Gestor();
    void MostrarEstacoes();

};
#endif //DA_PROJETO_1_GESTOR_H
