#include <iostream>
#include <vector>
#include <string>
#include "LayoutMaker.h"

int main() {
    LayoutMaker maker;
    int option;

    do {
        std::cout << "\n--- LayoutMaker++ ---\n";
        std::cout << "1 - Criar layout do zero\n";
        std::cout << "2 - Usar layout modelo default\n";
        std::cout << "0 - Sair\n";
        std::cout << "Escolha uma opcao: ";
        std::cin >> option;
        std::cin.ignore();

        if (option == 1) {
            // Criar do zero (simplificado)
            maker.clearLayout();

            std::string title, header, footer, bgColor;
            int layoutTypeChoice, themeChoice;

            std::cout << "Titulo da pagina: ";
            std::getline(std::cin, title);

            std::cout << "Cabecalho: ";
            std::getline(std::cin, header);

            std::cout << "Rodape: ";
            std::getline(std::cin, footer);

            std::cout << "Cor de fundo (ex: #ffffff): ";
            std::getline(std::cin, bgColor);

            std::cout << "Tipo de layout (0 - simples, 1 - flexbox, 2 - grid): ";
            std::cin >> layoutTypeChoice;
            std::cin.ignore();

            std::cout << "Tema (0 - claro, 1 - escuro): ";
            std::cin >> themeChoice;
            std::cin.ignore();

            maker.setTexts(title, header, footer);
            maker.setColors(bgColor);
            maker.setLayoutType(static_cast<LayoutType>(layoutTypeChoice));
            maker.setTheme(themeChoice == 0 ? Theme::LIGHT : Theme::DARK);

            int compOption;
            do {
                std::cout << "\nAdicionar componente:\n";
                std::cout << "1 - Texto\n2 - Lista\n3 - Video\n4 - Formulario contato\n5 - Portfolio\n0 - Finalizar\n";
                std::cout << "Escolha: ";
                std::cin >> compOption;
                std::cin.ignore();

                if (compOption == 1) {
                    std::string txt;
                    std::cout << "Texto: ";
                    std::getline(std::cin, txt);
                    maker.addText(txt);
                } else if (compOption == 2) {
                    int n;
                    std::cout << "Numero de itens da lista: ";
                    std::cin >> n;
                    std::cin.ignore();
                    std::vector<std::string> items(n);
                    for (int i = 0; i < n; ++i) {
                        std::cout << "Item " << i + 1 << ": ";
                        std::getline(std::cin, items[i]);
                    }
                    maker.addList(items);
                } else if (compOption == 3) {
                    std::string url;
                    std::cout << "URL do video (arquivo .mp4): ";
                    std::getline(std::cin, url);
                    maker.addVideo(url);
                } else if (compOption == 4) {
                    maker.addContactForm();
                } else if (compOption == 5) {
                    maker.addPortfolio();
                }

            } while (compOption != 0);

            maker.generateFiles("index.html", "style.css");
            std::cout << "Arquivos index.html e style.css gerados.\n";

        } else if (option == 2) {
            int tpl;
            std::cout << "Escolha modelo default:\n";
            std::cout << "1 - Portfolio simples\n";
            std::cout << "2 - Formulario contato\n";
            std::cout << "3 - Layout Flexbox\n";
            std::cout << "4 - Layout Grid\n";
            std::cout << "Escolha: ";
            std::cin >> tpl;
            std::cin.ignore();

            maker.loadDefaultTemplate(tpl);
            maker.generateFiles("index.html", "style.css");
            std::cout << "Modelo padrao carregado e arquivos gerados.\n";
        }

    } while (option != 0);

    std::cout << "Adeus!\n";
    return 0;
}
