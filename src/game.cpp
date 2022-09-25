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

void Game::iniciarEstados()
{
    _estado.push(new EstadoJuego(_ventana, &_teclasSoportadas));
}

void Game::iniciarTeclas()
{
    _teclasSoportadas.emplace("ESC", sf::Keyboard::Key::Escape);
    _teclasSoportadas.emplace("A", sf::Keyboard::Key::A);
    _teclasSoportadas.emplace("W", sf::Keyboard::Key::W);
    _teclasSoportadas.emplace("D", sf::Keyboard::Key::D);
    _teclasSoportadas.emplace("S", sf::Keyboard::Key::S);
}

/// --------------------- CONSTRUCTOR / DESTRUCTOR ---------------------
Game::Game()
{
	srand(time(NULL));
	this->iniciarVariables();
    this->iniciarVentana();
    this->iniciarTeclas();
    this->iniciarEstados();
}

Game::~Game()
{
    delete _ventana;
    while(!_estado.empty()){   // al ser memoria dinamica
        delete _estado.top(); // 1) se elimina el contenido del puntero
        _estado.pop();       // 2) se elimina el puntero
        std::cout << "debug destructor game" << std::endl;
    }
}

void Game::finAplicacion()
{
    std::cout << "Cerrando la aplicacion" << std::endl;
}

/// --------------------- ACTUALIZACIONES --------------------------
void Game::actualizarDT()
{
    _DT = relojDt.restart().asSeconds();
//    std::cout << _DT << std::endl;
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

    /// actualizar si la pila no esta vacia
    if(!_estado.empty()){
        _estado.top()->actualizar(_DT);

        if(_estado.top()->getSalir())
        {
            _estado.top()->finEstado();
            delete _estado.top(); // libera memoria
            _estado.pop(); // saca puntero
        }
    } /// si la pila esta vacia, cierra ventana
    else{
        finAplicacion();
        _ventana->close();
    }
}


/// --------------------- RENDERIZAR --------------------------
void Game::renderizar(){
	/// Clear.
	_ventana->clear();

	/// Renderizar
	if(!_estado.empty()){
        _estado.top()->renderizar();
	}

	/// Display.
	_ventana->display();
}

/// --------------------- GAMELOOP --------------------------
void Game::gameloop()
{
    while(_ventana->isOpen()){
        /// Delta Time.
        this->actualizarDT();
        /// Actualizar
        this->actualizar();
        /// Renderizar
        this->renderizar();
    }
}
