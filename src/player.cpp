#include "player.h"

void Player::crearAnimacion()
{

}

void Player::iniciarVariables()
{

}

void Player::iniciarTextura()
{
    _textura.loadFromFile("1.png");
    _sprite.setTexture(_textura);
}


Player::Player()
{
    this->iniciarTextura();
}

Player::~Player()
{
    //dtor
}
