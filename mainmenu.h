#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>
#include <QString>      // Para manipular strings HTML
#include <QFile>        // Para gravar ficheiro
#include <QTextStream>  // Para escrever no ficheiro
#include <QInputDialog> // Para diálogos de input
#include <QMessageBox>  // Para mensagens de confirmação

QT_BEGIN_NAMESPACE
namespace Ui { class MainMenu; }
QT_END_NAMESPACE

class MainMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = nullptr);
    ~MainMenu();

private slots:
    void on_btnAdicionarTexto_clicked();
    void on_btnAdicionarLista_clicked();
    void on_btnAdicionarVideo_clicked();
    void on_btnAdicionarImagem_clicked();
    void on_btnAdicionarLink_clicked();
    void on_btnAdicionarFormulario_clicked();
    void on_btnLayoutFlexbox_clicked();
    void on_btnLayoutGrid_clicked();
    void on_btnPersonalizarEstilo_clicked();
    void on_btnTemplatePortfolio_clicked();
    void on_btnTemplateBlog_clicked();
    void on_btnSalvar_clicked();
    void on_btnSair_clicked();
    void on_btnNovoProjeto_clicked();

private:
    Ui::MainMenu *ui;
    QString htmlContent;  // Armazena o conteúdo HTML do layout
};

#endif // MAINMENU_H
