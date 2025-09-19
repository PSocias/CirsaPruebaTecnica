#pragma once
#include <string>
#include <vector>

using namespace std;

class Ejercicio1
{
public:
	static string ConvertirASaludo(int numero);

private:
	static string ConseguirString(int numero);
	static vector<string> ConseguirAcciones(const string& binario);
};

