#include "entidades.h"
/// --------------------- INICIALIZACIONES --------------------------
void Entidades::iniciarVariables()
{
    _textura = NULL;
    _sprite = NULL;
    movimiento = NULL;
}

/// --------------------- CONSTRUCTOR / DESTRUCTOR ---------------------
Entidades::Entidades()
{
    this->iniciarVariables();


}

Entidades::~Entidades()
{
    delete _sprite;
}


/// --------------------- FUNCIONES ---------------------

void Entidades::crearSprite(sf::Texture* textura)
{
    _textura = textura;
    _sprite = new sf::Sprite(*_textura);

}

void Entidades::crearComponenteMovimiento(const float velocidadMaxima)
{
    movimiento = new Movimiento(velocidadMaxima, 0,0);
}

void Entidades::setPosicion(const float x, const float y)
{
    if(_sprite){
        _sprite->setPosition(x, y);
    }
}

void Entidades::mover(const float& DT, const float dir_x, const float dir_y)
{
    if(_sprite && this->movimiento){
    // Recibe direcciones (x y)
        movimiento->mover(dir_x, dir_y); // setea velocidad
        _sprite->move(movimiento->getVelocidad() * DT);
    }
}


/// --------------------- ACTUALIZACIONES --------------------------
void Entidades::actualizar(const float& DT)
{

}

/// --------------------- RENDERIZAR --------------------------
void Entidades::renderizar(sf::RenderTarget* target)
{
    target->draw(*_sprite);
}
