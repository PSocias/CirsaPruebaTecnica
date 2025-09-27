#include "Ejercicio4.h"
#include <iostream>
#include <sstream>

Robot::Robot(const string& modelo, int numero_linea)
{
	modelo_ = modelo;
	numero_linea_ = numero_linea;
}

void Robot::EjecutarSecuencia(const vector<Comando>& comandos)
{
	for (Comando cmd: comandos)
	{
		EjecutarComando(cmd);
	}
}

string Robot::ObtenerRespuestaSecuencia(const vector<Comando>& comandos)
{
	stringstream ss;
	for (int i = 0; i < comandos.size(); ++i) {
		ss << ObtenerRespuestaComando(comandos[i]);
		if (i < comandos.size() - 1) {
			ss << ",";
		}
	}
	return ss.str();
}


// Robot Modelo A
RobotModeloA::RobotModeloA(int numero_linea)
	: Robot("ModeloA", numero_linea), x_(0), y_(0), direccion_(0) {}

void RobotModeloA::EjecutarComando(Comando comando) {
	switch (comando) 
	{
	case Comando::GIRO_DERECHA:
		direccion_ = (direccion_ + 1) % 4; // Giro horario
		break;
	case Comando::GIRO_IZQUIERDA:
		direccion_ = (direccion_ + 3) % 4; // Giro antihorario
		break;
	case Comando::AVANZA:
		switch (direccion_) {
		case 0: y_++; break; // Norte
		case 1: x_++; break; // Este  
		case 2: y_--; break; // Sur
		case 3: x_--; break; // Oeste
		}
		break;
	case Comando::RETROCEDE:
		switch (direccion_) {
		case 0: y_--; break; // Norte
		case 1: x_--; break; // Este
		case 2: y_++; break; // Sur
		case 3: x_++; break; // Oeste
		}
		break;
	case Comando::ATORNILLA:
		// Modelo A no sabe atornillar
		cout << "Modelo A no puede atornillar" << endl;
		break;
	}
}

string RobotModeloA::ObtenerRespuestaComando(Comando comando) {
	switch (comando) {
	case Comando::GIRO_DERECHA: return "Giro Derecha";
	case Comando::GIRO_IZQUIERDA: return "Giro Izquierda";
	case Comando::AVANZA: return "Avanza";
	case Comando::RETROCEDE: return "Retrocede";
	case Comando::ATORNILLA: return "Atornilla";
	default: return "Desconocido";
	}
}


// Robot Modelo B
RobotModeloB::RobotModeloB(int numero_linea)
	: Robot("ModeloB", numero_linea), tornillos_atornillados_(0) {
}

void RobotModeloB::EjecutarComando(Comando comando) {
	switch (comando)
	{
	case Comando::GIRO_DERECHA:
		break;
	case Comando::GIRO_IZQUIERDA:
		break;
	case Comando::ATORNILLA:
		tornillos_atornillados_++;
		break;
	case Comando::AVANZA:
		// Modelo B no se mueve
		cout << "Modelo B no puede moverse" << endl;
		break;
	case Comando::RETROCEDE:
		// Modelo B no se mueve
		cout << "Modelo B no puede moverse" << endl;
		break;
	}
}

string RobotModeloB::ObtenerRespuestaComando(Comando comando) {
	switch (comando) {
	case Comando::GIRO_DERECHA: return "Giro Derecha";
	case Comando::GIRO_IZQUIERDA: return "Giro Izquierda";
	case Comando::ATORNILLA: return "Atornillo";
	case Comando::AVANZA: return "Comando no disponible";
	case Comando::RETROCEDE: return "Comando no disponible";
	default: return "Desconocido";
	}
}

vector<Comando> StringAComandos(const string& str) {
	vector<Comando> comandos;
	for (char c : str) {
		comandos.push_back(static_cast<Comando>(c));
	}
	return comandos;
}

void TestRobots() {
	cout << "=== PRUEBAS DE ROBOTS ===" << endl;

	// Test Modelo A
	cout << "TEST MODELO A:" << endl;
	RobotModeloA robotA(1);
	vector<Comando> secuenciaA = StringAComandos("AAIAADR");

	cout << "Secuencia: A,A,I,A,A,D,R" << endl;
	robotA.EjecutarSecuencia(secuenciaA);
	cout << "Posicion final: (" << robotA.getX() << ", " << robotA.getY() << ")" << endl;

	// Test Modelo B  
	cout << "TEST MODELO B:" << endl;
	RobotModeloB robotB(2);
	vector<Comando> secuenciaB = StringAComandos("DTTIT");

	cout << "Secuencia: D,T,T,I,T" << endl;
	string respuesta = robotB.ObtenerRespuestaSecuencia(secuenciaB);
	cout << "Respuesta: " << respuesta << endl;

	cout << "Esperado: Giro Derecha,Atornillo,Atornillo,Giro Izquierda,Atornillo" << endl;
}

