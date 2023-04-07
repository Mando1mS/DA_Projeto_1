#include "../include/Estacao.h"
#include "../include/Graph.h"
#include <vector>

#ifndef DA_PROJETO_1_GESTOR_H
#define DA_PROJETO_1_GESTOR_H
/**
 * Represents the manager class used to connect the other classes with the user interface.
 */
class Gestor
{
private:
    /**
     * @brief A pointer to the network graph which contains all info about the train network.
     */
    Graph* network_;
    /**
    * @brief Reads all the data saved in the files and stores them in the correct structures.
    * @details Time Complexity - O(n^3).
    */
    void LerFicheiros();
public:
    /**
     * @brief Creates a new manager.
     * @details Constructor of the "Gestor" class.
     */
    Gestor();
    void MostrarEstacoes();
    void MostrarNetwork();
    void maxFlow();

};
#endif //DA_PROJETO_1_GESTOR_H
