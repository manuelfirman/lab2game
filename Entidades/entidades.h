#ifndef ENTIDADES_H
#define ENTIDADES_H

#include "movimiento.h"

class Entidades
{
    private: // Metodos
        void iniciarVariables();



    protected: // Atributos
        sf::Sprite _sprite;

        Movimiento* movimiento;



    public:
        Entidades();
        virtual ~Entidades();
        // Funciones de componentes
        void setTextura(sf::Texture& textura);
        void crearComponenteMovimiento(float velocidadMaxima, float aceleracion, float desaceleracion);

        /// Overriders
        virtual void setPosicion(const float x, const float y);
        virtual void mover(const float x, const float y, const float& DT);
        virtual void actualizar(const float& DT);
        virtual void renderizar(sf::RenderTarget* target);
};

#endif // ENTIDADES_H
