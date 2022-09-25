#ifndef ESTADOJUEGO_H
#define ESTADOJUEGO_H
#include "estadobase.h"


class EstadoJuego : public EstadoBase
{
    private: // Variables
        Entidades player;


    private: // Funciones
        void iniciarKeybinds();
    public:
        EstadoJuego(sf::RenderWindow* ventana, std::map<std::string, int>* teclasSoportadas);
        ~EstadoJuego();

        void finEstado();

        void actualizarInput(const float& DT);
        void actualizar(const float& DT);
        void renderizar(sf::RenderTarget* target = NULL);
};

#endif // ESTADOJUEGO_H
