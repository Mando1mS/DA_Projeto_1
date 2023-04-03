
#ifndef DA_PROJETO_1_ESTACAO_H
#define DA_PROJETO_1_ESTACAO_H

#include <string>
#include "vector"


class Estacao
{
    private:

    std::string nome_;
    std::string distrito_;
    std::string concelho_;
    std::string localidade_;
    std::string linha_;

    public:
    Estacao(const std::string nome, const std::string distrito, const std::string concelho, const std::string localidade, const std::string linha);

    std::string getNome() const;
    std::string getDistrito() const;
    std::string getConcelho() const;
    std::string getLocalidade() const;
    std::string getLinha() const;
    bool operator==(const Estacao &estacao) const;
};






#endif //DA_PROJETO_1_ESTACAO_H
