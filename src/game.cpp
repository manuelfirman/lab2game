#include "game.h"

/// ------------------ INICIALIZACIONES ------------------
void Game::iniciarVariables()
{
    _ventana = NULL;
    _deltaTime = 0.f;
    _modoVideo.width = 800;
    _modoVideo.height = 600;
    _fps = 60;

    _textura.loadFromFile("clothes.png");
    _sprite.setTexture(_textura);
    animacion = new Animacion(&_textura, sf::Vector2u(32,8), 0.1f);
}

void Game::iniciarVentana()
{
    _ventana = new sf::RenderWindow(_modoVideo, "Juego", sf::Style::Titlebar | sf::Style::Close);
    _ventana->setFramerateLimit(_fps);
}


/// ---------- CONSTRUCTOR / DESTRUCTOR -------------------
Game::Game()
{
    this->iniciarVariables();
    this->iniciarVentana();
}

Game::~Game()
{
    delete _ventana;
}


/// ------------------ UPDATE ---------------------------
void Game::actualizarEventos()
{
    while(_ventana->pollEvent(_evento))
    {
        if(_evento.type == sf::Event::Closed) _ventana->close();
    }
}

void Game::actualizarDeltaTime()
{
    _deltaTime = relojDelta.restart().asSeconds();
    std::cout << _deltaTime << std::endl;
}

void Game::actualizar()
{
    this->actualizarEventos();
    animacion->actualizar(1, _deltaTime);
    _sprite.setTextureRect(animacion->_rect);
}


/// ------------------ RENDER ---------------------------
void Game::renderizar()
{
    _ventana->clear(sf::Color(255, 255, 255, 255));

    _ventana->draw(_sprite);

    _ventana->display();
}


/// ------------------ GAMELOOP ---------------------------
void Game::gameloop()
{
    while(_ventana->isOpen())
    {
        this->actualizarDeltaTime();

        this->actualizar();

        this->renderizar();
    }
}

void Game::finAplicacion()
{
//    std::cout << "Aplicacion Finalizada" << std::endl;
}
