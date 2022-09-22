#include "ventana.h"

/// CONSTRUCTOR - DESTRUCTOR
Ventana::Ventana()
{
    SetUp("Window", sf::Vector2u(640,480));
}

Ventana::Ventana(const std::string& tituloVentana, const sf::Vector2u& sizeVentana)
{
    SetUp(tituloVentana, sizeVentana);
}

Ventana::~Ventana()
{
    Destruir();
}


/// SET UP
void Ventana::SetUp(const std::string& tituloVentana, const sf::Vector2u& sizeVentana)
{
    _tituloVentana = tituloVentana;
    _sizeVentana = sizeVentana;
    _fullScreen = false;
    _ok = false;
    Crear();
}

void Ventana::Crear()
{
    auto style = (_fullScreen ? sf::Style::Fullscreen : sf::Style::Default);
    _ventana.create({_sizeVentana.x, _sizeVentana.y, 32}, _tituloVentana, style);
}

void Ventana::Destruir()
{
    _ventana.close();
}


void Ventana::AlternarFullScreen()
{
    _fullScreen = !_fullScreen;
    Destruir();
    Crear();
}


/// GETTERS
bool Ventana::Ok() { return _ok; }

bool Ventana::getFullScreen(){ return _fullScreen; }

sf::Vector2u Ventana::getSizeVentana(){ return _sizeVentana; }


/// ACTUALIZAR
void Ventana::Actualizar()
{
    sf::Event event;
    while(_ventana.pollEvent(event)){
        if(event.type == sf::Event::Closed){
            _ok = true;
        } else if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F5){
            AlternarFullScreen();
        }
    }
}

void Ventana::Limpiar()
{
    _ventana.clear(sf::Color::Black);
}

void Ventana::Mostrar()
{
    _ventana.display();
}

/// DIBUJAR
void Ventana::Dibujar(sf::Drawable& dibujable)
{
    _ventana.draw(dibujable);
}
