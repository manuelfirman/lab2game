#include "estadojuego.h"
/// --------------------- INICIALIZACIONES --------------------------
void EstadoJuego::iniciarKeybinds()
{
    _keybinds.emplace("MOVER_IZQUIERDA",_teclasSoportadas->at("A"));
    _keybinds.emplace("MOVER_DERECHA",_teclasSoportadas->at("D"));
    _keybinds.emplace("MOVER_ARRIBA",_teclasSoportadas->at("W"));
    _keybinds.emplace("MOVER_ABAJO",_teclasSoportadas->at("S"));
}


/// --------------------- CONSTRUCTOR / DESTRUCTOR ---------------------
EstadoJuego::EstadoJuego(sf::RenderWindow* ventana, std::map<std::string, int>* teclasSoportadas) : EstadoBase(ventana, teclasSoportadas)
{
    this->iniciarKeybinds();
}

EstadoJuego::~EstadoJuego()
{

}

void EstadoJuego::finEstado()
{
    std::cout << "Fin de Estado Juego" << std::endl;
}

/// --------------------- ACTUALIZACIONES --------------------------
void EstadoJuego::actualizarInput(const float& DT)
{
    checkSalir();

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(_keybinds.at("MOVER_IZQUIERDA"))))
        player.mover(DT, -1.f, 0.f);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(_keybinds.at("MOVER_DERECHA"))))
        player.mover(DT, 1.f, 0.f);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(_keybinds.at("MOVER_ARRIBA"))))
        player.mover(DT, 0.f, -1.f);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(_keybinds.at("MOVER_ABAJO"))))
        player.mover(DT, 0.f, 1.f);

}

void EstadoJuego::actualizar(const float& DT)
{
    actualizarInput(DT);

    player.actualizar(DT);
}


/// --------------------- RENDERIZAR --------------------------
void EstadoJuego::renderizar(sf::RenderTarget* target)
{
    if(!target)
        target = _ventana;


    player.renderizar(target);
}
