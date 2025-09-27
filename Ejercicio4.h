#pragma once
#include <string>
#include <vector>

using namespace std;

// Comandos posibles
enum class Comando 
{ 
    GIRO_DERECHA = 'D', 
    GIRO_IZQUIERDA = 'I',
    AVANZA = 'A',
    RETROCEDE = 'R',
    ATORNILLA = 'T'
};

// Clase base abstracta para todos los robots
class Robot
{
public:
    Robot(const string& modelo, int numero_linea);
    virtual ~Robot() = default;

    // Métodos comunes a todos los robots
    virtual void EjecutarComando(Comando comando) = 0;
    virtual string ObtenerRespuestaComando(Comando comando) = 0;

    virtual void EjecutarSecuencia(const vector<Comando>& comandos);
    string ObtenerRespuestaSecuencia(const vector<Comando>& comandos);

    // Getters
    string GetModelo() const { return modelo_; }
    int GetNumeroLinea() const { return numero_linea_; }

protected:
    string modelo_;
    int numero_linea_;
};

// Modelo A - Movimiento básico
class RobotModeloA : public Robot {
public:
    RobotModeloA(int numero_linea);
    void EjecutarComando(Comando comando) override;
    string ObtenerRespuestaComando(Comando comando) override;

    // Getters
    int getX() const { return x_; }
    int getY() const { return y_; }

private:
    int direccion_; // 0: Norte, 1: Este, 2: Sur, 3: Oeste
    int x_, y_; // Coordenadas
};

// Modelo B - Movimiento + Atornillado
class RobotModeloB : public Robot {
public:
    RobotModeloB(int numero_linea);
    void EjecutarComando(Comando comando) override;
    string ObtenerRespuestaComando(Comando comando) override;

    // Getter
    int GetTornillosAtornillados() const { return tornillos_atornillados_; }

private:
    int tornillos_atornillados_;
};

vector<Comando> StringAComandos(const string& str);
void TestRobots();


