#include "Ejercicio1.h"
#include <bitset>
#include <sstream>

string Ejercicio1::ConvertirASaludo(int numero)
{
	if (numero < 1 || numero > 31) // Comprobamos que no se salga del rango establecido
	{
		return "Numero invalido";
	}

	string binario = ConseguirString(numero); // Obtenemos los últimos 5 bits de nuestro número y los convertimos en tipo string
	vector<string> acciones = ConseguirAcciones(binario);
	
	if (acciones.empty())
	{
		return "No hay acciones para este numero";
	}

	// Creamos un stringstream para debugar el resultado
	stringstream resultado;
	resultado << "Tu saludo es ";

	// le añadimos las acciones necesarias
	for (int i = 0; i < acciones.size(); i++)
	{
		if (i > 0) 
		{
			if (i == acciones.size() - 1)
			{
				resultado << " y "; // Si solo queda 1 accion, añadimos "y"
			}
			else
			{
				resultado << ", "; // si queda mas de una accion, añadimos ","
			}
		}
		resultado << acciones[i];
	}
	return resultado.str(); // Devolvemos tras añadir las acciones
}

string Ejercicio1::ConseguirString(int numero)
{
	// Usamos bitset para obtener los ultimos 5 bits de la derecha
	bitset<5> bits(numero);
	return bits.to_string(); // Convertimos los 5 bits a string
}

vector<string> Ejercicio1::ConseguirAcciones(const string& binario)
{
	vector<string> acciones;

	// Los bits están ordenados de izquierda a derecha, pero los necesitamos leer al reves
	const int length = binario.length();

	// Mapeo de posiciones (de derecha a izquierda) a acciones. Buscamos la posición del 1 para determinar que saludo corresponde
	if (binario[length - 1] == '1') acciones.push_back("parpadeo");
	if (binario[length - 2] == '1') acciones.push_back("guiño");
	if (binario[length - 3] == '1') acciones.push_back("cierra los ojos");
	if (binario[length - 4] == '1') acciones.push_back("salto");
	if (binario[length - 5] == '1') acciones.push_back("Haz el saludo contrario");
	
	return acciones;
}
