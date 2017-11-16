#include "Terna.cpp"

struct TuringMachine {
	vector<int> estados;
	vector<char> alfabetoEntrada;
	vector<char> alfabetoCinta;
	int inicial;
	const char blank = '~';
	vector<int> finales;
	vector<map<char, Terna>> delta;
};
