#ifndef ESTADOBASE_H
#define ESTADOBASE_H
#include "entidades.h"

class EstadoBase
{
    private:

    protected: // Variables
        sf::RenderWindow* _ventana;
        std::map<std::string, int>* _teclasSoportadas;
        std::map<std::string, int> _keybinds;
        bool _salir;

        std::vector<sf::Texture> _texturas;

    protected: // Funciones
        virtual void iniciarKeybinds() = 0;

    public:
        // Const - Dtor
        EstadoBase(sf::RenderWindow* ventana, std::map<std::string, int>* teclasSoportadas);
        virtual ~EstadoBase();

        // salida de estado
        virtual void checkSalir();
        const bool& getSalir() const;

        // virtuales puras
        virtual void finEstado() = 0;
        virtual void actualizarInput(const float& DT) = 0;
        virtual void actualizar(const float& DT) = 0;
        virtual void renderizar(sf::RenderTarget* target = NULL) = 0;

};

#endif // ESTADOBASE_H
