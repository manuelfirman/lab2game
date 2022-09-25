#ifndef GAME_H
#define GAME_H

#include "estadojuego.h"
#include "estadomenuprincipal.h"

class Game{
private: // Variables

	sf::RenderWindow* _ventana; // memoria dinamica
	sf::Event sfEvento;
	std::vector<sf::VideoMode> _modosDeVideo;
	sf::ContextSettings _configVentana;
	bool _fullscreen;

	sf::Clock relojDt;
	float _DT;

	std::stack<EstadoBase*> _estado;
	std::map<std::string, int> _teclasSoportadas;

private: // Funciones
    void iniciarVariables();
    void iniciarVentana();
    void iniciarEstados();
    void iniciarTeclas();

public:
	Game();
	~Game();


	/// Actualizar
    void actualizarDT();
	void actualizarEventosSFML();
	void actualizar();

	/// Renderizar
	void renderizar();

	/// Core
	void gameloop();

	void finAplicacion();
};

#endif // GAME_H
