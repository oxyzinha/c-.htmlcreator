#include "LayoutMaker.h"
#include <fstream>
#include <sstream>
#include <iostream>

// --- Implementação dos componentes ---

TextComponent::TextComponent(const std::string& txt) : text(txt) {}

std::string TextComponent::render() const {
    return "<p>" + text + "</p>\n";
}

ListComponent::ListComponent(const std::vector<std::string>& it) : items(it) {}

std::string ListComponent::render() const {
    std::stringstream ss;
    ss << "<ul>\n";
    for (const auto& item : items) {
        ss << "  <li>" << item << "</li>\n";
    }
    ss << "</ul>\n";
    return ss.str();
}

VideoComponent::VideoComponent(const std::string& videoUrl) : url(videoUrl) {}

std::string VideoComponent::render() const {
    return "<video controls>\n  <source src=\"" + url + "\" type=\"video/mp4\">\n</video>\n";
}

std::string ContactFormComponent::render() const {
    return R"(
<form action="#" method="post">
    <label for="name">Nome:</label><br>
    <input type="text" id="name" name="name"><br>
    <label for="email">Email:</label><br>
    <input type="email" id="email" name="email"><br>
    <input type="submit" value="Enviar">
</form>
)";
}

std::string PortfolioComponent::render() const {
    return R"(
<div class="portfolio">
    <h2>Portfólio</h2>
    <p>Aqui vão seus projetos destacados.</p>
</div>
)";
}

// --- Implementação da classe Layout ---

Layout::Layout(LayoutType t, Theme th)
    : type(t), theme(th), bgColor("#ffffff"), title("Meu Layout"), header("Cabeçalho"), footer("Rodapé") {}

Layout::~Layout() {
    clearComponents();
}

void Layout::setTitle(const std::string& t) { title = t; }
void Layout::setHeader(const std::string& h) { header = h; }
void Layout::setFooter(const std::string& f) { footer = f; }
void Layout::setBgColor(const std::string& color) { bgColor = color; }
void Layout::setTheme(Theme th) { theme = th; }

void Layout::addComponent(Component* comp) {
    components.push_back(comp);
}

void Layout::clearComponents() {
    for (auto comp : components) {
        delete comp;
    }
    components.clear();
}

std::string Layout::generateHTML() const {
    std::stringstream ss;
    ss << "<!DOCTYPE html>\n<html lang=\"pt\">\n<head>\n";
    ss << "<meta charset=\"UTF-8\">\n";
    ss << "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n";
    ss << "<title>" << title << "</title>\n";
    ss << "<link rel=\"stylesheet\" href=\"style.css\">\n";
    ss << "</head>\n<body>\n";

    ss << "<header><h1>" << header << "</h1></header>\n";

    ss << "<main>\n";
    for (const auto& comp : components) {
        ss << comp->render() << "\n";
    }
    ss << "</main>\n";

    ss << "<footer><p>" << footer << "</p></footer>\n";

    ss << "</body>\n</html>\n";
    return ss.str();
}

std::string Layout::generateCSS() const {
    std::stringstream ss;

    ss << "body {\n";
    ss << "  background-color: " << bgColor << ";\n";
    ss << "  font-family: Arial, sans-serif;\n";
    ss << "  margin: 0;\n  padding: 0;\n}\n";

    ss << "header, footer {\n";
    ss << "  background-color: " << (theme == Theme::LIGHT ? "#eee" : "#333") << ";\n";
    ss << "  color: " << (theme == Theme::LIGHT ? "#333" : "#eee") << ";\n";
    ss << "  text-align: center;\n";
    ss << "  padding: 1em;\n}\n";

    ss << "main {\n  padding: 1em;\n}\n";

    ss << "ul {\n  list-style-type: disc;\n  padding-left: 20px;\n}\n";

    ss << "video {\n  max-width: 100%;\n  height: auto;\n}\n";

    ss << "form {\n  max-width: 300px;\n  margin: 0 auto;\n  padding: 1em;\n  background-color: #f9f9f9;\n  border: 1px solid #ccc;\n  border-radius: 5px;\n}\n";

    ss << "form input[type=text], form input[type=email] {\n  width: 100%;\n  padding: 0.5em;\n  margin-bottom: 1em;\n  border: 1px solid #ccc;\n  border-radius: 3px;\n}\n";

    ss << "form input[type=submit] {\n  padding: 0.7em 1.5em;\n  background-color: #28a745;\n  border: none;\n  color: white;\n  border-radius: 3px;\n  cursor: pointer;\n}\n";

    ss << "form input[type=submit]:hover {\n  background-color: #218838;\n}\n";

    ss << ".portfolio {\n  background-color: #ddd;\n  padding: 1em;\n  border-radius: 5px;\n  margin-top: 1em;\n}\n";

    return ss.str();
}

// --- Implementação da classe LayoutMaker ---

LayoutMaker::LayoutMaker() : currentLayout() {}

void LayoutMaker::setLayoutType(LayoutType type) {
    currentLayout = Layout(type, currentLayout.theme);
}

void LayoutMaker::setTheme(Theme theme) {
    currentLayout.setTheme(theme);
}

void LayoutMaker::setColors(const std::string& bg) {
    currentLayout.setBgColor(bg);
}

void LayoutMaker::setTexts(const std::string& title, const std::string& header, const std::string& footer) {
    currentLayout.setTitle(title);
    currentLayout.setHeader(header);
    currentLayout.setFooter(footer);
}

void LayoutMaker::addText(const std::string& text) {
    currentLayout.addComponent(new TextComponent(text));
}

void LayoutMaker::addList(const std::vector<std::string>& items) {
    currentLayout.addComponent(new ListComponent(items));
}

void LayoutMaker::addVideo(const std::string& url) {
    currentLayout.addComponent(new VideoComponent(url));
}

void LayoutMaker::addContactForm() {
    currentLayout.addComponent(new ContactFormComponent());
}

void LayoutMaker::addPortfolio() {
    currentLayout.addComponent(new PortfolioComponent());
}

void LayoutMaker::clearLayout() {
    currentLayout.clearComponents();
}

void LayoutMaker::generateFiles(const std::string& htmlFile, const std::string& cssFile) const {
    std::ofstream htmlOut(htmlFile);
    std::ofstream cssOut(cssFile);
    if (!htmlOut.is_open() || !cssOut.is_open()) {
        throw std::runtime_error("Erro ao abrir arquivos para escrita.");
    }
    htmlOut << currentLayout.generateHTML();
    cssOut << currentLayout.generateCSS();
    htmlOut.close();
    cssOut.close();
}

void LayoutMaker::loadDefaultTemplate(int templateId) {
    clearLayout();
    // Dois templates simples para exemplificar
    if (templateId == 1) {
        setTexts("Template Simples", "Bem-vindo ao LayoutMaker++", "Rodapé padrão");
        setColors("#ffffff");
        setTheme(Theme::LIGHT);
        addText("Este é um template simples com texto.");
        addList({"Item 1", "Item 2", "Item 3"});
    } else if (templateId == 2) {
        setTexts("Template Escuro", "LayoutMaker++ - Tema Escuro", "Rodapé escuro");
        setColors("#222222");
        setTheme(Theme::DARK);
        addText("Este template usa tema escuro.");
        addVideo("video_exemplo.mp4");
    }
}

void LayoutMaker::createFromScratch() {
    clearLayout();
    std::string input;
    std::cout << "Criando layout do zero.\n";
    std::cout << "Defina o título: ";
    std::getline(std::cin, input);
    setTexts(input, "", "");

    std::cout << "Defina o cabeçalho: ";
    std::getline(std::cin, input);
    currentLayout.setHeader(input);

    std::cout << "Defina o rodapé: ";
    std::getline(std::cin, input);
    currentLayout.setFooter(input);

    std::cout << "Defina a cor de fundo (ex: #ffffff): ";
    std::getline(std::cin, input);
    currentLayout.setBgColor(input);

    int compChoice;
    do {
        std::cout << "\nEscolha o componente para adicionar:\n";
        std::cout << "1 - Texto\n2 - Lista\n3 - Vídeo\n4 - Formulário de Contato\n5 - Portfólio\n0 - Finalizar\n";
        std::cout << "Opção: ";
        std::cin >> compChoice;
        std::cin.ignore(); // limpar buffer

        if (compChoice == 1) {
            std::cout << "Digite o texto: ";
            std::getline(std::cin, input);
            addText(input);
        } else if (compChoice == 2) {
            std::vector<std::string> items;
            std::cout << "Digite os itens da lista (vazio para terminar):\n";
            while (true) {
                std::getline(std::cin, input);
                if (input.empty()) break;
                items.push_back(input);
            }
            addList(items);
        } else if (compChoice == 3) {
            std::cout << "Digite a URL do vídeo: ";
            std::getline(std::cin, input);
            addVideo(input);
        } else if (compChoice == 4) {
            addContactForm();
        } else if (compChoice == 5) {
            addPortfolio();
        }
    } while (compChoice != 0);

    std::cout << "Layout criado.\n";
}
