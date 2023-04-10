
#ifndef DA_PROJETO_1_ESTACAO_H
#define DA_PROJETO_1_ESTACAO_H

#include <string>
#include "vector"

/**
 * Represents a District.
 */
class District{
private:
    /**
     * @brief Name of the district.
     */
    std::string nome_dist;
    /**
     * @brief Total capacity.
     * @details Total amount of trains that travel simultaneously in that district.
     */
    int capacidade_total;
public:
    /**
     * @brief Gets the name of the district.
     * @return The district's name.
     */
    std::string getNome();
    /**
     * @brief Gets the total capacity.
     * @return Maximum amount of trains simultaneously traveling in a district.
     */
    int getCapacidade();
    /**
     * @brief Sets the name of the district.
     * @param n The district's name.
     */
    void setNome(std::string n);
    /**
     * @brief Sets the total capacity.
     * @param n Capacity to be set.
     */
    void setCapacidade(int n);
    /**
     * @brief Updates the current district capacity.
     * @param n Capacity to be added.
     */
    void updateCapacidade(int n);
    /**
     * @brief Compares the equality between two districts.
     * @param dist District to be compared.
     * @return True- If dist's capacity is higher.
     * @return False- If dist's capacity is lower.
     */
    bool operator<(const District &dist);
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
