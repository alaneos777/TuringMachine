/*
Proyecto final de teoría computacional
	Grupo: 2CM4
	Integrantes:
		-Fuentes García Alan Kevin
		-López Leal Irving
		-Ontiveros Salazar Alan Enrique
		-Ruiz Lopez Luis Carlos
	Descripción: implementación de la Máquina de Turing
	determinista de una sola cinta
	Aplicación: convertidor de decimal a binario
*/

#include <bits/stdc++.h>
#include "TuringMachine.cpp"

using namespace std;

int main(){
	int estados, estadoInicial;
	int numEstadosFinales, numTransiciones;
	char blank;
	string alfabetoCinta;

	cout << "Introduce el numero de estados: ";
	cin >> estados;

	cout << "Introduce el alfabeto de cinta: ";
	cin >> alfabetoCinta;

	cout << "Introduce el simbolo blanco: ";
	cin >> blank;

	cout << "Introduce el estado inicial: ";
	cin >> estadoInicial;

	cout << "Introduce el numero de estados finales: ";
	cin >> numEstadosFinales;

	cout << "Introduce los " << numEstadosFinales << " estados finales:\n";

	vector<int> estadosFinales(numEstadosFinales);
	for(int i = 0; i < numEstadosFinales; i++){
		cin >> estadosFinales[i];
	}

	cout << "Introduce el numero de transiciones: ";
	cin >> numTransiciones;

	cout << "Introduce las " << numTransiciones << " en la forma delta(q, a) = (p, b, d):\n";

	TuringMachine * MT = new TuringMachine(estados, vector<char>(alfabetoCinta.begin(), alfabetoCinta.end()), blank, estadoInicial, estadosFinales);

	int q, p, d;
	char a, b;

	for(int i = 0; i < numTransiciones; i++){
		cin >> q >> a >> p >> b >> d;
		MT->agregar(q, a, {p, b, d});
	}

	string cadena;

	do{
		cout << "Introduce una cadena, " << blank << " para salir: ";
		cin >> cadena;
		if(cadena[0] == blank) break;
		if(MT->leerEntrada(cadena)){
			cout << "Cadena valida. Contenido de la cinta: " << cadena << "\n\n";
		}else{
			cout << "Cadena no valida.\n\n";
		}
	}while(cadena[0] != blank);

	return 0;
}
