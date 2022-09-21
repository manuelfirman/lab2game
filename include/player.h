#ifndef PLAYER_H
#define PLAYER_H
#include <SFML\Graphics.hpp>
class Player
{
    private:
        sf::Texture _textura;
        sf::Sprite _sprite;

        void crearAnimacion();
        void iniciarVariables();
        void iniciarTextura();
    public:
        Player();
        ~Player();

        void setPosition(int x, int y);
};

#endif // PLAYER_H
