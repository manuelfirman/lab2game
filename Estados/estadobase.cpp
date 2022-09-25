#include "estadobase.h"
/// --------------------- CONSTRUCTOR / DESTRUCTOR ---------------------
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


/// --------------------- FUNCIONES ---------------------
void EstadoBase::finEstado()
{
    _salir = true;
}

const bool& EstadoBase::getSalir() const
{
    return _salir;
}

void EstadoBase::actualizarPosicionMouse()
{
    posMousePantalla = sf::Mouse::getPosition();
    posMouseVentana = sf::Mouse::getPosition(*_ventana);
    posMouseVista = _ventana->mapPixelToCoords(sf::Mouse::getPosition(*_ventana));
}

