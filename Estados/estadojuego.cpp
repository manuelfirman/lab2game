#include "estadojuego.h"
/// --------------------- INICIALIZACIONES --------------------------
void EstadoJuego::iniciarKeybinds()
{
    std::ifstream archivo("config/teclas_juego.ini");

    if(archivo.is_open()){
        std::string accion = "";
        std::string tecla = "";

        while(archivo >> accion >> tecla){
            _keybinds[accion] = _teclasSoportadas->at(tecla);
        }
    }
}


/// --------------------- CONSTRUCTOR / DESTRUCTOR ---------------------
EstadoJuego::EstadoJuego(sf::RenderWindow* ventana, std::map<std::string, int>* teclasSoportadas, std::stack<EstadoBase*>* estado) : EstadoBase(ventana, teclasSoportadas, estado)
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
    actualizarPosicionMouse();
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
