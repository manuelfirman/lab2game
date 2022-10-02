#include "animacion.h"

Animacion::Animacion(sf::Sprite& sprite, sf::Texture& textura)
    : _spriteCA(sprite), _texturaCA(textura), _ultimaAnimacion(NULL)
{
    //ctor
}

Animacion::~Animacion()
{
    for(auto &animaciones : _animaciones){
        delete animaciones.second;
    }
}

void Animacion::agregarAnimacion(const std::string key, float tiempoAnimacion, int inicio_x, int inicio_y, int frames_x, int frames_y, int ancho, int alto)
{
    _animaciones[key] = new setAnimacion(_spriteCA, _texturaCA, tiempoAnimacion, inicio_x, inicio_y, frames_x, frames_y, ancho, alto);
}



void Animacion::play(const std::string key, const float& DT)
{
    if(_ultimaAnimacion != _animaciones[key] && _ultimaAnimacion != NULL)
    {
        if(_ultimaAnimacion == NULL){
            _ultimaAnimacion = _animaciones[key];
        }
        else{
            _ultimaAnimacion->reset();
            _ultimaAnimacion = _animaciones[key];
        }
    }
    _animaciones[key]->play(DT);
}
