#include "layoutmaker.h"
#include <iostream>
#include <fstream>

LayoutMaker::LayoutMaker() {
    html = "";
    css = "";
    filename = "layout";
}

void LayoutMaker::gerarBase() {
    html = "<!DOCTYPE html>\n<html>\n<head>\n<meta charset='UTF-8'>\n<title>Layout Maker</title>\n<link rel='stylesheet' href='style.css'>\n</head>\n<body>\n";
    html += "<header>\n<h1>Bem-vindo ao LayoutMaker++</h1>\n</header>\n<main>\n";
    css = "body {\n  font-family: Arial, sans-serif;\n  padding: 20px;\n  background-color: #f9f9f9;\n  color: #333;\n}\n";
    css += "header { background-color: #222; color: white; padding: 20px; text-align: center; }\n";
    css += "footer { background-color: #ddd; color: #000; padding: 10px; text-align: center; }\n";
}

void LayoutMaker::finalizarHTML() {
    html += "</main>\n<footer>\n<p>Gerado por LayoutMaker++</p>\n</footer>\n</body>\n</html>";
}

void LayoutMaker::salvarFicheiros() {
    finalizarHTML();
    std::ofstream htmlFile(filename + ".html");
    std::ofstream cssFile("style.css");
    htmlFile << html;
    cssFile << css;
    htmlFile.close();
    cssFile.close();
    std::cout << "Ficheiros '" << filename << ".html' e 'style.css' salvos com sucesso.\n";
}

void LayoutMaker::menu() {
    int opcao;
    gerarBase();
    do {
        std::cout << "\n--- MENU LAYOUTMAKER++ ---\n";
        std::cout << "1. Adicionar texto\n";
        std::cout << "2. Adicionar lista\n";
        std::cout << "3. Adicionar vídeo\n";
        std::cout << "4. Adicionar imagem\n";
        std::cout << "5. Adicionar link\n";
        std::cout << "6. Adicionar formulário de contacto\n";
        std::cout << "7. Aplicar layout Flexbox\n";
        std::cout << "8. Aplicar layout Grid\n";
        std::cout << "9. Personalizar cores, fontes e alinhamento\n";
        std::cout << "10. Usar template pronto (Portfólio)\n";
        std::cout << "11. Usar template pronto (Blog)\n";
        std::cout << "12. Salvar como...\n";
        std::cout << "0. Sair e gerar ficheiro\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;
        std::cin.ignore();

        switch(opcao) {
            case 1: adicionarTexto(); break;
            case 2: adicionarLista(); break;
            case 3: adicionarVideo(); break;
            case 4: adicionarImagem(); break;
            case 5: adicionarLink(); break;
            case 6: adicionarFormulario(); break;
            case 7: aplicarFlexbox(); break;
            case 8: aplicarGrid(); break;
            case 9: escolherCoresFontesAlinhamento(); break;
            case 10: usarTemplatePronto(); return;
            case 11: usarTemplateBlog(); return;
            case 12: salvarComo(); break;
            case 0: salvarFicheiros(); break;
            default: std::cout << "Opção inválida!\n";
        }

    } while(opcao != 0);
}

void LayoutMaker::adicionarTexto() {
    std::string texto;
    std::cout << "Digite o texto a adicionar: ";
    std::getline(std::cin, texto);
    html += "<p>" + texto + "</p>\n";
}

void LayoutMaker::adicionarLista() {
    int n;
    std::cout << "Quantos itens terá a lista? ";
    std::cin >> n;
    std::cin.ignore();
    html += "<ul>\n";
    for (int i = 0; i < n; ++i) {
        std::string item;
        std::cout << "Item " << i+1 << ": ";
        std::getline(std::cin, item);
        html += "  <li>" + item + "</li>\n";
    }
    html += "</ul>\n";
}

void LayoutMaker::adicionarVideo() {
    std::string url;
    std::cout << "URL do vídeo (embed): ";
    std::getline(std::cin, url);
    html += "<iframe width='560' height='315' src='" + url + "' frameborder='0' allowfullscreen></iframe>\n";
}

void LayoutMaker::adicionarImagem() {
    std::string src, alt;
    std::cout << "URL da imagem: ";
    std::getline(std::cin, src);
    std::cout << "Texto alternativo: ";
    std::getline(std::cin, alt);
    html += "<img src='" + src + "' alt='" + alt + "' style='max-width:100%;'>\n";
}

void LayoutMaker::adicionarLink() {
    std::string url, texto;
    std::cout << "URL do link: ";
    std::getline(std::cin, url);
    std::cout << "Texto do link: ";
    std::getline(std::cin, texto);
    html += "<a href='" + url + "' target='_blank'>" + texto + "</a>\n";
}

void LayoutMaker::adicionarFormulario() {
    html += "<form action='#' method='post'>\n";
    html += "  <label for='nome'>Nome:</label><br>\n";
    html += "  <input type='text' id='nome' name='nome'><br><br>\n";
    html += "  <label for='email'>Email:</label><br>\n";
    html += "  <input type='email' id='email' name='email'><br><br>\n";
    html += "  <label for='mensagem'>Mensagem:</label><br>\n";
    html += "  <textarea id='mensagem' name='mensagem'></textarea><br><br>\n";
    html += "  <input type='submit' value='Enviar'>\n";
    html += "</form>\n";
}

void LayoutMaker::aplicarFlexbox() {
    css += "\n.flex {\n  display: flex;\n  gap: 20px;\n}\n";
    html += "<div class='flex'>\n  <div>Item 1</div>\n  <div>Item 2</div>\n  <div>Item 3</div>\n</div>\n";
}

void LayoutMaker::aplicarGrid() {
    css += "\n.grid {\n  display: grid;\n  grid-template-columns: repeat(3, 1fr);\n  gap: 20px;\n}\n";
    html += "<div class='grid'>\n  <div>Bloco A</div>\n  <div>Bloco B</div>\n  <div>Bloco C</div>\n</div>\n";
}

void LayoutMaker::escolherCoresFontesAlinhamento() {
    std::string corFundo, corTexto, fonte, alinhamento;
    std::cout << "Cor de fundo (ex: #f0f0f0): ";
    std::getline(std::cin, corFundo);
    std::cout << "Cor do texto (ex: #000000): ";
    std::getline(std::cin, corTexto);
    std::cout << "Fonte (ex: Arial): ";
    std::getline(std::cin, fonte);
    std::cout << "Alinhamento do texto (left, center, right): ";
    std::getline(std::cin, alinhamento);

    css += "\nbody {\n";
    css += "  background-color: " + corFundo + ";\n";
    css += "  color: " + corTexto + ";\n";
    css += "  font-family: " + fonte + ";\n";
    css += "  text-align: " + alinhamento + ";\n";
    css += "}\n";
}

void LayoutMaker::usarTemplatePronto() {
    html = "<!DOCTYPE html>\n<html>\n<head>\n<title>Portfólio</title>\n<link rel='stylesheet' href='style.css'>\n</head>\n<body>\n";
    html += "<h1>Meu Portfólio</h1>\n<p>Bem-vindo ao meu site!</p>\n";
    html += "<img src='https://via.placeholder.com/300' alt='Imagem'>\n";
    html += "<p><a href='#'>Saiba mais</a></p>\n</body>\n</html>\n";

    css = "body { font-family: Verdana; background-color: #f4f4f4; text-align: center; padding: 50px; }\n";
    salvarFicheiros();
}

void LayoutMaker::usarTemplateBlog() {
    html = "<!DOCTYPE html>\n<html>\n<head>\n<meta charset='UTF-8'>\n<title>Blog</title>\n<link rel='stylesheet' href='style.css'>\n</head>\n<body>\n";
    html += "<header><h1>Meu Blog</h1></header>\n<main>\n";
    html += "<article>\n<h2>Primeiro Post</h2>\n<small>Publicado em 4 de junho de 2025</small>\n<p>Este é o conteúdo do meu primeiro post no blog. Espero que gostem!</p>\n</article>\n";
    html += "<article>\n<h2>Segundo Post</h2>\n<small>Publicado em 3 de junho de 2025</small>\n<p>Aqui vai outro post interessante. Este blog é gerado com C++!</p>\n</article>\n";
    html += "</main>\n<footer>\n<p>© 2025 Meu Blog. Todos os direitos reservados.</p>\n</footer>\n</body>\n</html>\n";

    css = "body { font-family: Georgia, serif; margin: 0; padding: 0; background-color: #fff; color: #222; }\n";
    css += "header { background-color: #333; color: white; padding: 20px; text-align: center; }\n";
    css += "main { padding: 20px; }\n";
    css += "article { border-bottom: 1px solid #ccc; margin-bottom: 20px; padding-bottom: 20px; }\n";
    css += "footer { background-color: #eee; color: #000; padding: 10px; text-align: center; }\n";
    salvarFicheiros();
}

void LayoutMaker::salvarComo() {
    std::cout << "Nome do ficheiro HTML (sem extensão): ";
    std::getline(std::cin, filename);
    std::cout << "Salvando como '" << filename << ".html'...\n";
}
