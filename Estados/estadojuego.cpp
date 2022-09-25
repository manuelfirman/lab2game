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

void EstadoJuego::iniciarTexturas()
{
    sf::Texture aux;

    if(!_texturas["JUGADOR_QUIETO"].loadFromFile("recursos/img/Mushroom.png")){
       std::cout << "ERROR:EstadoJuego_iniciarTexturas_CargaTexturaPersonaje" << std::endl;
    }
}

void EstadoJuego::iniciarJugadores()
{
    player = new Jugador(0,0, _texturas["JUGADOR_QUIETO"]);
}

/// --------------------- CONSTRUCTOR / DESTRUCTOR ---------------------
EstadoJuego::EstadoJuego(sf::RenderWindow* ventana, std::map<std::string, int>* teclasSoportadas, std::stack<EstadoBase*>* estado) : EstadoBase(ventana, teclasSoportadas, estado)
{
    this->iniciarKeybinds();
    this->iniciarTexturas();
    this->iniciarJugadores();
}

EstadoJuego::~EstadoJuego()
{

}


/// --------------------- ACTUALIZACIONES --------------------------
void EstadoJuego::actualizarInput(const float& DT)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(_keybinds.at("MOVER_IZQUIERDA"))))
        player->mover(-1.f, 0.f, DT);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(_keybinds.at("MOVER_DERECHA"))))
        player->mover(1.f, 0.f, DT);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(_keybinds.at("MOVER_ARRIBA"))))
        player->mover(0.f, -1.f, DT);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(_keybinds.at("MOVER_ABAJO"))))
        player->mover(0.f, 1.f, DT);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(_keybinds.at("CLOSE"))))
        finEstado();

}

void EstadoJuego::actualizar(const float& DT)
{
    actualizarPosicionMouse();
    actualizarInput(DT);

    player->actualizar(DT);
}


/// --------------------- RENDERIZAR --------------------------
void EstadoJuego::renderizar(sf::RenderTarget* target)
{
    if(!target)
        target = _ventana;


    player->renderizar(target);
}
