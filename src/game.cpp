#include "Game.h"

Game::Game(): _ventana("Chapter 2", sf::Vector2u(800,600)){
	RestartClock();
	srand(time(NULL));

	// Setting up class members.
	m_mushroomTexture.loadFromFile("Mushroom.png");
	m_mushroom.setTexture(m_mushroomTexture);
	m_increment = sf::Vector2i(400,400);
}

Game::~Game()
{

}

sf::Time Game::GetElapsed(){ return _elapsed; }
void Game::RestartClock(){ _elapsed = _clock.restart(); }
Ventana* Game::GetVentana(){ return &_ventana; }

void Game::HandleInput(){
	// Input handling.
}

void Game::actualizar(){
	_ventana.Actualizar();
	MoveMushroom();
}

void Game::MoveMushroom(){
	sf::Vector2u l_windSize = _ventana.getSizeVentana();
	sf::Vector2u l_textSize = m_mushroomTexture.getSize();

	if ((m_mushroom.getPosition().x >
		l_windSize.x - l_textSize.x && m_increment.x > 0) ||
		(m_mushroom.getPosition().x < 0 && m_increment.x < 0)){
		m_increment.x = -m_increment.x;
	}

	if ((m_mushroom.getPosition().y >
		l_windSize.y - l_textSize.y && m_increment.y > 0) ||
		(m_mushroom.getPosition().y < 0 && m_increment.y < 0)){
		m_increment.y = -m_increment.y;
	}

	float fElapsed = _elapsed.asSeconds();

	m_mushroom.setPosition(
		m_mushroom.getPosition().x + (m_increment.x * fElapsed),
		m_mushroom.getPosition().y + (m_increment.y * fElapsed));
}

void Game::renderizar(){
	_ventana.Limpiar(); // Clear.
	_ventana.Dibujar(m_mushroom);
	_ventana.Mostrar(); // Display.
}
