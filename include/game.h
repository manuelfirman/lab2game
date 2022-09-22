#ifndef GAME_H
#define GAME_H

#include "Ventana.h"

class Game{
private:

	Ventana _ventana;
	sf::Clock _clock;
	sf::Time _elapsed;

	sf::Texture m_mushroomTexture;
	sf::Sprite m_mushroom;
	sf::Vector2i m_increment;

private:
	void MoveMushroom();

public:
	Game();
	~Game();

	void HandleInput();
	void actualizar();
	void renderizar();

	Ventana* GetVentana();

	sf::Time GetElapsed();
	void RestartClock();
};

#endif // GAME_H
