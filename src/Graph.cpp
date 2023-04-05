

#include "../include/Graph.h"
using namespace std;
Graph::Graph() {}

void Graph::setUnvisited() {
    for(auto &it: nodes) {
        it.second.visited = false;
        it.second.path= "";
        it.second.travel_from_src.clear();
    }
}

void Graph::addNode(const std::string &nome_estacao, const Estacao &estacao) {
    nodes.insert({ nome_estacao, { estacao,{},false,list<list<pair<Estacao,string>>>()}});//n
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

void Graph::bfs(const std::string &nome_estacao) {
    setUnvisited();

    std::queue<std::string> q; // queue of unvisited nodes
    q.push(nome_estacao);
    nodes.at(nome_estacao).visited = true;
    nodes.at(nome_estacao).travel_from_src.push_back({ { nodes.at(nome_estacao).estacao, "" } });

    while(!q.empty()) {
        std::string u = q.front();
        q.pop();
        Node& node = nodes.at(u);
        for(const auto &e: node.adj) {
            std::string w = e.dest;

            if(!nodes.at(w).visited) {
                q.push(w);
                nodes.at(w).visited = true;
                for(auto n: node.travel_from_src) {
                    n.push_back({nodes.at(w).estacao, e.serv});
                    nodes.at(w).travel_from_src.push_back(n);
                }
            }
            else if (node.travel_from_src.front().size()+1==nodes.at(w).travel_from_src.front().size()){
                bool flag = true;
                for (auto n : nodes.at(w).travel_from_src) { //if all possibilities wanted comment this for loop
                    auto it = n.end();
                    std::advance(it,-2);
                    if (it->first==node.estacao) {
                        flag= false;
                        break;
                    }
                }
                if (!flag) continue;
                for(auto n: node.travel_from_src) {
                    n.push_back({nodes.at(w).estacao,e.serv});
                    nodes.at(w).travel_from_src.push_back(n);
                }
            }
        }
    }
}

void Graph::max_flow(const std::string &nome_estacaoA,const std::string &nome_estacaoB)
{
    bfs(nome_estacaoA);
    auto shortpath=nodes.at(nome_estacaoB).travel_from_src.size();
    setUnvisited();
}
void Graph::bfs2p(const std::string &nome_estacaoA)
{
    queue<string> q; // queue of unvisited nodes
    q.push(nome_estacaoA);
    setUnvisited();
    nodes.at(nome_estacaoA).visited = true;
    while(!q.empty())
    {
        string node=q.front();
        q.pop();
        auto neighbour=nodes.at(node);
        for(auto u:neighbour.adj)
        {
            auto newnode=u.dest;
            if(!nodes.at(newnode).visited)
            {
                q.push(newnode);
                nodes.at(newnode).visited=true;
                nodes.at(newnode).path=node;
            }
        }
    }
}
