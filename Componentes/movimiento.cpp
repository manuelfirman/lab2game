#include "movimiento.h"

Movimiento::Movimiento(sf::Sprite& sprite, float velocidadMaxima, float aceleracion, float desaceleracion)
: _sprite(sprite)
{
    _velocidadMax = velocidadMaxima;
    _aceleracion = aceleracion;
    _desaceleracion = desaceleracion;
}

Movimiento::~Movimiento()
{
    //dtor
}

const sf::Vector2f& Movimiento::getVelocidad() const
{
    return _velocidad;
}

void Movimiento::mover(const float dir_x, const float dir_y, const float& DT)
{
    _velocidad.x += _aceleracion * dir_x; /// aceleracion x
    _velocidad.y += _aceleracion * dir_y; /// aceleracion y

}

void Movimiento::actualizar(const float& DT)
{
    if(_velocidad.x > 0.f){
        if(_velocidad.x > _velocidadMax){
            _velocidad.x = _velocidadMax; // Limitar velocidad
        }

        _velocidad.x -= _desaceleracion; /// Desacelerar derecha

        if(_velocidad.x < 0.f){
            _velocidad.x = 0.f; // Detener
        }
    }

    if(_velocidad.x < 0.f){
        if(_velocidad.x < -_velocidadMax){
            _velocidad.x = -_velocidadMax; // Limitar velocidad
        }
        _velocidad.x += _desaceleracion; /// Desacelerar izquierda

        if(_velocidad.x > 0.f){
            _velocidad.x = 0.f; // Detener
        }
    }

    if(_velocidad.y > 0.f){
        if(_velocidad.y > _velocidadMax){ // Limitar velocidad
            _velocidad.y = _velocidadMax;
        }
        _velocidad.y -= _desaceleracion; /// Desacelerar abajo

        if(_velocidad.y < 0.f){
            _velocidad.y = 0.f; // Detener
        }
    }

    if(_velocidad.y < 0.f){
        if(_velocidad.y < -_velocidadMax){
            _velocidad.y = -_velocidadMax; // Limitar velocidad
        }
        _velocidad.y += _desaceleracion; /// Desacelerar arriba

        if(_velocidad.y > 0.f ){
            _velocidad.y = 0.f; // Detener
        }
    }


    /// Movimiento
    _sprite.move(_velocidad * DT);

}
