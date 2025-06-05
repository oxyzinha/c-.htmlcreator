#ifndef LAYOUTMAKER_H
#define LAYOUTMAKER_H

#include <string>
#include <vector>

class LayoutMaker {
private:
    std::string html;
    std::string css;
    std::string filename;

    void gerarBase();
    void finalizarHTML();
    void salvarFicheiros();

public:
    LayoutMaker();
    void menu();
    void adicionarTexto();
    void adicionarLista();
    void adicionarVideo();
    void adicionarImagem();
    void adicionarLink();
    void adicionarFormulario();
    void aplicarFlexbox();
    void aplicarGrid();
    void escolherCoresFontesAlinhamento();
    void usarTemplatePronto();
    void usarTemplateBlog(); // <-- Novo
    void salvarComo();
};

#endif
