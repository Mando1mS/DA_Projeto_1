#include "../include/Gestor.h"
#include "../include/Estacao.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

Gestor::Gestor() {
    network_=new Graph();
    LerFicheiros();
}
void Gestor::LerFicheiros() {
    std::ifstream estacoes_input("../data/stations.csv");
    std::ifstream network_input("../data/network.csv");
    std::string line;
    //passar a primeira linha á frente pois tem dados desnecessários.
    getline(estacoes_input, line);
    getline(network_input, line);
    while(getline(estacoes_input, line)) {//n^2
        std::stringstream ss(line);

        std::string nome, distrito, concelho, localidade,linha;

        getline(ss, nome, ',');//n
        getline(ss, distrito, ',');
        getline(ss, concelho, ',');
        getline(ss, localidade, ',');
        getline(ss, linha, '\r');

        Estacao estacao= Estacao(nome,distrito, concelho,localidade,linha);
        network_->addNode(nome,estacao);
    }
    while(getline(network_input, line)) {
        std::stringstream ss(line);

        std::string source, target,cap, tipo;

        getline(ss, source, ',');
        getline(ss, target, ',');
        getline(ss, cap, ',');
        getline(ss, tipo, '\r');

        network_->addEdge(source, target, std::stoi(cap),tipo);
    }

}

void Gestor::MostrarEstacoes() {
    for(auto est:network_->nodes)
    {
        cout <<"Nome: " << est.second.estacao.getNome() << " Distrito: " << est.second.estacao.getDistrito() << "\n";
    }
}