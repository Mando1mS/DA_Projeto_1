#include "../include/Menu.h"
#include "../include/Gestor.h"
#include <iostream>
#include <string>


Menu::Menu():gestor_(Gestor()) {}

void Menu::iniciarMenu() {
    std::string s;
    std::string t;
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
                //cout << "Escolha a estacao de partida: ";
                //cin >> s;
                //cout << "Escolha a estacao final: ";
                //cin >> t;
                gestor_.testeBFS("Espinho","Porto Campanhã");
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