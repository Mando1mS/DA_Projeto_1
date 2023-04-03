

#include "../include/Graph.h"

Graph::Graph() {}

void Graph::setUnvisited() {
    for(auto &it: nodes) {
        it.second.visited = false;
    }
}

void Graph::addNode(const std::string &nome_estacao, const Estacao &estacao) {
    nodes.insert({ nome_estacao, { estacao,{},false}});//n
}

void Graph::addEdge(const std::string &source_estacao, const std::string &target_estacao,int cap,
                    const std::string &tipo)
{
    auto source = nodes.find(source_estacao);
    auto target = nodes.find(target_estacao);
    if(source == nodes.end() || target == nodes.end() || source == target) return;
    source->second.adj.push_back({target_estacao,tipo,cap});
}


int Graph::getNumEstacoes() const{
    return nodes.size();
}

