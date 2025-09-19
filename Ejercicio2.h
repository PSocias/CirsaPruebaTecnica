#pragma once

/*
struct Juego 
{
	virtual ~Juego() = default;
	virtual void Jugar() {}
};
struct Rodillos : Juego {
	virtual void Girar() {}
};
struct Seleccion : Juego {
	virtual void PulsarPantalla() {}
};
// NuevoJuego es un juego de rodillos y selección
struct NuevoJuego : Rodillos, Seleccion {};
NuevoJuego Tetris;
Juego& j = t;
*/

// El problema se origina devido a la heréncia multiple de NuevoJuego (diamond problem). Al heredar tanto Rodillos como
// Seleccion de Juego, cuando intentamos hacer Juego& j = t, se crea una ambiguedad ya que no sabe a cual de las dos
// clases padre Juego igualar. Al hacer la herencia de Rodillos y Seleccion virtual, nos aseguramos que solo se crea una 
// instáncia de su clase padre Juego, evitando la ambiguedad y el error de compilación.

struct Juego 
{
	virtual ~Juego() = default;
	virtual void Jugar() {}
};

struct Rodillos:  virtual Juego // Herencia virtual
{
	virtual void Girar() {};
};
struct Seleccion :  virtual Juego // Herencia virtual
{
	virtual void PulsarPantalla() {}
};
// NuevoJuego es un juego de rodillos y selección
struct NuevoJuego : Rodillos, Seleccion {};

