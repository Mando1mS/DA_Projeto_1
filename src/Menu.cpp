#include "../include/Menu.h"
#include "../include/Gestor.h"
#include <iostream>
#include <string>


Menu::Menu():gestor_(Gestor()) {}
void Menu::iniciarMenu() {
    while(true) {
        std::cout << "--------------------------------------------------------\n";
        std::cout << "|      Bem vindo a gestao ferroviaria de Portugal      |\n";
        std::cout << "|                                                      |\n";
        std::cout << "| 1 - Numero maximo de comboios                        |\n";
        std::cout << "| 2 - Vizualizar Rede                                  |\n";
        std::cout << "| 3 - Transportation needs                             |\n";
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
                MenuMaximo();
                break;
            case '2':
                MenuViz();
                break;
            case '3':
                MenuNeeds();
                break;
            case '9':
                break;
            case '0':
                exit(3);
                return;
        }
    }
}


void Menu::MenuMaximo() {
    while(true) {
        std::cout << "--------------------------------------------------------\n";
        std::cout << "|            Numero maximo de comboios                 |\n";
        std::cout << "|                                                      |\n";
        std::cout << "| 1 - Entre duas estacoes                              |\n";
        std::cout << "| 2 - Que chegam em uma unica estacao                  |\n";
        std::cout << "| 3 - Estacoes com maior numero maximo de comboios     |\n";
        std::cout << "|                                                      |\n";
        std::cout << "|                                                      |\n";
        std::cout << "| 9 - Go back                                          |\n";
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
                MaxFlow();
                break;
            case '2':
                MaxToStation();
                break;
            case '3':
                TopEstacoes();
                break;
            case '9':
                iniciarMenu();
                break;
            case '0':
                exit(3);
                return;
        }
    }
}

void Menu::MaxFlow() {
    string source,target;
    int opt;
    cout << "Introduza o nome da primeira estacao: ";
    cin >> source;
    cout << "\n";
    cout << "Introduza o nome da segunda estacao: ";
    cin >> target;
    cout << "\n";
    try {
        cout << "Numero maximo de comboios que podem viajar entre " << source << " e " << target << ": "
             << gestor_.maxFlow(source, target);
    }
    catch(exception) {
        cout << "Numero maximo de comboios que podem viajar entre " << source << " e " << target << ": " << 0;

    }
    cout << "\n";
    cout << "Para voltar ao menu digite o numero '9' : ";
    while (opt!=9)
    {
        cin >> opt;cout << "\n";
        if(opt==9)
        {
            MenuMaximo();
        }
        else
        {
            cout << "Opcao invalida tente novamente... ";
            cout << "\n";
        }
    }
}

void Menu::MaxToStation() {
    string station;
    cout << "Introduza o nome da estação: " << "\n";
    try {
        cin >> station;
    }
    catch (exception) {
        cout << "Estação Inválida";
    }
    int res = gestor_.MaxArrivingTrains(station);
    cout << "\n" << "Numero maximo de comboios que podem chegar em simultâneo: " << res;
    cout << "\n";
    cout << "Para voltar ao menu digite o numero '9' : ";
    int opt = 0;
    while (opt!=9)
    {
        cin >> opt;cout << "\n";
        if(opt==9)
        {
            MenuMaximo();
        }
        else
        {
            cout << "Opcao invalida tente novamente... ";
            cout << "\n";
        }
    }
}

void Menu::TopEstacoes() {
    auto lista =gestor_.topestacoes();
    int cont=1;
    for(auto est:lista)
    {
        cout << "Numero " << cont << ": ";
        cout << "\n";
        cont++;
        cout << "Estacao 1: " << est.first << " Estacao 2: " << est.second << "\n";
    }
    int opt;
    cout << "\n";
    cout << "Para voltar ao menu digite o numero '9' : ";
    while (opt!=9)
    {
        cin >> opt;cout << "\n";
        if(opt==9)
        {
            MenuMaximo();
        }
        else
        {
            cout << "Opcao invalida tente novamente... ";
            cout << "\n";
        }
    }
}

void Menu::MenuViz() {
    while (true) {
        std::cout << "--------------------------------------------------------\n";
        std::cout << "|                    Vizualizar Rede                   |\n";
        std::cout << "|                                                      |\n";
        std::cout << "| 1 - Mostrar estacoes                                 |\n";
        std::cout << "| 2 - Mostrar network                                  |\n";
        std::cout << "|                                                      |\n";
        std::cout << "|                                                      |\n";
        std::cout << "| 9 - Go back                                          |\n";
        std::cout << "| 0 - Exit                                             |\n";
        std::cout << "--------------------------------------------------------\n";

        char opt;
        while (true) {
            std::cout << "\nOpcao: ";
            std::cin >> opt;
            if (opt <= '2' && opt >= '0' || opt == '9')
                break;
            std::cout << "Opcao invalida, escolha outra.\n";
        }

        switch (opt) {
            case '1':
                gestor_.MostrarEstacoes();
                MenuViz();
                break;
            case '2':
                gestor_.MostrarNetwork();
                MenuViz();
                break;
            case '9':
                iniciarMenu();
                break;
            case '0':
                exit(3);
                return;
        }
    }
}

void Menu::MenuNeeds() {
    while (true) {
        std::cout << "--------------------------------------------------------\n";
        std::cout << "|                    Transportation needs              |\n";
        std::cout << "|                                                      |\n";
        std::cout << "| 1 - Districts                                        |\n";
        std::cout << "| 2 - Municipality                                     |\n";
        std::cout << "|                                                      |\n";
        std::cout << "|                                                      |\n";
        std::cout << "| 9 - Go back                                          |\n";
        std::cout << "| 0 - Exit                                             |\n";
        std::cout << "--------------------------------------------------------\n";

        char opt;
        while (true) {
            std::cout << "\nOpcao: ";
            std::cin >> opt;
            if (opt <= '2' && opt >= '0' || opt == '9')
                break;
            std::cout << "Opcao invalida, escolha outra.\n";
        }

        switch (opt) {
            case '1':
                gestor_.TransNeeds_Dist();
                MenuNeeds();
                break;
            case '2':
                gestor_.TransNeeds_Mun();
                MenuNeeds();
                break;
            case '9':
                iniciarMenu();
                break;
            case '0':
                exit(3);
                return;
        }
    }
}