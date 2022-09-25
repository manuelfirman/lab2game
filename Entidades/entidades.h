#ifndef ENTIDADES_H
#define ENTIDADES_H

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

class Entidades
{
    private:

    protected:
        sf::RectangleShape _shape;
        float _velocidad;


    public:
        Entidades();
        virtual ~Entidades();

        virtual void mover(const float& DT, const float x, const float y);

        virtual void actualizar(const float& DT);
        virtual void renderizar(sf::RenderTarget* target);
};

#endif // ENTIDADES_H
