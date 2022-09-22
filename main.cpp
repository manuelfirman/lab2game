#include "game.h"

int main()
{
    Game game;

    while(!game.GetVentana()->Ok()){
        game.HandleInput();
        game.actualizar();
        game.renderizar();
        game.RestartClock();
    }
    return 0;
}
