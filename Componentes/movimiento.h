#ifndef MOVIMIENTO_H
#define MOVIMIENTO_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include <vector>
#include <stack>
#include <map>
#include <ctime>
#include <cstdlib>
#include <iostream>

#include <fstream>

class Movimiento
{
    private: // Atributos
        float _velocidadMax;
        sf::Vector2f _velocidad;
        sf::Vector2f _aceleracion;
        sf::Vector2f _desaceleracion;

    public:
        Movimiento(float velocidadMaxima, float aceleracion, float desaceleracion);
        virtual ~Movimiento();

        const sf::Vector2f& getVelocidad() const;

        void mover(const float dir_x, const float dir_y);
        void actualizar(const float& DT);



};

#endif // MOVIMIENTO_H
