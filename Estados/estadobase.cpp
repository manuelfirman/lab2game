#include "estadobase.h"

EstadoBase::EstadoBase(sf::RenderWindow* ventana, std::map<std::string, int>* teclasSoportadas)
{
    _ventana = ventana;
    _salir = false;
    _teclasSoportadas = teclasSoportadas;

}

EstadoBase::~EstadoBase()
{
    //dtor
}

void EstadoBase::checkSalir()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        _salir = true;
    }
}

const bool& EstadoBase::getSalir() const
{
    return _salir;
}
