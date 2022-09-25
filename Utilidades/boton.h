#ifndef BOTON_H
#define BOTON_H

#include <SFML/Graphics.hpp>
#include <iostream>


class Boton
{
    private:
        enum BOTON{
            INACTIVO,
            HOVER,
            ACTIVO
        };

        BOTON _estado;

        sf::RectangleShape _boton;
        sf::Font* _fuente;
        sf::Text _texto;

        sf::Color _colorBotonInactivo;
        sf::Color _colorBotonHover;
        sf::Color _colorBotonActivo;

        sf::Color _colorTexto;
    public:
        Boton(sf::Vector2f tamanio, std::string texto, int tamanioLetra, sf::Font& fuente, sf::Color colorBotonInactivo, sf::Color colorBotonHover, sf::Color colorBotonActivo, sf::Color colorTexto);
        ~Boton();


        void setFuente(sf::Font& fuente);
        void setColorBoton(sf::Color colorBoton);
        void setColorTexto(sf::Color colorTexto);
        void setPosicion(sf::Vector2f posicion);
        void actualizar(sf::Vector2f posMouse);
        bool getClick();
        void renderizar(sf::RenderTarget* target);

};

#endif // BOTON_H
