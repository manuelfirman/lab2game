#include "jugador.h"
/// --------------------- INICIALIZACIONES --------------------------
void Jugador::iniciarVariables()
{

}

void Jugador::iniciarComponentes()
{

}


/// --------------------- CONSTRUCTOR / DESTRUCTOR ---------------------
Jugador::Jugador(float x, float y, sf::Texture& textura)
{
    this->iniciarVariables();

    setPosicion(x, y);

    crearComponenteMovimiento(200.f, 15.f, 4.f); // Movimiento
    crearComponenteAnimacion(textura);

                                // key - timer - inicioX - inicioY - framesX - framesY
    _animacion->agregarAnimacion("CAMINAR_QUIETO", 10.f, 1, 20, 5, 20, 64, 64);
    _animacion->agregarAnimacion("CAMINAR_ABAJO", 10.f, 1, 10, 8, 10, 64, 64);
    _animacion->agregarAnimacion("CAMINAR_ARRIBA", 10.f, 1, 8, 8, 8, 64, 64);
    _animacion->agregarAnimacion("CAMINAR_DERECHA", 10.f, 1, 11, 8, 11, 64, 64);
    _animacion->agregarAnimacion("CAMINAR_IZQUIERDA", 10.f, 1, 9, 8, 9, 64, 64);
}

Jugador::~Jugador()
{
    //dtor
}

void Jugador::actualizar(const float& DT)
{
    _movimiento->actualizar(DT);

    if(_movimiento->getEstadoMov(QUIETO))
        _animacion->play("CAMINAR_QUIETO", DT);
    else if(_movimiento->getEstadoMov(MOV_ABAJO))
        _animacion->play("CAMINAR_ABAJO", DT);
    else if(_movimiento->getEstadoMov(MOV_ARRIBA))
        _animacion->play("CAMINAR_ARRIBA", DT);
    else if(_movimiento->getEstadoMov(MOV_DERECHA))
        _animacion->play("CAMINAR_DERECHA", DT);
    else if(_movimiento->getEstadoMov(MOV_IZQUIERDA))
        _animacion->play("CAMINAR_IZQUIERDA", DT);

}
