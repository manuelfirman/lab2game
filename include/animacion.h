#ifndef ANIMACION_H
#define ANIMACION_H
#include <SFML/Graphics.hpp>
#include <iostream>

class Animacion
{
    private:
        sf::Vector2u _framesImagen;
        sf::Vector2u _imagenActual;

        float _tiempoAnimacion;
        float _tiempoCambioImagen;

    public:
        sf::IntRect _rect;
        Animacion(sf::Texture* textura, sf::Vector2u framesImagen, float tiempoCambioImagen);
        ~Animacion();

        void actualizar(int columna, const float& deltaTime);
        sf::IntRect getRect();
};


#endif // ANIMACION_H
