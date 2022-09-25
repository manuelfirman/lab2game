#ifndef ESTADOBASE_H
#define ESTADOBASE_H
#include "entidades.h"

class EstadoBase
{
    private:


    protected: // Atributos
        std::stack<EstadoBase*>* _estado; // Pila de punteros que apuntan a pila de punteros EstadoBase (Para no hacer una copia)

        sf::RenderWindow* _ventana;
        std::map<std::string, int>* _teclasSoportadas;
        std::map<std::string, int> _keybinds;
        bool _salir;

        sf::Vector2i posMousePantalla;
        sf::Vector2i posMouseVentana;
        sf::Vector2f posMouseVista;

        std::map<std::string, sf::Texture> _texturas;

    protected: // Metodos
        virtual void iniciarKeybinds() = 0;

    public:
        EstadoBase(sf::RenderWindow* ventana, std::map<std::string, int>* teclasSoportadas, std::stack<EstadoBase*>* estado);
        virtual ~EstadoBase();

        // salida de estado
        const bool& getSalir() const;
        void finEstado();

        // Funciones
        virtual void actualizarPosicionMouse();

        // virtuales puras
        virtual void actualizarInput(const float& DT) = 0;
        virtual void actualizar(const float& DT) = 0;
        virtual void renderizar(sf::RenderTarget* target = NULL) = 0;
};

#endif // ESTADOBASE_H
