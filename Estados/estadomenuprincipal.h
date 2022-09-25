#ifndef ESTADOMENUPRINCIPAL_H
#define ESTADOMENUPRINCIPAL_H
#include "estadobase.h"
#include "estadojuego.h"
#include "boton.h"

class EstadoMenuPrincipal : public EstadoBase
{
    private: // Variables
        sf::RectangleShape _fondoMenu;
        sf::Font _fuenteMenu;
        sf::Font _fuenteBoton;

        std::map<std::string, Boton*> _boton;

    private: // Funciones
        void iniciarKeybinds();
        void iniciarFuentes();
        void iniciarBotones();

    public:
        EstadoMenuPrincipal(sf::RenderWindow* ventana, std::map<std::string, int>* teclasSoportadas, std::stack<EstadoBase*>* estado);
        ~EstadoMenuPrincipal();

        void actualizarBotones();
        void renderBotones(sf::RenderTarget* target);

        void finEstado();

        void actualizarInput(const float& DT);
        void actualizar(const float& DT);
        void renderizar(sf::RenderTarget* target = NULL);
};

#endif // ESTADOMENUPRINCIPAL_H