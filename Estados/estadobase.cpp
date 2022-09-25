#include "estadobase.h"

EstadoBase::EstadoBase(sf::RenderWindow* ventana, std::map<std::string, int>* teclasSoportadas, std::stack<EstadoBase*>* estado)
{
    _ventana = ventana;
    _salir = false;
    _estado = estado;
    _teclasSoportadas = teclasSoportadas;

}

EstadoBase::~EstadoBase()
{
    //dtor
}

void EstadoBase::actualizarPosicionMouse()
{
    posMousePantalla = sf::Mouse::getPosition();
    posMouseVentana = sf::Mouse::getPosition(*_ventana);
    posMouseVista = _ventana->mapPixelToCoords(sf::Mouse::getPosition(*_ventana));
}

void EstadoBase::checkSalir()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(_keybinds.at("CLOSE")))){
        _salir = true;
    }
}

const bool& EstadoBase::getSalir() const
{
    return _salir;
}
