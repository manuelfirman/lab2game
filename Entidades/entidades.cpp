#include "entidades.h"
/// --------------------- INICIALIZACIONES --------------------------
void Entidades::iniciarVariables()
{
    movimiento = NULL;
}

/// --------------------- CONSTRUCTOR / DESTRUCTOR ---------------------
Entidades::Entidades()
{
    this->iniciarVariables();


}

Entidades::~Entidades()
{
    delete &_sprite;
}


/// --------------------- FUNCIONES ---------------------

void Entidades::setTextura(sf::Texture& textura)
{
    _sprite.setTexture(textura);

}

void Entidades::crearComponenteMovimiento(float velocidadMaxima, float aceleracion, float desaceleracion)
{
    movimiento = new Movimiento(_sprite, velocidadMaxima, aceleracion, desaceleracion);
}

void Entidades::setPosicion(const float x, const float y)
{
    _sprite.setPosition(x, y);
}

void Entidades::mover(const float dir_x, const float dir_y, const float& DT)
{
    if(this->movimiento){
    // Recibe direcciones (x y)
        movimiento->mover(dir_x, dir_y, DT); // setea velocidad
    }
}


/// --------------------- ACTUALIZACIONES --------------------------
void Entidades::actualizar(const float& DT)
{
    if(movimiento){
        movimiento->actualizar(DT);
    }
}

/// --------------------- RENDERIZAR --------------------------
void Entidades::renderizar(sf::RenderTarget* target)
{
    target->draw(_sprite);
}
