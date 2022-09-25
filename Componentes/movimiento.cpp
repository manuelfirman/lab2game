#include "movimiento.h"

Movimiento::Movimiento(float velocidadMaxima, float aceleracion, float desaceleracion)
{
    _velocidadMax = velocidadMaxima;
}

Movimiento::~Movimiento()
{
    //dtor
}

const sf::Vector2f& Movimiento::getVelocidad() const
{
    return _velocidad;
}

void Movimiento::mover(const float dir_x, const float dir_y)
{
    _velocidad.x = _velocidadMax * dir_x;
    _velocidad.y = _velocidadMax * dir_y;

}

void Movimiento::actualizar(const float& DT)
{

}
