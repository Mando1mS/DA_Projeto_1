
#ifndef DA_PROJETO_1_ESTACAO_H
#define DA_PROJETO_1_ESTACAO_H

#include <string>
#include "vector"

class Linha;

class Estacao
{
    private:

    std::string nome_;
    std::string distrito_;
    std::string concelho_;
    std::string localidade_;
    std::string linha_;
    std::vector<Linha *> adj;

    public:
    Estacao(const std::string nome, const std::string distrito, const std::string concelho, const std::string localidade, const std::string linha);

    std::string getNome() const;
    std::string getDistrito() const;
    std::string getConcelho() const;
    std::string getLocalidade() const;
    std::string getLinha() const;
    std::vector<Linha *> getAdj() const;
    Linha * addLinha(Estacao *dest, int c);

    bool operator==(const Estacao &estacao) const;
};

class Linha {
private:

    Estacao estacao_A;
    Estacao estacao_B;
    int capacidade;

public:

    Linha(Estacao *estacao_A, Estacao *estacao_B, int capacidade);
    Estacao getEstacao_A() const;
    Estacao getEstacao_B() const;
    int getCapacidade() const;

};



#endif //DA_PROJETO_1_ESTACAO_H
