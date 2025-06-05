/********************************************************************************
** Form generated from reading UI file 'mainmenu.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENU_H
#define UI_MAINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainMenu
{
public:
    QPushButton *btnAdicionarTexto;
    QPushButton *btnAdicionarLista;
    QPushButton *btnAdicionarVideo;
    QPushButton *btnAdicionarImagem;
    QPushButton *btnAdicionarLink;
    QPushButton *btnAdicionarFormulario;
    QPushButton *btnLayoutFlexbox;
    QPushButton *btnLayoutGrid;
    QPushButton *btnPersonalizarEstilo;
    QPushButton *btnTemplatePortfolio;
    QPushButton *btnTemplateBlog;
    QPushButton *btnSalvar;
    QPushButton *btnSair;

    void setupUi(QWidget *MainMenu)
    {
        if (MainMenu->objectName().isEmpty())
            MainMenu->setObjectName("MainMenu");
        MainMenu->resize(636, 300);
        btnAdicionarTexto = new QPushButton(MainMenu);
        btnAdicionarTexto->setObjectName("btnAdicionarTexto");
        btnAdicionarTexto->setGeometry(QRect(20, 30, 111, 29));
        btnAdicionarLista = new QPushButton(MainMenu);
        btnAdicionarLista->setObjectName("btnAdicionarLista");
        btnAdicionarLista->setGeometry(QRect(20, 70, 111, 29));
        btnAdicionarVideo = new QPushButton(MainMenu);
        btnAdicionarVideo->setObjectName("btnAdicionarVideo");
        btnAdicionarVideo->setGeometry(QRect(20, 110, 111, 29));
        btnAdicionarImagem = new QPushButton(MainMenu);
        btnAdicionarImagem->setObjectName("btnAdicionarImagem");
        btnAdicionarImagem->setGeometry(QRect(20, 150, 141, 29));
        btnAdicionarLink = new QPushButton(MainMenu);
        btnAdicionarLink->setObjectName("btnAdicionarLink");
        btnAdicionarLink->setGeometry(QRect(20, 190, 111, 29));
        btnAdicionarFormulario = new QPushButton(MainMenu);
        btnAdicionarFormulario->setObjectName("btnAdicionarFormulario");
        btnAdicionarFormulario->setGeometry(QRect(20, 230, 241, 29));
        btnLayoutFlexbox = new QPushButton(MainMenu);
        btnLayoutFlexbox->setObjectName("btnLayoutFlexbox");
        btnLayoutFlexbox->setGeometry(QRect(220, 30, 161, 29));
        btnLayoutGrid = new QPushButton(MainMenu);
        btnLayoutGrid->setObjectName("btnLayoutGrid");
        btnLayoutGrid->setGeometry(QRect(220, 70, 141, 29));
        btnPersonalizarEstilo = new QPushButton(MainMenu);
        btnPersonalizarEstilo->setObjectName("btnPersonalizarEstilo");
        btnPersonalizarEstilo->setGeometry(QRect(220, 110, 271, 29));
        btnTemplatePortfolio = new QPushButton(MainMenu);
        btnTemplatePortfolio->setObjectName("btnTemplatePortfolio");
        btnTemplatePortfolio->setGeometry(QRect(220, 150, 221, 29));
        btnTemplateBlog = new QPushButton(MainMenu);
        btnTemplateBlog->setObjectName("btnTemplateBlog");
        btnTemplateBlog->setGeometry(QRect(220, 190, 211, 29));
        btnSalvar = new QPushButton(MainMenu);
        btnSalvar->setObjectName("btnSalvar");
        btnSalvar->setGeometry(QRect(480, 250, 111, 29));
        btnSair = new QPushButton(MainMenu);
        btnSair->setObjectName("btnSair");
        btnSair->setGeometry(QRect(280, 250, 161, 29));

        retranslateUi(MainMenu);

        QMetaObject::connectSlotsByName(MainMenu);
    } // setupUi

    void retranslateUi(QWidget *MainMenu)
    {
        MainMenu->setWindowTitle(QCoreApplication::translate("MainMenu", "Form", nullptr));
        btnAdicionarTexto->setText(QCoreApplication::translate("MainMenu", "Adicionar texto", nullptr));
        btnAdicionarLista->setText(QCoreApplication::translate("MainMenu", "Adicionar lista", nullptr));
        btnAdicionarVideo->setText(QCoreApplication::translate("MainMenu", "Adicionar v\303\255deo", nullptr));
        btnAdicionarImagem->setText(QCoreApplication::translate("MainMenu", "Adicionar imagem", nullptr));
        btnAdicionarLink->setText(QCoreApplication::translate("MainMenu", "Adicionar link", nullptr));
        btnAdicionarFormulario->setText(QCoreApplication::translate("MainMenu", "Adicionar formul\303\241rio de contacto", nullptr));
        btnLayoutFlexbox->setText(QCoreApplication::translate("MainMenu", " Aplicar layout Flexbox", nullptr));
        btnLayoutGrid->setText(QCoreApplication::translate("MainMenu", "Aplicar layout Grid", nullptr));
        btnPersonalizarEstilo->setText(QCoreApplication::translate("MainMenu", "Personalizar cores, fontes e alinhamento", nullptr));
        btnTemplatePortfolio->setText(QCoreApplication::translate("MainMenu", "Usar template pronto (Portf\303\263lio)", nullptr));
        btnTemplateBlog->setText(QCoreApplication::translate("MainMenu", "Usar template pronto (Blog)", nullptr));
        btnSalvar->setText(QCoreApplication::translate("MainMenu", "Salvar como...", nullptr));
        btnSair->setText(QCoreApplication::translate("MainMenu", "Sair e gerar ficheiro", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainMenu: public Ui_MainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H
