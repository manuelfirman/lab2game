#ifndef ESTADO_BASE_H
#define ESTADO_BASE_H
#include <vector>
#include <ctime>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
class Estado_Base
{
    private:
    std::vector<sf::Texture> texturas;


    public:
        Estado_Base();
        virtual ~Estado_Base();


        virtual void actualizar() = 0;
        virtual void renderizar() = 0;

};

#endif // ESTADO_BASE_H
