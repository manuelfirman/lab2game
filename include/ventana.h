#ifndef VENTANA_H
#define VENTANA_H
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class Ventana
{
    private:
        sf::RenderWindow _ventana;
        sf::Vector2u _sizeVentana;
        std::string _tituloVentana;
        bool _ok;
        bool _fullScreen;

    private:
        void SetUp(const std::string& tituloVentana, const sf::Vector2u& sizeVentana);
        void Destruir();
        void Crear();
    public:
        Ventana();
        Ventana(const std::string& tituloVentana, const sf::Vector2u& sizeVentana);
        ~Ventana();

        bool Ok();
        bool getFullScreen();
        sf::Vector2u getSizeVentana();

        void Limpiar();
        void Mostrar();
        void Actualizar();
        void AlternarFullScreen();
        void Dibujar(sf::Drawable& dibujable);

};

#endif // VENTANA_H
