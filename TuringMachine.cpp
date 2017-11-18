#include "Terna.cpp"

struct TuringMachine {
	int numeroEstados;
	vector<char> alfabetoEntrada;
	vector<char> alfabetoCinta;
	int inicial;
	const char blank = '~';
	vector<int> finales;
	vector<map<char, Terna>> delta;
};
