#include "../include/Menu.h"
#include "../include/Gestor.h"
#include <iostream>


Menu::Menu():gestor_(Gestor()) {}

void Menu::iniciarMenu() {
    while(true) {
        LimparTela();
        std::cout << "--------------------------------------------------------\n";
        std::cout << "|      Bem vindo á gestão ferroviária de Portugal      |\n";
        std::cout << "|                                                      |\n";
        std::cout << "| 1 - Opcao 1                                          |\n";
        std::cout << "| 2 - Opcao 2                                          |\n";
        std::cout << "| 3 - Opcao 3                                          |\n";
        std::cout << "|                                                      |\n";
        std::cout << "|                                                      |\n";
        std::cout << "| 9 - Settings                                         |\n";
        std::cout << "| 0 - Exit                                             |\n";
        std::cout << "--------------------------------------------------------\n";

        char opt;
        while(true) {
            std::cout << "\nOption: ";
            std::cin >> opt;
            if(opt <= '3' && opt >= '0' || opt == '9')
                break;
            std::cout << "Not a valid option, please choose another.\n";
        }

        switch(opt) {
            case '1':
                //inputFlights();
                break;
            case '2':
                //airportInfo();
                break;
            case '3':
                //airlineInfo();
                break;
            case '9':
                //settings();
                break;
            default:
                LimparTela();
                return;
        }
    }
}
}

void Menu::LimparTela() {
    std::cout << "\033[2J\033[1;1H";
}