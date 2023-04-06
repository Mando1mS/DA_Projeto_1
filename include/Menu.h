
#ifndef DA_PROJETO_1_MENU_H
#define DA_PROJETO_1_MENU_H
#include "Gestor.h"

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
     * @brief Clears the current screen.
     */
    void LimparTela();
};
#endif //DA_PROJETO_1_MENU_H
