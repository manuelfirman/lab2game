#include "jugador.h"
/// --------------------- INICIALIZACIONES --------------------------
void Jugador::iniciarVariables()
{

}

void Jugador::iniciarComponentes()
{
    crearComponenteMovimiento(100.f, 5.f, 2.f);
}


/// --------------------- CONSTRUCTOR / DESTRUCTOR ---------------------
Jugador::Jugador(float x, float y, sf::Texture& textura)
{
    this->iniciarVariables();
    this->iniciarComponentes();

    setTextura(textura);
    setPosicion(x, y);

}

Jugador::~Jugador()
{
    //dtor
}
