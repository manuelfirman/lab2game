#ifndef GAME_H
#define GAME_H
#include "Estado_Base.h"

class Game{
private:

	sf::RenderWindow* _ventana; // memoria dinamica
	sf::Event sfEvento;

	sf::Clock relojDt;
	float _DT;

private:
    void iniciarVariables();
    void iniciarVentana();

public:
	Game();
	~Game();
    void actualizarDT();
	void actualizarEventosSFML();
	void actualizar();
	void renderizar();
	void gameloop();
};

#endif // GAME_H
