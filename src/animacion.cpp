#include "animacion.h"

Animacion::Animacion(sf::Texture* textura, sf::Vector2u framesImagen, float tiempoCambioImagen)
{
    _framesImagen = framesImagen;
    _tiempoCambioImagen = tiempoCambioImagen;
    _tiempoAnimacion = 0.0f;
    _imagenActual.x = 0;

    _rect.width = textura->getSize().x / float(framesImagen.x);
    _rect.height = textura->getSize().y / float(framesImagen.y);
}

Animacion::~Animacion()
{
    //dtor
}

void Animacion::actualizar(int columna, const float& deltaTime)
{
    _imagenActual.y = columna;
    _tiempoAnimacion += deltaTime;

    if(_tiempoAnimacion >= _tiempoCambioImagen)
    {
        _tiempoAnimacion -= _tiempoCambioImagen;
        _imagenActual.x++;

        if(_imagenActual.x >= _framesImagen.x)
        {
            _imagenActual.x = 0;
        }
    }

    _rect.left = _imagenActual.x * _rect.width;
    _rect.top = _imagenActual.y * _rect.height;
}
