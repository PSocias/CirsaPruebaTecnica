// CirsaPruebaTécnica.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Ejercicio1.h"
#include "Ejercicio2.h"

using namespace std;

int main()
{
    // Testing Ejercicio 1
    cout << "Numero 9: " << Ejercicio1::ConvertirASaludo(9) << endl;
    cout << "Numero 1: " << Ejercicio1::ConvertirASaludo(1) << endl;
    cout << "Numero 10: " << Ejercicio1::ConvertirASaludo(10) << endl;
    cout << "Numero 5: " << Ejercicio1::ConvertirASaludo(5) << endl;
    cout << "Numero 15: " << Ejercicio1::ConvertirASaludo(15) << endl;
    cout << "Numero 31: " << Ejercicio1::ConvertirASaludo(31) << endl;
    cout << "Numero 32: " << Ejercicio1::ConvertirASaludo(32) << endl;
    cout << "Numero 0: " << Ejercicio1::ConvertirASaludo(0) << endl;

    // Testing Ejercicio 2
    NuevoJuego t;
    Juego& j = t;

    j.Jugar();

    t.Girar();
    t.PulsarPantalla();

    cout << "Nuevo juego funciona ahora con normalidad" << endl;
}




