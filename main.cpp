#include <QApplication>
#include "mainmenu.h"  // sua janela gráfica MainMenu

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MainMenu window;   // cria a janela
    window.show();     // mostra a janela na tela

    return app.exec(); // executa o loop da aplicação Qt
}
