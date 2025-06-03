#ifndef LAYOUTMAKER_H
#define LAYOUTMAKER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class LayoutMaker {
private:
    std::vector<std::string> htmlComponents;
    std::string layoutType;
    std::string title;
    std::string bgColor;
    std::string fontColor;

    void criarLayout();
    void gerarHTML();
    void gerarCSS();
    void adicionarTexto();
    void adicionarLista();
    void adicionarVideo();
    void escolherLayoutPronto();
    void limparComponentes();
    void mostrarMenuLayout();
    void personalizarCores();
    void gerarTemplatePortfolio(); // NOVO

public:
    void menu();
};

#endif
