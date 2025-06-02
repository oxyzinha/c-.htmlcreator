#include "LayoutMaker.h"
#include <fstream>
#include <sstream>

// --- Implementação dos componentes ---

TextComponent::TextComponent(const std::string& txt) : text(txt) {}
std::string TextComponent::render() const {
    return "<p>" + text + "</p>\n";
}

ListComponent::ListComponent(const std::vector<std::string>& it) : items(it) {}
std::string ListComponent::render() const {
    std::ostringstream oss;
    oss << "<ul>\n";
    for (const auto& item : items) {
        oss << "  <li>" << item << "</li>\n";
    }
    oss << "</ul>\n";
    return oss.str();
}

VideoComponent::VideoComponent(const std::string& videoUrl) : url(videoUrl) {}
std::string VideoComponent::render() const {
    return "<video controls>\n  <source src=\"" + url + "\" type=\"video/mp4\">\n</video>\n";
}

std::string ContactFormComponent::render() const {
    return R"(
<form>
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
<section>
  <h2>Portfolio</h2>
  <p>Projeto 1: Descrição...</p>
  <p>Projeto 2: Descrição...</p>
</section>
)";
}

// --- Implementação da classe Layout ---

Layout::Layout(LayoutType t, Theme th) : type(t), theme(th), bgColor("#ffffff") {}

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
    std::ostringstream oss;
    oss << "<!DOCTYPE html>\n<html>\n<head>\n";
    oss << "<meta charset=\"UTF-8\">\n";
    oss << "<title>" << title << "</title>\n";
    oss << "<link rel=\"stylesheet\" href=\"style.css\">\n";
    oss << "</head>\n<body>\n";

    oss << "<header>" << header << "</header>\n";

    for (auto comp : components) {
        oss << comp->render();
    }

    oss << "<footer>" << footer << "</footer>\n";
    oss << "</body>\n</html>\n";
    return oss.str();
}

std::string Layout::generateCSS() const {
    std::ostringstream oss;
    oss << "body {\n";
    oss << "  background-color: " << bgColor << ";\n";

    if (theme == Theme::LIGHT) {
        oss << "  color: #000000;\n";
    } else {
        oss << "  color: #ffffff;\n";
        oss << "  background-color: #222222;\n";
    }

    // Layout específico
    if (type == LayoutType::FLEXBOX) {
        oss << "body { display: flex; flex-direction: column; }\n";
    } else if (type == LayoutType::GRID) {
        oss << "body { display: grid; grid-template-columns: 1fr 1fr; gap: 10px; }\n";
    }

    oss << "header, footer { padding: 10px; background: #ccc; }\n";
    return oss.str();
}

// --- Implementação da classe LayoutMaker ---

LayoutMaker::LayoutMaker() : currentLayout(LayoutType::SIMPLE, Theme::LIGHT) {}

void LayoutMaker::setLayoutType(LayoutType type) {
    currentLayout.setTheme(type);
    currentLayout.setBgColor("#ffffff"); // reset background or keep as needed
    currentLayout.setTheme(Theme::LIGHT);
    currentLayout.setTheme(Theme::LIGHT);
    currentLayout.setTheme(Theme::LIGHT);
    currentLayout.setTheme(Theme::LIGHT);
    currentLayout.setTheme(Theme::LIGHT);
    currentLayout.setTheme(Theme::LIGHT);
    currentLayout.setTheme(Theme::LIGHT);
    currentLayout.setTheme(Theme::LIGHT);
    currentLayout.setTheme(Theme::LIGHT);
    currentLayout.setTheme(Theme::LIGHT);
    currentLayout.setTheme(Theme::LIGHT);

    currentLayout.setTheme(Theme::LIGHT);
    currentLayout.setTheme(Theme::LIGHT);
    currentLayout.setTheme(Theme::LIGHT);

    currentLayout.setTheme(Theme::LIGHT);
    currentLayout.setTheme(Theme::LIGHT);

    currentLayout.setTheme(Theme::LIGHT);
    currentLayout.setTheme(Theme::LIGHT);
    currentLayout.setTheme(Theme::LIGHT);

    currentLayout.setTheme(Theme::LIGHT);
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
    currentLayout.setTitle("");
    currentLayout.setHeader("");
    currentLayout.setFooter("");
    currentLayout.setBgColor("#ffffff");
    currentLayout.setTheme(Theme::LIGHT);
}

void LayoutMaker::generateFiles(const std::string& htmlFile, const std::string& cssFile) const {
    std::ofstream html(htmlFile);
    if (html) {
        html << currentLayout.generateHTML();
        html.close();
    }

    std::ofstream css(cssFile);
    if (css) {
        css << currentLayout.generateCSS();
        css.close();
    }
}

void LayoutMaker::loadDefaultTemplate(int templateId) {
    clearLayout();
    switch (templateId) {
        case 1:
            setTexts("Meu Portfolio", "Bem-vindo ao meu portfolio", "© 2025 Lara");
            setColors("#eeeeee");
            setLayoutType(LayoutType::SIMPLE);
            addPortfolio();
            break;
        case 2:
            setTexts("Contato", "Fale conosco", "© 2025 Lara");
            setColors("#ffffff");
            setLayoutType(LayoutType::SIMPLE);
            addContactForm();
            break;
        case 3:
            setTexts("Layout Flexbox", "Header Flexbox", "Footer Flexbox");
            setColors("#dddddd");
            setLayoutType(LayoutType::FLEXBOX);
            addText("Exemplo de texto em Flexbox");
            break;
        case 4:
            setTexts("Layout Grid", "Header Grid", "Footer Grid");
            setColors("#cccccc");
            setLayoutType(LayoutType::GRID);
            addText("Exemplo de texto em Grid");
            break;
        default:
            // Template inválido, mantém vazio
            break;
    }
}

void LayoutMaker::createFromScratch() {
    clearLayout();
    // Esta função pode ser implementada conforme a lógica desejada
}
