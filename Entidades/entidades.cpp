#include "entidades.h"

Entidades::Entidades()
{
    _shape.setSize(sf::Vector2f(50.f, 50.f));
    _shape.setFillColor(sf::Color::White);
    _velocidad = 100.f;

}

Entidades::~Entidades()
{
    //dtor
}

void Entidades::mover(const float& DT, const float dir_x, const float dir_y)
{
    // Recibe direcciones (x y)
    _shape.move(dir_x * _velocidad * DT, dir_y * _velocidad * DT);
}

void Entidades::actualizar(const float& DT)
{

}

void Entidades::renderizar(sf::RenderTarget* target)
{
    target->draw(_shape);
}
