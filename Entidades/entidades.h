#ifndef ENTIDADES_H
#define ENTIDADES_H

#include "movimiento.h"

class Entidades
{
    private: // Metodos
        void iniciarVariables();



    protected: // Atributos
        sf::Texture* _textura; // puntero para no duplicar la textura
        sf::Sprite* _sprite;

        Movimiento* movimiento;



    public:
        Entidades();
        virtual ~Entidades();
        // Funciones de componentes
        void crearSprite(sf::Texture* textura);
        void crearComponenteMovimiento(const float velocidadMaxima);

        /// Overriders
        virtual void setPosicion(const float x, const float y);
        virtual void mover(const float& DT, const float x, const float y);
        virtual void actualizar(const float& DT);
        virtual void renderizar(sf::RenderTarget* target);
};

#endif // ENTIDADES_H
