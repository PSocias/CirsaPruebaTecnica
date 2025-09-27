#pragma once
#include <string>

using namespace std;

class Maquina{
public:
	Maquina(string p_modelo,string p_juego, int p_juegos_instalados) :
	modelo_(p_modelo), juego_(p_juego), juegos_instalados_(p_juegos_instalados) {}

	int GetNumJuegos() { return juegos_instalados_; }
private:

	string modelo_;
	string juego_;
 
int juegos_instalados_;
};

