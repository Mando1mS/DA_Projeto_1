#include "../include/Gestor.h"
#include "../include/Estacao.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>

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
        network_->addEdge(target, source, std::stoi(cap),tipo);
    }

}

void Gestor::MostrarEstacoes() {
    for(auto est:network_->nodes)
    {
        cout << left << setw(6) << "Nome: " << setw(40) << est.second.estacao.getNome() << setw(10) << "Distrito: " << setw(30) << est.second.estacao.getDistrito() << "\n";
    }
}

void Gestor::MostrarNetwork()
{
    for(auto est:network_->nodes)
    {
        auto u=est.second;
        for(auto lig:u.adj)
        {
            cout << left << setw(13) << "Nome source: " << setw(40) << u.estacao.getNome() << setw(13) << "Nome destino: " << setw(30) << lig.dest << "\n";
        }
    }
    for(auto a: network_->nodes.at("Espinho").adj)
    {
        cout << a.dest << "\n";
    }
}

void Gestor::maxFlow() {
    string nome_estacaoA;
    string nome_estacaoB;
    int flowsum = 0;
    cout << "Escolha a estacao de partida: ";
    cin >> nome_estacaoA;
    cout << "Escolha a estacao final: ";
    cin >> nome_estacaoB;
    cout << "Maximum flow between " << nome_estacaoA << " and " << nome_estacaoB << ": " << "\n";
    cout << network_->maxFlow(nome_estacaoA, nome_estacaoB) << "\n";
}
    /*for(auto e:network_->getShortestpaths()) {
        if(e.size()!=0) {
            for(auto e2:e) {
                cout << "\n" << "Estacao: " << setw(30) << e2 << " \x19 \n";
            }
            cout << "Tamanho: " << e.size() << "\n";
            cout << "Maximum flow: " << flow << "\n";
            cout <<"\n";
            cout <<"\n";
            cout << "Outro caminho... \n";
        }
    }*/
