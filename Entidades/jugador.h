#ifndef JUGADOR_H
#define JUGADOR_H

#include <Entidades.h>


class Jugador : public Entidades
{
    private: // Atributos


    private: // Metodos
        void iniciarVariables();
        void iniciarComponentes();

    public:
        Jugador(float x, float y, sf::Texture* textura);
        ~Jugador();
};

#endif // JUGADOR_H
