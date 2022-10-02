#include "entidades.h"
/// --------------------- INICIALIZACIONES --------------------------
void Entidades::iniciarVariables()
{
    _movimiento = NULL;
    _animacion = NULL;
}

/// --------------------- CONSTRUCTOR / DESTRUCTOR ---------------------
Entidades::Entidades()
{
    this->iniciarVariables();


}

Entidades::~Entidades()
{
    delete _movimiento;
    delete _animacion;
}


/// --------------------- FUNCIONES ---------------------

void Entidades::setTextura(sf::Texture& textura)
{
    _sprite.setTexture(textura);
}


void Entidades::crearComponenteMovimiento(float velocidadMaxima, float aceleracion, float desaceleracion)
{
    _movimiento = new Movimiento(_sprite, velocidadMaxima, aceleracion, desaceleracion);
}

void Entidades::crearComponenteAnimacion(sf::Texture& textura)
{
    _animacion = new Animacion(_sprite, textura);
}


void Entidades::setPosicion(const float x, const float y)
{
    _sprite.setPosition(x, y);
}

void Entidades::mover(const float dir_x, const float dir_y, const float& DT)
{
    if(this->_movimiento){
    // Recibe direcciones (x y)
        _movimiento->mover(dir_x, dir_y, DT); // setea velocidad
    }
}


/// --------------------- ACTUALIZACIONES --------------------------
void Entidades::actualizar(const float& DT)
{


}

/// --------------------- RENDERIZAR --------------------------
void Entidades::renderizar(sf::RenderTarget* target)
{
    target->draw(_sprite);
}
