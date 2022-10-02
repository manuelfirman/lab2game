#include "estadomenuprincipal.h"
#include <sstream>
/// --------------------- INICIALIZACIONES --------------------------
void EstadoMenuPrincipal::iniciarVariables()
{

}

void EstadoMenuPrincipal::iniciarKeybinds()
{
    std::ifstream archivo("config/teclas_menuprincipal.ini");

    if(archivo.is_open()){
        std::string accion = "";
        std::string tecla = "";

        while(archivo >> accion >> tecla){
            _keybinds[accion] = _teclasSoportadas->at(tecla);
        }
    }
}

void EstadoMenuPrincipal::iniciarFondo()
{
    if(!_texturaFondoMenu.loadFromFile("recursos/img/fondos/fondo_menu.jpg"))
        std::cout << "ERROR:iniciarFondo_EstadoMenuPrincipal_CargarTexturaMenu" << std::endl;

    _fondoMenu.setSize(sf::Vector2f(static_cast<float>(_ventana->getSize().x), static_cast<float>(_ventana->getSize().y)));
    _fondoMenu.setTexture(&_texturaFondoMenu);
}

void EstadoMenuPrincipal::iniciarFuentes()
{
    if(!_fuenteMenu.loadFromFile("recursos/fuentes/Bungee-Regular.ttf")){
        std::cout << "ERROR:CargarFuente_MenuPrincipal" << std::endl;
    }
    if(!_fuenteBoton.loadFromFile("recursos/fuentes/Bungee-Regular.ttf")){
        std::cout << "ERROR:CargarFuente_MenuPrincipal_Botones" << std::endl;
    }
}

void EstadoMenuPrincipal::iniciarBotones()
{
    _boton["ESTADO_JUEGO"] = new Boton(sf::Vector2f(200,50), "NUEVO JUEGO", 20, _fuenteBoton, sf::Color(48,132,70,155), sf::Color(189,236,182,155), sf::Color(208,208,208,155), sf::Color(sf::Color::Black));
    _boton["ESTADO_JUEGO"]->setPosicion(sf::Vector2f((_ventana->getSize().x / 2.f) - 100, 400));

    _boton["ESTADO_CARGAR"] = new Boton(sf::Vector2f(200,50), "CARGAR PARTIDA", 20, _fuenteBoton, sf::Color(48,132,70,155), sf::Color(189,236,182,155), sf::Color(208,208,208,155), sf::Color(sf::Color::Black));
    _boton["ESTADO_CARGAR"]->setPosicion(sf::Vector2f((_ventana->getSize().x / 2.f) - 100, 480));

    _boton["ESTADO_OPCIONES"] = new Boton(sf::Vector2f(200,50), "OPCIONES", 20, _fuenteBoton, sf::Color(48,132,70,155), sf::Color(189,236,182,155), sf::Color(208,208,208,155), sf::Color(sf::Color::Black));
    _boton["ESTADO_OPCIONES"]->setPosicion(sf::Vector2f((_ventana->getSize().x / 2.f) - 100, 560));

    _boton["ESTADO_SALIR"] = new Boton(sf::Vector2f(200,50), "SALIR", 20, _fuenteBoton, sf::Color(48,132,70,155), sf::Color(189,236,182,155), sf::Color(208,208,208,155), sf::Color(sf::Color::Black));
    _boton["ESTADO_SALIR"]->setPosicion(sf::Vector2f((_ventana->getSize().x / 2.f) - 100, 640));

    _boton["ESTADO_EDITOR"] = new Boton(sf::Vector2f(200,50), "EDITOR", 20, _fuenteBoton, sf::Color(48,132,70,155), sf::Color(189,236,182,155), sf::Color(208,208,208,155), sf::Color(sf::Color::Black));
    _boton["ESTADO_EDITOR"]->setPosicion(sf::Vector2f((_ventana->getSize().x / 2.f) - 100, 800));
}

/// --------------------- CONSTRUCTOR / DESTRUCTOR ---------------------
EstadoMenuPrincipal::EstadoMenuPrincipal(sf::RenderWindow* ventana, std::map<std::string, int>* teclasSoportadas, std::stack<EstadoBase*>* estado) : EstadoBase(ventana, teclasSoportadas, estado)
{
    this->iniciarVariables();
    this->iniciarKeybinds();
    this->iniciarFondo();
    this->iniciarFuentes();
    this->iniciarBotones();

}

EstadoMenuPrincipal::~EstadoMenuPrincipal()
{
    auto it = _boton.begin();
    for(it = _boton.begin(); it != _boton.end(); ++it){
        delete it->second;
    }
}


/// --------------------- ACTUALIZACIONES --------------------------
void EstadoMenuPrincipal::actualizarInput(const float& DT)
{


}

void EstadoMenuPrincipal::actualizarBotones()
{
    for(auto &botones : _boton){
        botones.second->actualizar(posMouseVista);
    }

    if(_boton["ESTADO_JUEGO"]->getClick())
        _estado->push(new EstadoJuego(_ventana, _teclasSoportadas, _estado)); // pasa 3 punteros

    if(_boton["ESTADO_CARGAR"]->getClick());


    if(_boton["ESTADO_EDITOR"]->getClick())
        _estado->push(new EstadoEditor(_ventana, _teclasSoportadas, _estado));


    if(_boton["ESTADO_SALIR"]->getClick())
        finEstado();

}

void EstadoMenuPrincipal::actualizar(const float& DT)
{
    actualizarPosicionMouse();
    actualizarInput(DT);
    actualizarBotones();

}


/// --------------------- RENDERIZAR --------------------------
void EstadoMenuPrincipal::renderBotones(sf::RenderTarget& target)
{
    for(auto &botones : _boton){
        botones.second->renderizar(target);
    }
}


void EstadoMenuPrincipal::renderizar(sf::RenderTarget* target)
{
    if(!target)
        target = _ventana;

    target->draw(_fondoMenu);

    renderBotones(*target);


    /// VER POSICION MOUSE AL LADO DE LA FLECHA (QUITAR DESPUES)
//    sf::Text textoMouse;
//    textoMouse.setPosition(posMouseVista.x, posMouseVista.y - 50);
//    textoMouse.setFont(_fuenteBoton);
//    textoMouse.setCharacterSize(12);
//    std::stringstream ss;
//    ss << posMouseVista.x << " " << posMouseVista.y;
//    textoMouse.setString(ss.str());
//
//    target->draw(textoMouse);
}
