#include "Game.h"
/// --------------------- INICIALIZACIONES --------------------------
void Game::iniciarVariables()
{
    _ventana = NULL;
    _DT = 0.f;

}

void Game::iniciarVentana()
{
    _ventana = new sf::RenderWindow(sf::VideoMode(800, 600),"RPG GAME");
}

/// --------------------- CONSTRUCTOR / DESTRUCTOR ---------------------
Game::Game()
{
	srand(time(NULL));
    iniciarVentana();
}

Game::~Game()
{
    delete _ventana;
}

/// --------------------- ACTUALIZACIONES --------------------------
void Game::actualizarDT()
{
    _DT = relojDt.restart().asSeconds();
    std::cout << _DT << std::endl;
}

void Game::actualizarEventosSFML()
{
    while(_ventana->pollEvent(sfEvento))
    {
        if(sfEvento.type == sf::Event::Closed){
            _ventana->close();
        }
    }
}

void Game::actualizar()
{
    actualizarEventosSFML();
}


/// --------------------- RENDERIZAR --------------------------
void Game::renderizar(){
	_ventana->clear(); // Clear.
	_ventana->display(); // Display.
}

/// --------------------- GAMELOOP --------------------------
void Game::gameloop()
{
    while(_ventana->isOpen()){
        this->actualizarDT();
        this->actualizar();
        this->renderizar();
    }
}
