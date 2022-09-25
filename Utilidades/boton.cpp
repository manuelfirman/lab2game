#include "boton.h"

/// CONSTRUCTOR
Boton::Boton(sf::Vector2f tamanio, std::string texto, int tamanioLetra, sf::Font& fuente, sf::Color colorBotonInactivo, sf::Color colorBotonHover, sf::Color colorBotonActivo, sf::Color colorTexto)
{
    _estado = BOTON::INACTIVO;

    _texto.setString(texto);
    _texto.setFillColor(colorTexto);
    _texto.setCharacterSize(tamanioLetra);
    _texto.setFont(fuente);
    _boton.setSize(tamanio);
    _colorBotonInactivo = colorBotonInactivo;
    _colorBotonHover = colorBotonHover;
    _colorBotonActivo = colorBotonActivo;
}

Boton::~Boton()
{

}

void Boton::setFuente(sf::Font& fuente)
{
    _texto.setFont(fuente);
}

void Boton::setColorBoton(sf::Color colorBoton)
{
    _boton.setFillColor(colorBoton);
}

void Boton::setColorTexto(sf::Color colorTexto)
{
    _texto.setFillColor(colorTexto);
}

void Boton::setPosicion(sf::Vector2f posicion)
{
    _boton.setPosition(posicion);

    _texto.setPosition(
        _boton.getPosition().x + (_boton.getGlobalBounds().width / 2.f) - _texto.getGlobalBounds().width / 2.f,
        _boton.getPosition().y + (_boton.getGlobalBounds().height / 2.f) - _texto.getGlobalBounds().height);
}

bool Boton::getClick()
{
    if(_estado == BOTON::ACTIVO){
        return true;
    }

    return false;
}

/// ACTUALIZAR BOTON
void Boton::actualizar(sf::Vector2f posMouse)
{
    _estado = BOTON::INACTIVO;
    if(_boton.getGlobalBounds().contains(posMouse)){
        _estado = BOTON::HOVER;

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            _estado = BOTON::ACTIVO;
        }
    }

    switch(_estado){
        case BOTON::INACTIVO:
            _boton.setFillColor(_colorBotonInactivo);
            break;

        case BOTON::HOVER:
            _boton.setFillColor(_colorBotonHover);
            break;

        case BOTON::ACTIVO:
            _boton.setFillColor(_colorBotonActivo);
            break;
    }
}

/// RENDERIZAR BOTON
void Boton::renderizar(sf::RenderTarget* target)
{
    target->draw(_boton);
    target->draw(_texto);
}
