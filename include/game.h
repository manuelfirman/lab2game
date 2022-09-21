#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "animacion.h"
class Game
{
    private:
        sf::RenderWindow* _ventana;
        sf::VideoMode _modoVideo;
        sf::Event _evento;
        int _fps;

        sf::Texture _textura;
        sf::Sprite _sprite;

        sf::Clock relojDelta;
        float _deltaTime;

        Animacion* animacion;
    private:
        void iniciarVariables();
        void iniciarVentana();

    public:
        Game();
        ~Game();

        void actualizarEventos();
        void actualizarDeltaTime();
        void actualizar();
        void renderizar();
        void gameloop();
        void finAplicacion();
};

#endif // GAME_H
