#include "../include/Gestor.h"
#include "../include/Estacao.h"
#include <fstream>
#include <sstream>
#include <iostream>

Gestor::Gestor() {
    LerFicheiros();
}
void Gestor::LerFicheiros() {
    std::ifstream estacoes_input("../data/stations.csv");
    std::string line;
    //passar a primeira linha á frente pois tem dados desnecessários.
    getline(estacoes_input, line);
    while(getline(estacoes_input, line)) {//n^2
        std::stringstream ss(line);

        std::string nome, distrito, concelho, localidade,linha;

        getline(ss, nome, ',');//n
        getline(ss, distrito, ',');
        getline(ss, concelho, ',');
        getline(ss, localidade, ',');
        getline(ss, linha, '\r');

        Estacao estacao= Estacao(nome,distrito, concelho,localidade,linha);
        testeVec_.push_back(estacao);
    }
}

void Gestor::MostrarEstacoes() {
    for(auto est:testeVec_)
    {
        std::cout << "Nome: "<< est.getNome() << "\n";
    }
}