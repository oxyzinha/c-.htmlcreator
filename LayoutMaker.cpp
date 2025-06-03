#include "layoutmaker.h"

void LayoutMaker::menu() {
    int opcao;
    do {
        std::cout << "\n=== LayoutMaker++ ===\n";
        std::cout << "1. Criar layout personalizado\n";
        std::cout << "2. Escolher layout pronto\n";
        std::cout << "3. Sair\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;
        std::cin.ignore();

        switch (opcao) {
            case 1:
                criarLayout();
                break;
            case 2:
                escolherLayoutPronto();
                break;
            case 3:
                std::cout << "Saindo...\n";
                break;
            default:
                std::cout << "Opção inválida.\n";
        }
    } while (opcao != 3);
}

void LayoutMaker::criarLayout() {
    limparComponentes();
    std::cout << "\nTítulo do site: ";
    std::getline(std::cin, title);

    personalizarCores();
    mostrarMenuLayout();
    gerarHTML();
    gerarCSS();

    std::cout << "Layout HTML e CSS gerado com sucesso!\n";
}

void LayoutMaker::personalizarCores() {
    std::cout << "Cor de fundo (ex: #ffffff): ";
    std::getline(std::cin, bgColor);
    std::cout << "Cor da fonte (ex: #000000): ";
    std::getline(std::cin, fontColor);
}

void LayoutMaker::mostrarMenuLayout() {
    int escolha;
    do {
        std::cout << "\nEscolha componentes para adicionar:\n";
        std::cout << "1. Adicionar Texto\n";
        std::cout << "2. Adicionar Lista\n";
        std::cout << "3. Adicionar Vídeo\n";
        std::cout << "4. Finalizar\n";
        std::cout << "Opção: ";
        std::cin >> escolha;
        std::cin.ignore();

        switch (escolha) {
            case 1:
                adicionarTexto();
                break;
            case 2:
                adicionarLista();
                break;
            case 3:
                adicionarVideo();
                break;
            case 4:
                break;
            default:
                std::cout << "Opção inválida.\n";
        }
    } while (escolha != 4);
}

void LayoutMaker::adicionarTexto() {
    std::string texto;
    std::cout << "Digite o texto: ";
    std::getline(std::cin, texto);
    htmlComponents.push_back("<p>" + texto + "</p>");
}

void LayoutMaker::adicionarLista() {
    int n;
    std::string item;
    std::cout << "Quantos itens? ";
    std::cin >> n;
    std::cin.ignore();
    std::string lista = "<ul>\n";
    for (int i = 0; i < n; ++i) {
        std::cout << "Item " << i + 1 << ": ";
        std::getline(std::cin, item);
        lista += "<li>" + item + "</li>\n";
    }
    lista += "</ul>";
    htmlComponents.push_back(lista);
}

void LayoutMaker::adicionarVideo() {
    std::string url;
    std::cout << "URL do vídeo (embed): ";
    std::getline(std::cin, url);
    htmlComponents.push_back("<iframe width=\"560\" height=\"315\" src=\"" + url + "\" frameborder=\"0\" allowfullscreen></iframe>");
}

void LayoutMaker::gerarHTML() {
    std::ofstream html("layout.html");
    html << "<!DOCTYPE html>\n<html lang=\"pt\">\n<head>\n";
    html << "<meta charset=\"UTF-8\">\n";
    html << "<title>" << title << "</title>\n";
    html << "<link rel=\"stylesheet\" href=\"style.css\">\n";
    html << "</head>\n<body>\n";
    html << "<h1>" << title << "</h1>\n";
    for (const auto& comp : htmlComponents) {
        html << comp << "\n";
    }
    html << "</body>\n</html>";
}

void LayoutMaker::gerarCSS() {
    std::ofstream css("style.css");
    css << "body {\n";
    css << "  background-color: " << bgColor << ";\n";
    css << "  color: " << fontColor << ";\n";
    css << "  font-family: Arial, sans-serif;\n";
    css << "  padding: 20px;\n";
    css << "}\n";
}

void LayoutMaker::limparComponentes() {
    htmlComponents.clear();
    title.clear();
    bgColor = "#ffffff";
    fontColor = "#000000";
}

void LayoutMaker::escolherLayoutPronto() {
    int escolha;
    std::cout << "\nEscolha um layout pronto:\n";
    std::cout << "1. Portfólio moderno\n";
    std::cout << "Opção: ";
    std::cin >> escolha;
    std::cin.ignore();

    switch (escolha) {
        case 1:
            gerarTemplatePortfolio();
            break;
        default:
            std::cout << "Opção inválida.\n";
    }
}

void LayoutMaker::gerarTemplatePortfolio() {
    std::ofstream html("layout.html");
    std::ofstream css("style.css");

    html << R"(<!DOCTYPE html>
<html lang="pt">
<head>
  <meta charset="UTF-8">
  <title>Portfólio - Lara Oliveira</title>
  <link rel="stylesheet" href="style.css">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
</head>
<body>
  <header>
    <div class="container">
      <h1>Lara Oliveira</h1>
      <p>Desenvolvedora Criativa</p>
    </div>
  </header>

  <main class="container">
    <section id="sobre">
      <h2>Sobre Mim</h2>
      <p>Sou apaixonada por tecnologia, design e resolver problemas de forma criativa. Tenho experiência em desenvolvimento web e adoro criar projetos que unem funcionalidade e estética.</p>
    </section>

    <section id="projetos">
      <h2>Projetos</h2>
      <div class="projeto">
        <h3>LayoutMaker++</h3>
        <p>Ferramenta desenvolvida em C++ para gerar layouts HTML/CSS diretamente pelo terminal.</p>
      </div>
      <div class="projeto">
        <h3>Meu Jogo Educativo</h3>
        <p>Jogo interativo voltado ao ensino de saúde mental, combinando diversão e aprendizagem.</p>
      </div>
    </section>

    <section id="contato">
      <h2>Contacto</h2>
      <p>Entre em contacto comigo pelo e-mail: <a href="mailto:lara@email.com">lara@email.com</a></p>
    </section>
  </main>

  <footer>
    <div class="container">
      <p>&copy; 2025 Lara Oliveira. Todos os direitos reservados.</p>
    </div>
  </footer>
</body>
</html>
)";

    css << R"(body {
  margin: 0;
  font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
  background-color: #f7f7fb;
  color: #333;
  line-height: 1.6;
}

.container {
  width: 90%;
  max-width: 900px;
  margin: auto;
  padding: 20px;
}

header {
  background-color: #6a5acd;
  color: white;
  padding: 40px 0;
  text-align: center;
  border-bottom: 5px solid #483d8b;
}

header h1 {
  margin: 0;
  font-size: 2.5em;
}

header p {
  margin: 5px 0 0;
  font-size: 1.2em;
}

main section {
  margin: 40px 0;
}

h2 {
  color: #483d8b;
  border-bottom: 2px solid #ccc;
  padding-bottom: 5px;
}

.projeto {
  background-color: #fff;
  border: 1px solid #ddd;
  padding: 15px;
  margin: 15px 0;
  border-radius: 8px;
  box-shadow: 0 2px 4px rgba(0,0,0,0.05);
}

a {
  color: #6a5acd;
  text-decoration: none;
}

a:hover {
  text-decoration: underline;
}

footer {
  background-color: #eee;
  text-align: center;
  padding: 20px;
  font-size: 0.9em;
  color: #555;
}
)";

    std::cout << "Template de portfólio moderno gerado com sucesso!\n";
}
