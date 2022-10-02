#ifndef ANIMACION_H
#define ANIMACION_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include <map>

class Animacion // Componente Animacion
{
    private:
        class setAnimacion // Animacion (No puede instanciarse por fuera de clase Animacion)
        {
            public:
            // Atributos
                sf::Sprite& _spriteA;
                sf::Texture& _texturaA;
                float _velocidad;
                float _tiempoAnimacion;
                float _timer;
                int _ancho;
                int _alto;

                sf::IntRect _cuadroInicial;
                sf::IntRect _cuadroActual;
                sf::IntRect _cuadroFinal;

            // Constructor/Dtor
                setAnimacion(sf::Sprite& sprite, sf::Texture& textura, float tiempoAnimacion, int inicio_x, int inicio_y, int frames_x, int frames_y, int ancho, int alto)
                    : _spriteA(sprite), _texturaA(textura), _ancho(ancho), _alto(alto), _tiempoAnimacion(tiempoAnimacion)
                {
                    _timer = 0.f;
                    _cuadroInicial = sf::IntRect(inicio_x * ancho, inicio_y * alto, ancho, alto);
                    _cuadroActual = _cuadroInicial;
                    _cuadroFinal = sf::IntRect(frames_x * ancho, frames_y * alto, ancho, alto);

                    _spriteA.setTexture(_texturaA);
                    _spriteA.setTextureRect(_cuadroInicial);


                }
//                ~setAnimacion();

            // Metodos
                void play(const float& DT)
                {
                    _timer += 100.f * DT;
                    if(_timer >= _tiempoAnimacion){

                        // reset timer
                        _timer = 0.f;

                        if(_cuadroActual != _cuadroFinal)
                        {
                            // Animar
                            _cuadroActual.left += _ancho;
//                            std::cout << "play" << std::endl;
                        }
                        else
                        {
//                            std::cout << "reset" << std::endl;
                            // reset animacion
                            _cuadroActual.left = _cuadroInicial.left;
                        }

                        _spriteA.setTextureRect(_cuadroActual);
                    }
                }


                void reset()
                {
                    _timer = 0.f;
                    _cuadroActual = _cuadroInicial;
                }
        };

        sf::Sprite& _spriteCA;
        sf::Texture& _texturaCA;
        std::map<std::string, setAnimacion*> _animaciones;
        setAnimacion* _ultimaAnimacion;

    public:
        // Constructor - Forzando a usar sprite y textura - No se puede tener animacion sin ellos
        Animacion(sf::Sprite& sprite, sf::Texture& textura);
        virtual ~Animacion();

        // Metodos
        void agregarAnimacion(const std::string key, float tiempoAnimacion, int inicio_x, int inicio_y, int frames_x, int frames_y, int ancho, int alto);

        void play(const std::string key, const float& DT);

};

#endif // ANIMACION_H
