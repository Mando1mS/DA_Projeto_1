#include "../include/Menu.h"
#include "../include/Gestor.h"
#include <iostream>


Menu::Menu():gestor_(Gestor()) {}

void Menu::iniciarMenu() {
    while(true) {
        LimparTela();
        std::cout << "--------------------------------------------------------\n";
        std::cout << "|      Bem vindo a gestao ferroviaria de Portugal      |\n";
        std::cout << "|                                                      |\n";
        std::cout << "| 1 - Mostrar Estacoes                                 |\n";
        std::cout << "| 2 - Mostrar Network                                  |\n";
        std::cout << "| 3 - maxFlow                                          |\n";
        std::cout << "|                                                      |\n";
        std::cout << "|                                                      |\n";
        std::cout << "| 9 - Settings                                         |\n";
        std::cout << "| 0 - Exit                                             |\n";
        std::cout << "--------------------------------------------------------\n";

        char opt;
        while(true) {
            std::cout << "\nOpcao: ";
            std::cin >> opt;
            if(opt <= '3' && opt >= '0' || opt == '9')
                break;
            std::cout << "Opcao invalida, escolha outra.\n";
        }

        switch(opt) {
            case '1':
                gestor_.MostrarEstacoes();
                break;
            case '2':
                gestor_.MostrarNetwork();
                break;
            case '3':
                int s, t;
                cout << "Escolha a estação de partida: ";
                cin >> s;
                cout << "Escolha a estação final: ";
                cin >> t;
                gestor_.maxFlow(s, t);
                break;
            case '9':
                break;
            default:
                LimparTela();
                return;
        }
    }
}


void Menu::LimparTela() {
    std::cout << "\033[2J\033[1;1H";
}