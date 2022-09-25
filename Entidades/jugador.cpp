#include "jugador.h"
/// --------------------- INICIALIZACIONES --------------------------
void Jugador::iniciarVariables()
{

}

void Jugador::iniciarComponentes()
{
    crearComponenteMovimiento(20.f);
}


/// --------------------- CONSTRUCTOR / DESTRUCTOR ---------------------
Jugador::Jugador(float x, float y, sf::Texture* textura)
{
    this->iniciarVariables();
    this->iniciarComponentes();

    crearSprite(textura);
    setPosicion(x, y);

}

Jugador::~Jugador()
{
    //dtor
}
