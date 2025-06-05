#include "mainmenu.h"
#include "ui_mainmenu.h"
#include <QMessageBox>
#include <QInputDialog>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>

MainMenu::MainMenu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainMenu)
{
    ui->setupUi(this);

    // Inicializa o conteúdo HTML básico
    htmlContent = "<!DOCTYPE html>\n<html>\n<head>\n<title>LayoutMaker++</title>\n<style>\nbody { font-family: Arial; padding: 20px; }\n</style>\n</head>\n<body>\n";
}

MainMenu::~MainMenu()
{
    delete ui;
}

// 1. Adicionar texto
void MainMenu::on_btnAdicionarTexto_clicked()
{
    QString texto = QInputDialog::getText(this, "Adicionar Texto", "Insere o texto:");
    if (!texto.isEmpty()) {
        htmlContent += "<p>" + texto.toHtmlEscaped() + "</p>\n";
    }
}

// 2. Adicionar lista
void MainMenu::on_btnAdicionarLista_clicked()
{
    QString itens = QInputDialog::getText(this, "Adicionar Lista", "Insere itens separados por vírgula:");
    if (!itens.isEmpty()) {
        htmlContent += "<ul>\n";
        for (const QString &item : itens.split(",")) {
            htmlContent += "  <li>" + item.trimmed().toHtmlEscaped() + "</li>\n";
        }
        htmlContent += "</ul>\n";
    }
}

// 3. Adicionar vídeo
void MainMenu::on_btnAdicionarVideo_clicked()
{
    QString url = QInputDialog::getText(this, "Adicionar Vídeo", "Insere a URL do vídeo:");
    if (!url.isEmpty()) {
        htmlContent += "<video controls width='480'><source src='" + url.toHtmlEscaped() + "' type='video/mp4'>Vídeo não suportado</video>\n";
    }
}

// 4. Adicionar imagem
void MainMenu::on_btnAdicionarImagem_clicked()
{
    QString url = QInputDialog::getText(this, "Adicionar Imagem", "Insere a URL da imagem:");
    if (!url.isEmpty()) {
        htmlContent += "<img src='" + url.toHtmlEscaped() + "' alt='Imagem' style='max-width:100%;'/>\n";
    }
}

// 5. Adicionar link
void MainMenu::on_btnAdicionarLink_clicked()
{
    QString url = QInputDialog::getText(this, "Adicionar Link", "Insere a URL:");
    QString texto = QInputDialog::getText(this, "Texto do Link", "Texto a exibir:");
    if (!url.isEmpty() && !texto.isEmpty()) {
        htmlContent += "<a href='" + url.toHtmlEscaped() + "'>" + texto.toHtmlEscaped() + "</a><br/>\n";
    }
}

// 6. Adicionar formulário de contacto
void MainMenu::on_btnAdicionarFormulario_clicked()
{
    htmlContent +=
        "<form>\n"
        "  <label>Nome:</label><br/>\n"
        "  <input type='text' name='nome'><br/>\n"
        "  <label>Email:</label><br/>\n"
        "  <input type='email' name='email'><br/>\n"
        "  <label>Mensagem:</label><br/>\n"
        "  <textarea name='mensagem'></textarea><br/>\n"
        "  <input type='submit' value='Enviar'>\n"
        "</form>\n";
}

// 7. Aplicar layout Flexbox
void MainMenu::on_btnLayoutFlexbox_clicked()
{
    htmlContent +=
        "<style>\n"
        ".flex-container {\n"
        "  display: flex;\n"
        "  gap: 10px;\n"
        "}\n"
        ".flex-item {\n"
        "  background: #e0e0e0;\n"
        "  padding: 10px;\n"
        "  flex: 1;\n"
        "}\n"
        "</style>\n"
        "<div class='flex-container'>\n"
        "  <div class='flex-item'>Item 1</div>\n"
        "  <div class='flex-item'>Item 2</div>\n"
        "  <div class='flex-item'>Item 3</div>\n"
        "</div>\n";
}

// 8. Aplicar layout Grid
void MainMenu::on_btnLayoutGrid_clicked()
{
    htmlContent +=
        "<style>\n"
        ".grid-container {\n"
        "  display: grid;\n"
        "  grid-template-columns: repeat(3, 1fr);\n"
        "  gap: 10px;\n"
        "}\n"
        ".grid-item {\n"
        "  background: #d0d0d0;\n"
        "  padding: 10px;\n"
        "  text-align: center;\n"
        "}\n"
        "</style>\n"
        "<div class='grid-container'>\n"
        "  <div class='grid-item'>Bloco 1</div>\n"
        "  <div class='grid-item'>Bloco 2</div>\n"
        "  <div class='grid-item'>Bloco 3</div>\n"
        "</div>\n";
}

// 9. Personalizar cores, fontes e alinhamento
void MainMenu::on_btnPersonalizarEstilo_clicked()
{
    QString cor = QInputDialog::getText(this, "Cor de fundo", "Cor em hexadecimal (#ffffff):");
    QString fonte = QInputDialog::getText(this, "Fonte", "Nome da fonte (ex: Verdana):");
    QString alinhamento = QInputDialog::getItem(this, "Alinhamento", "Escolhe o alinhamento:", {"left", "center", "right"}, 1, false);

    if (!cor.isEmpty() || !fonte.isEmpty() || !alinhamento.isEmpty()) {
        htmlContent += "<style>body { ";
        if (!cor.isEmpty()) htmlContent += "background-color: " + cor + "; ";
        if (!fonte.isEmpty()) htmlContent += "font-family: " + fonte + "; ";
        if (!alinhamento.isEmpty()) htmlContent += "text-align: " + alinhamento + "; ";
        htmlContent += "}</style>\n";
    }
}

// 10. Usar template pronto (Portfólio)
void MainMenu::on_btnTemplatePortfolio_clicked()
{
    htmlContent += R"(
<!DOCTYPE html>
<html lang="pt">
<head>
<meta charset="UTF-8" />
<meta name="viewport" content="width=device-width, initial-scale=1.0"/>
<title>Seu Nome - Portfólio Profissional</title>
<link href="https://fonts.googleapis.com/css2?family=Montserrat:wght@400;600;700&family=Roboto:wght@300;400;500&display=swap" rel="stylesheet">
<style>
    :root {
        --primary-color: #2c3e50; /* Azul escuro / Preto */
        --accent-color: #3498db; /* Azul vibrante */
        --light-bg: #f5f7fa; /* Fundo cinza claro */
        --dark-bg: #2c3e50;
        --text-color: #333;
        --light-text: #ecf0f1; /* Para texto em fundos escuros */
        --border-radius-lg: 10px;
        --shadow-elevation-1: 0 4px 12px rgba(0,0,0,0.08);
        --shadow-elevation-2: 0 8px 25px rgba(0,0,0,0.15);
        --transition-speed: 0.3s ease-in-out;
    }

    /* Reset básico e tipografia */
    * {
        margin: 0;
        padding: 0;
        box-sizing: border-box;
    }

    body {
        font-family: 'Roboto', sans-serif;
        background: var(--light-bg);
        color: var(--text-color);
        line-height: 1.7;
        min-height: 100vh;
        display: flex;
        flex-direction: column;
        scroll-behavior: smooth; /* Rolagem suave para âncoras */
    }

    h1, h2, h3 {
        font-family: 'Montserrat', sans-serif;
        color: var(--primary-color);
        margin-bottom: 1rem;
    }

    h1 { font-size: 3rem; }
    h2 { font-size: 2.2rem; }
    h3 { font-size: 1.6rem; }

    p {
        font-size: 1.05rem;
        margin-bottom: 1rem;
    }

    a {
        text-decoration: none;
        color: var(--accent-color);
        transition: color var(--transition-speed);
    }

    a:hover {
        color: darken(var(--accent-color), 10%); /* Uma cor ligeiramente mais escura no hover */
    }

    /* Utilitários */
    .container {
        max-width: 1100px;
        margin: 0 auto;
        padding: 0 1.5rem;
    }

    /* Navegação */
    nav {
        background-color: var(--primary-color);
        padding: 1rem 0;
        box-shadow: var(--shadow-elevation-1);
        position: sticky; /* Sticky nav */
        top: 0;
        z-index: 1000; /* Garante que fica por cima de outros elementos */
    }

    nav .container {
        display: flex;
        justify-content: center;
        align-items: center;
    }

    nav ul {
        list-style: none;
        display: flex;
        gap: 2.5rem;
    }

    nav a {
        color: var(--light-text);
        font-weight: 600;
        font-size: 1.1rem;
        padding: 0.5rem 0;
        position: relative;
    }

    nav a::after { /* Linha inferior no hover */
        content: '';
        position: absolute;
        bottom: 0;
        left: 50%;
        width: 0;
        height: 2px;
        background-color: var(--accent-color);
        transition: width var(--transition-speed), left var(--transition-speed);
    }

    nav a:hover::after {
        width: 100%;
        left: 0;
    }

    /* Secção Hero (Cabeçalho principal) */
    .hero {
        background: linear-gradient(rgba(44, 62, 80, 0.8), rgba(44, 62, 80, 0.8)), url('https://source.unsplash.com/random/1920x1080/?coding,design,workspace') no-repeat center center/cover;
        color: var(--light-text);
        text-align: center;
        padding: 8rem 1.5rem;
        display: flex;
        flex-direction: column;
        justify-content: center;
        align-items: center;
        min-height: 70vh; /* Altura mínima para o hero */
        animation: fadeIn 1s ease-out;
    }

    .hero h1 {
        color: var(--light-text);
        font-size: 4.5rem;
        margin-bottom: 1rem;
        line-height: 1.1;
        text-shadow: 0 4px 15px rgba(0,0,0,0.4);
        animation: slideInLeft 1s ease-out;
    }

    .hero p {
        font-size: 1.6rem;
        font-weight: 300;
        max-width: 700px;
        margin-top: 0;
        animation: slideInRight 1s ease-out 0.3s forwards;
        opacity: 0;
    }

    @keyframes fadeIn {
        from { opacity: 0; }
        to { opacity: 1; }
    }

    @keyframes slideInLeft {
        from { opacity: 0; transform: translateX(-50px); }
        to { opacity: 1; transform: translateX(0); }
    }

    @keyframes slideInRight {
        from { opacity: 0; transform: translateX(50px); }
        to { opacity: 1; transform: translateX(0); }
    }

    /* Secções gerais */
    section {
        padding: 4rem 0;
        opacity: 0; /* Para animação de scroll */
        transform: translateY(20px); /* Para animação de scroll */
        transition: opacity 0.8s ease-out, transform 0.8s ease-out;
    }

    section.fade-in { /* Classe adicionada por JavaScript no scroll */
        opacity: 1;
        transform: translateY(0);
    }

    section:nth-of-type(even) { /* Fundo alternado para legibilidade */
        background-color: var(--white);
    }

    section h2 {
        text-align: center;
        margin-bottom: 3rem;
        position: relative;
    }

    section h2::after { /* Linha decorativa abaixo do título */
        content: '';
        display: block;
        width: 60px;
        height: 4px;
        background-color: var(--accent-color);
        margin: 0.8rem auto 0;
        border-radius: 2px;
    }

    /* Secção Sobre Mim */
    .about-content {
        display: flex;
        flex-wrap: wrap;
        gap: 2rem;
        align-items: center;
        justify-content: center;
    }

    .about-image {
        flex: 1;
        min-width: 250px;
        max-width: 350px;
        text-align: center;
    }

    .about-image img {
        width: 100%;
        height: auto;
        border-radius: var(--border-radius-lg);
        box-shadow: var(--shadow-elevation-1);
    }

    .about-text {
        flex: 2;
        min-width: 300px;
    }

    /* Secção Projetos */
    .project-grid {
        display: grid;
        grid-template-columns: repeat(auto-fit, minmax(300px, 1fr));
        gap: 2rem;
    }

    .project-card {
        background: var(--white);
        border-radius: var(--border-radius-lg);
        overflow: hidden;
        box-shadow: var(--shadow-elevation-1);
        transition: transform var(--transition-speed), box-shadow var(--transition-speed);
        display: flex;
        flex-direction: column;
    }

    .project-card:hover {
        transform: translateY(-10px);
        box-shadow: var(--shadow-elevation-2);
    }

    .project-card img {
        width: 100%;
        height: 220px; /* Altura fixa para as imagens dos projetos */
        object-fit: cover;
        transition: transform 0.5s ease;
    }

    .project-card:hover img {
        transform: scale(1.05); /* Zoom na imagem ao passar o rato */
    }

    .project-content {
        padding: 1.5rem;
        flex-grow: 1; /* Ocupa o espaço restante */
        display: flex;
        flex-direction: column;
    }

    .project-content h3 {
        margin-top: 0;
        margin-bottom: 0.5rem;
        color: var(--accent-color);
    }

    .project-content p {
        font-size: 0.95rem;
        color: #666;
        flex-grow: 1; /* Para a descrição ocupar o espaço e o link ficar no fundo */
    }

    .project-links {
        margin-top: 1rem;
    }

    .project-links a {
        display: inline-block;
        background-color: var(--accent-color);
        color: var(--white);
        padding: 0.7rem 1.2rem;
        border-radius: 5px;
        font-size: 0.9rem;
        font-weight: 500;
        transition: background-color var(--transition-speed);
    }

    .project-links a:hover {
        background-color: #2980b9; /* Cor mais escura no hover */
    }

    /* Secção Contacto */
    .contact-info {
        text-align: center;
    }

    .contact-info p {
        font-size: 1.1rem;
        margin-bottom: 0.8rem;
    }

    .social-links {
        margin-top: 2rem;
    }

    .social-links a {
        display: inline-block;
        font-size: 2rem;
        margin: 0 0.8rem;
        color: var(--primary-color);
        transition: transform var(--transition-speed), color var(--transition-speed);
    }

    .social-links a:hover {
        color: var(--accent-color);
        transform: translateY(-5px);
    }

    /* Rodapé */
    footer {
        background: var(--dark-bg);
        color: var(--light-text);
        text-align: center;
        padding: 2.5rem;
        font-size: 0.9rem;
        margin-top: auto;
        box-shadow: 0 -4px 12px rgba(0,0,0,0.1);
    }

    /* Media Queries para Responsividade */
    @media (max-width: 768px) {
        .hero {
            padding: 6rem 1rem;
            min-height: 50vh;
        }
        .hero h1 {
            font-size: 3rem;
        }
        .hero p {
            font-size: 1.3rem;
        }
        nav ul {
            flex-direction: column;
            gap: 1.2rem;
        }
        nav a {
            font-size: 1rem;
        }
        section {
            padding: 3rem 0;
        }
        h2 {
            font-size: 1.8rem;
            margin-bottom: 2rem;
        }
        .about-content {
            flex-direction: column;
        }
        .about-image {
            max-width: 280px;
        }
        .project-grid {
            grid-template-columns: 1fr;
        }
        .project-card img {
            height: 180px;
        }
    }

    @media (max-width: 480px) {
        h1 { font-size: 2.5rem; }
        h2 { font-size: 1.5rem; }
        h3 { font-size: 1.3rem; }
        .hero h1 {
            font-size: 2.5rem;
        }
        .hero p {
            font-size: 1.1rem;
        }
        .container {
            padding: 0 1rem;
        }
        .project-content {
            padding: 1rem;
        }
    }
</style>
</head>
<body>
<nav>
    <div class="container">
        <ul>
            <li><a href="#hero">Início</a></li>
            <li><a href="#sobre">Sobre Mim</a></li>
            <li><a href="#projetos">Projetos</a></li>
            <li><a href="#contacto">Contacto</a></li>
        </ul>
    </div>
</nav>

<header id="hero" class="hero">
    <div class="hero-content">
        <h1>Olá, sou o [O Seu Nome]</h1>
        <p>Um Designer Gráfico & Desenvolvedor Web apaixonado por criar experiências digitais incríveis e funcionais.</p>
    </div>
</header>

<main>
    <section id="sobre" class="fade-in">
        <div class="container">
            <h2>Sobre Mim</h2>
            <div class="about-content">
                <div class="about-image">
                    <img src="https://source.unsplash.com/random/350x350/?person,profile" alt="Foto de Perfil">
                </div>
                <div class="about-text">
                    <p>Com X anos de experiência na área, dedico-me a transformar ideias complexas em soluções digitais intuitivas e visualmente apelativas. A minha paixão reside na interseção do design e do código, procurando sempre a harmonia entre estética e funcionalidade.</p>
                    <p>Tenho um vasto conhecimento em **Design Gráfico**, **Web Design (UI/UX)** e **Desenvolvimento Frontend (HTML, CSS, JavaScript)**. Adoro aprender novas tecnologias e enfrentar desafios que me permitam crescer e criar algo verdadeiramente impactante.</p>
                    <p>Fora do trabalho, sou um entusiasta de [Seus Hobbies, ex: fotografia, leitura, jogos]. Acredito que a inspiração pode vir de todo o lado, e estas atividades ajudam-me a manter a criatividade sempre ativa.</p>
                </div>
            </div>
        </div>
    </section>

    <section id="projetos" class="fade-in">
        <div class="container">
            <h2>Projetos em Destaque</h2>
            <div class="project-grid">
                <div class="project-card">
                    <img src="https://source.unsplash.com/random/800x600/?website,ecommerce" alt="Projeto E-commerce">
                    <div class="project-content">
                        <h3>Plataforma de E-commerce Moderna</h3>
                        <p>Um projeto de desenvolvimento web completo, focado em uma experiência de utilizador intuitiva e um design responsivo. Inclui funcionalidades de catálogo, carrinho e checkout seguro.</p>
                        <div class="project-links">
                            <a href="#" target="_blank">Ver Projeto</a>
                        </div>
                    </div>
                </div>

                <div class="project-card">
                    <img src="https://source.unsplash.com/random/800x600/?app,mobile-design" alt="Aplicativo Mobile UX/UI">
                    <div class="project-content">
                        <h3>Redesign de Aplicativo Mobile (UI/UX)</h3>
                        <p>Fiz o redesenho da interface e experiência de utilizador de um aplicativo de [tipo de app, ex: gestão financeira], tornando-o mais limpo, moderno e fácil de usar. Os estudos de usabilidade levaram a uma melhoria de 30% na satisfação do utilizador.</p>
                        <div class="project-links">
                            <a href="#" target="_blank">Ver Estudo de Caso</a>
                        </div>
                    </div>
                </div>

                <div class="project-card">
                    <img src="https://source.unsplash.com/random/800x600/?branding,logo-design" alt="Identidade Visual Completa">
                    <div class="project-content">
                        <h3>Identidade Visual para Startup</h3>
                        <p>Desenvolvimento completo de uma identidade visual para uma nova startup do setor de [setor, ex: tecnologia verde], incluindo logótipo, paleta de cores, tipografia e diretrizes de marca para um branding consistente.</p>
                        <div class="project-links">
                            <a href="#" target="_blank">Ver Portfólio Gráfico</a>
                        </div>
                    </div>
                </div>

                </div>
        </div>
    </section>

    <section id="contacto" class="fade-in">
        <div class="container">
            <h2>Contacto</h2>
            <div class="contact-info">
                <p>Estou sempre aberto a novas oportunidades e colaborações. Se tiver um projeto em mente ou simplesmente quiser conversar, sinta-se à vontade para me contactar!</p>
                <p>Email: <a href="mailto:seuemail@exemplo.com">seuemail@exemplo.com</a></p>
                <p>Telefone: <a href="tel:+351912345678">+351 912 345 678</a></p>
                <div class="social-links">
                    <a href="https://www.linkedin.com/in/seuperfil" target="_blank" title="LinkedIn">in</a>
                    <a href="https://github.com/seugithub" target="_blank" title="GitHub">gh</a>
                    <a href="https://www.behance.net/seubehance" target="_blank" title="Behance">be</a>
                    </div>
            </div>
        </div>
    </section>
</main>

<footer>
    <div class="container">
        <p>&copy; 2025 [Seu Nome]. Todos os direitos reservados.</p>
    </div>
</footer>

<script>
    document.addEventListener('DOMContentLoaded', () => {
        const sections = document.querySelectorAll('section');

        const observerOptions = {
            root: null,
            rootMargin: '0px',
            threshold: 0.2 // A secção fica visível quando 20% dela entra no viewport
        };

        const sectionObserver = new IntersectionObserver((entries, observer) => {
            entries.forEach(entry => {
                if (entry.isIntersecting) {
                    entry.target.classList.add('fade-in');
                    observer.unobserve(entry.target); // Deixa de observar depois de animar
                }
            });
        }, observerOptions);

        sections.forEach(section => {
            sectionObserver.observe(section);
        });

        // Simulação de carregamento de imagem aleatória para a foto de perfil
        const profileImage = document.querySelector('.about-image img');
        if (profileImage) {
            profileImage.src = 'https://source.unsplash.com/random/350x350/?face,portrait&' + Math.random();
        }
    });
</script>
</body>
</html>
    )";
}

// 11. Usar template pronto (Blog)
void MainMenu::on_btnTemplateBlog_clicked()
{
    htmlContent += R"(
<!DOCTYPE html>
<html lang="pt">
<head>
<meta charset="UTF-8" />
<meta name="viewport" content="width=device-width, initial-scale=1.0"/>
<title>Aventuras Pelo Mundo - Blog de Viagens</title>
<link href="https://fonts.googleapis.com/css2?family=Playfair+Display:wght@700&family=Lato:wght@300;400;700&display=swap" rel="stylesheet">
<style>
    :root {
        --primary-color: #2c3e50; /* Azul escuro quase preto */
        --accent-color: #e67e22; /* Laranja vibrante */
        --text-color: #333;
        --light-bg: #f5f7fa; /* Fundo suave */
        --white: #ffffff;
        --card-shadow: 0 8px 20px rgba(0,0,0,0.08);
        --transition-speed: 0.3s ease-in-out;
    }

    body {
        font-family: 'Lato', sans-serif;
        margin: 0;
        padding: 0;
        background: var(--light-bg);
        color: var(--text-color);
        line-height: 1.6;
        min-height: 100vh;
        display: flex;
        flex-direction: column;
    }

    /* Navegação */
    nav {
        background-color: var(--primary-color);
        padding: 1rem 0;
        text-align: center;
        box-shadow: 0 2px 10px rgba(0,0,0,0.1);
    }

    nav ul {
        list-style: none;
        margin: 0;
        padding: 0;
        display: flex;
        justify-content: center;
        gap: 2rem;
    }

    nav a {
        color: var(--white);
        text-decoration: none;
        font-weight: 700;
        font-size: 1rem;
        transition: color var(--transition-speed);
    }

    nav a:hover {
        color: var(--accent-color);
    }

    /* Secção Hero (Cabeçalho) */
    .hero {
        position: relative;
        height: 500px; /* Altura fixa para o hero */
        background-image: url('https://source.unsplash.com/random/1600x900/?travel,landscape'); /* Imagem de fundo aleatória */
        background-size: cover;
        background-position: center;
        display: flex;
        align-items: center;
        justify-content: center;
        text-align: center;
        color: var(--white);
        overflow: hidden; /* Para esconder qualquer overflow da imagem */
    }

    .hero::before {
        content: '';
        position: absolute;
        top: 0;
        left: 0;
        width: 100%;
        height: 100%;
        background: rgba(0, 0, 0, 0.5); /* Overlay escuro para o texto se destacar */
        z-index: 1;
    }

    .hero-content {
        position: relative;
        z-index: 2;
        padding: 2rem;
    }

    .hero h1 {
        font-family: 'Playfair Display', serif;
        font-size: 4rem;
        margin-bottom: 1rem;
        text-shadow: 2px 2px 8px rgba(0,0,0,0.7);
        animation: fadeInDown 1s ease-out; /* Animação ao carregar */
    }

    .hero p {
        font-size: 1.5rem;
        font-weight: 300;
        margin-top: 0;
        animation: fadeInUp 1s ease-out 0.5s forwards; /* Animação com delay */
        opacity: 0; /* Começa invisível para a animação */
    }

    @keyframes fadeInDown {
        from { opacity: 0; transform: translateY(-50px); }
        to { opacity: 1; transform: translateY(0); }
    }

    @keyframes fadeInUp {
        from { opacity: 0; transform: translateY(50px); }
        to { opacity: 1; transform: translateY(0); }
    }

    /* Conteúdo Principal */
    main {
        flex: 1;
        padding: 2rem 0;
    }

    .container {
        max-width: 900px;
        margin: 0 auto;
        padding: 0 1.5rem;
        display: grid;
        grid-template-columns: repeat(auto-fit, minmax(300px, 1fr));
        gap: 2rem; /* Espaçamento entre os posts */
    }

    /* Post Card */
    .post-card {
        background: var(--white);
        border-radius: 12px;
        box-shadow: var(--card-shadow);
        overflow: hidden; /* Para garantir que a imagem não ultrapasse o card */
        transition: transform var(--transition-speed), box-shadow var(--transition-speed);
        display: flex;
        flex-direction: column;
        justify-content: space-between; /* Para manter o footer do card no fundo */
    }

    .post-card:hover {
        transform: translateY(-8px);
        box-shadow: 0 12px 25px rgba(0,0,0,0.15);
    }

    .post-card img {
        width: 100%;
        height: 200px; /* Altura fixa para as imagens */
        object-fit: cover; /* Garante que a imagem cobre a área sem distorção */
    }

    .post-content {
        padding: 1.5rem;
    }

    .post-card h2 {
        font-family: 'Playfair Display', serif;
        color: var(--primary-color);
        margin-top: 0;
        margin-bottom: 0.8rem;
        font-size: 1.8rem;
        line-height: 1.3;
    }

    .post-card p {
        font-size: 0.95rem;
        color: #555;
        margin-bottom: 1rem;
    }

    .post-meta {
        font-size: 0.85rem;
        color: #888;
        border-top: 1px solid #eee;
        padding-top: 1rem;
        margin-top: 1rem;
    }

    /* Rodapé */
    footer {
        background: var(--primary-color);
        color: var(--white);
        text-align: center;
        padding: 2rem;
        font-size: 0.9rem;
        box-shadow: 0 -2px 10px rgba(0,0,0,0.1);
        margin-top: auto; /* Empurra o footer para o fundo */
    }

    /* Responsividade */
    @media (max-width: 768px) {
        .hero {
            height: 400px;
        }
        .hero h1 {
            font-size: 3rem;
        }
        .hero p {
            font-size: 1.2rem;
        }
        .container {
            grid-template-columns: 1fr; /* Coluna única em ecrãs pequenos */
            padding: 0 1rem;
        }
        .post-card {
            margin-bottom: 1.5rem;
        }
    }

    @media (max-width: 480px) {
        .hero {
            height: 300px;
        }
        .hero h1 {
            font-size: 2.2rem;
        }
        .hero p {
            font-size: 1rem;
        }
        nav ul {
            flex-direction: column;
            gap: 1rem;
        }
        .post-card h2 {
            font-size: 1.5rem;
        }
        .post-content {
            padding: 1rem;
        }
    }
</style>
</head>
<body>
<nav>
    <ul>
        <li><a href="#home">Home</a></li>
        <li><a href="#destinos">Destinos</a></li>
        <li><a href="#dicas">Dicas</a></li>
        <li><a href="#sobre">Sobre Mim</a></li>
        <li><a href="#contacto">Contacto</a></li>
    </ul>
</nav>

<header class="hero">
    <div class="hero-content">
        <h1>Aventuras Pelo Mundo</h1>
        <p>Histórias, guias e inspiração para a sua próxima viagem.</p>
    </div>
</header>

<main>
    <div class="container">
        <div class="post-card">
            <img src="https://source.unsplash.com/random/800x450/?italy,colosseum" alt="Coliseu, Itália">
            <div class="post-content">
                <h2>Minha Inesquecível Viagem à Itália</h2>
                <p>Foi uma experiência incrível! Explorei as ruas históricas de Roma, os canais românticos de Veneza e a arte renascentista de Florença. Cada cidade ofereceu uma beleza única e a gastronomia... ah, a gastronomia foi sublime! Recomendo vivamente uma viagem de comboio para apreciar as paisagens.</p>
                <div class="post-meta">Publicado em 22 de Maio, 2025</div>
            </div>
        </div>

        <div class="post-card">
            <img src="https://source.unsplash.com/random/800x450/?japan,kyoto" alt="Templo em Quioto, Japão">
            <div class="post-content">
                <h2>Descobrindo o Japão: Uma Imersão Cultural</h2>
                <p>A cultura e a comida do Japão foram fantásticas! Desde os vibrantes bairros de Tóquio até os templos serenos de Quioto, cada momento foi uma descoberta. Não deixe de experimentar o sushi fresco e visitar os jardins zen. É um lugar mágico que combina tradição com modernidade de forma única.</p>
                <div class="post-meta">Publicado em 15 de Maio, 2025</div>
            </div>
        </div>

        <div class="post-card">
            <img src="https://source.unsplash.com/random/800x450/?greece,santorini" alt="Santorini, Grécia">
            <div class="post-content">
                <h2>A Magia das Ilhas Gregas: Sol, Mar e História</h2>
                <p>As ilhas gregas são um verdadeiro paraíso. De Santorini, com as suas casas brancas e vistas deslumbrantes do pôr do sol, a Mykonos, com a sua vida noturna vibrante, cada ilha tem o seu encanto. Mergulhar nas águas cristalinas e explorar ruínas antigas foi simplesmente espetacular. Uma viagem de sonho para qualquer amante de praia e história!</p>
                <div class="post-meta">Publicado em 08 de Maio, 2025</div>
            </div>
        </div>

        <div class="post-card">
            <img src="https://source.unsplash.com/random/800x450/?brazil,beach" alt="Praia no Brasil">
            <div class="post-content">
                <h2>Explorando as Praias Paradisiacas do Brasil</h2>
                <p>O Brasil é um destino que encanta com a sua beleza natural. Desde as praias douradas do Nordeste até à vibrante energia do Rio de Janeiro, cada canto oferece uma experiência única. A hospitalidade do povo e a riqueza cultural tornam a viagem inesquecível.</p>
                <div class="post-meta">Publicado em 01 de Maio, 2025</div>
            </div>
        </div>
    </div>
</main>

<footer>
    <p>&copy; 2025 Aventuras Pelo Mundo. Todos os direitos reservados.</p>
    <p>Criado com amor por um viajante.</p>
</footer>
</body>
</html>
    )";
}

// Função para reiniciar o htmlContent para um novo projeto (limpar tudo)
void MainMenu::on_btnNovoProjeto_clicked()
{
    htmlContent = "<!DOCTYPE html>\n<html>\n<head>\n<title>LayoutMaker++</title>\n<style>\nbody { font-family: Arial; padding: 20px; }\n</style>\n</head>\n<body>\n";
}

// Salvar arquivo HTML
void MainMenu::on_btnSalvar_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Salvar arquivo HTML", "", "Arquivos HTML (*.html *.htm)");
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            QString finalHtml = htmlContent;

            // Fecha body e html caso ainda não estejam fechados
            if (!finalHtml.endsWith("</body>\n</html>\n") && !finalHtml.endsWith("</body></html>")) {
                finalHtml += "</body>\n</html>\n";
            }

            out << finalHtml;
            file.close();

            QMessageBox::information(this, "Sucesso", "Arquivo salvo com sucesso!");
        } else {
            QMessageBox::warning(this, "Erro", "Não foi possível salvar o arquivo.");
        }
    }
}
// Sair da aplicação
void MainMenu::on_btnSair_clicked()
{
    QApplication::quit(); // Ou this->close(); dependendo do que preferes
}
