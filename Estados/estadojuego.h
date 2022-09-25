#ifndef ESTADOJUEGO_H
#define ESTADOJUEGO_H
#include "estadobase.h"
#include "jugador.h"


class EstadoJuego : public EstadoBase
{
    private: // Atributos
        Jugador* player;


    private: // Metodos
        void iniciarKeybinds();
        void iniciarTexturas();
        void iniciarJugadores();

    public:
        EstadoJuego(sf::RenderWindow* ventana, std::map<std::string, int>* teclasSoportadas, std::stack<EstadoBase*>* estado);
        ~EstadoJuego();



        void actualizarInput(const float& DT);
        void actualizar(const float& DT);
        void renderizar(sf::RenderTarget* target = NULL);
};

#endif // ESTADOJUEGO_H
