
#ifndef DA_PROJETO_1_ESTACAO_H
#define DA_PROJETO_1_ESTACAO_H

#include <string>
#include "vector"


class District{
private:
    std::string nome_dist;
    int capacidade_total;
public:
    std::string getNome();
    int getCapacidade();
    void setNome(std::string n);
    void setCapacidade(int n);
    void updateCapacidade(int n);
};

/**
 * Represents a station.
 */
class Estacao
{
    private:
    /**
     * @brief Name of the station.
     * @details The name of the station is unique and so it is possible to identify which station is referenced by its name.
     */
    std::string nome_;
    /**
     * @brief District the station belongs to.
     */
    District distrito_;
    /**
     * @brief Municipality the station belongs to.
     */
    std::string concelho_;
    /**
     * @brief Township the station belongs to.
     */
    std::string localidade_;
    /**
     * @brief The line which the station operates on.
     */
    std::string linha_;

    public:
    /**
     * @brief Creates a new station.
     * @details Constructor of the "Estacao" class.
     * @param nome Station's name.
     * @param distrito District.
     * @param concelho Municipality.
     * @param localidade Township.
     * @param linha Line of network.
     */
    Estacao(const std::string nome, const District distrito, const std::string concelho, const std::string localidade, const std::string linha);
    /**
     * @brief Gets the name of the station.
     * @return Station's name..
     */
    std::string getNome() const;
    /**
     * @brief Gets the name of the District the station belongs to.
     * @return District's name..
     */
    District getDistrito() const;
    /**
     * @brief Gets the name of the Municipality the station belongs to.
     * @return Township's name..
     */
    std::string getConcelho() const;
    /**
     * @brief Gets the name of the Township the station belongs to.
     * @return Township's name.
     */
    std::string getLocalidade() const;
    /**
     * @brief Gets the line the station operates on.
     * @return Line's name.
     */
    std::string getLinha() const;
    /**
     * @brief Compares the equality between two stations.
     * @param estacao Station to be compared.
     * @return True- If both names are the same.
     * @return False- If the names are not equal.
     */
    bool operator==(const Estacao &estacao) const;
};






#endif //DA_PROJETO_1_ESTACAO_H
