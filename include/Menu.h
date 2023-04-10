
#ifndef DA_PROJETO_1_MENU_H
#define DA_PROJETO_1_MENU_H
#include "Gestor.h"
/**
 * @brief Represents the menu.
 */
class Menu{
    /**
     * @brief A manager.
     */
    Gestor gestor_;
public:
    /**
     * @brief Constructor of the Menu class.
     * @details Also creates a new Manager to execute every action needed.
     */
    Menu();
    /**
     * @brief Initializes the main menu.
     */
    void iniciarMenu();
    /**
     * @brief Initializes the max trains' menu.
     */
     void MenuMaximo();
     /**
      * @brief Opens the user-interface to calculate the maximum amount of trains that travel into a single station.
      */
     void MaxToStation();
     /**
      * @brief Opens the user-interface to calculate the maximum amount of trains that travel between 2 stations.
      */
     void MaxFlow();
     /**
      * @brief Opens the user-interface to print the top4 stations with most trains traveling simultaneously.
      */
     void TopEstacoes();
     /**
      * @brief Initializes the menu for the station and network printer.
      */
      void MenuViz();
      /**
       * @brief Initializes the menu for the transportation needs.
       */
      void MenuNeeds();
};
#endif //DA_PROJETO_1_MENU_H
