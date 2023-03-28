
#ifndef DA_PROJETO_1_ESTACAO_H
#define DA_PROJETO_1_ESTACAO_H

#include <string>
class Estacao
{
    private:

    std::string nome_;
    std::string distrito_;
    std::string municipio_;
    std::string freguesia_;
    std::string linha_;

    public:

    Estacao(const std::string nome, const std::string distrito, const std::string municipio, const std::string freguesia, const std::string linha);

    std::string getNome() const;
    std::string getDistrito() const;
    std::string getMunicipio() const;
    std::string getFreguesia() const;
    std::string getLinha() const;

    bool operator==(const Estacao &estacao) const;
};



#endif //DA_PROJETO_1_ESTACAO_H
