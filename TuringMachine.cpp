#include "Terna.cpp"

struct TuringMachine {
	int numeroEstados;
	vector<char> alfabetoEntrada;
	vector<char> alfabetoCinta;
	int inicial;
	const char blank = 'B';
	vector<int> finales;
	vector<map<char, Terna>> delta;
	TuringMachine(int numeroEstados, vector<char> alfabetoEntrada, vector<char> alfabetoCinta,int inicial, vector<int> finales){
		this->numeroEstados= numeroEstados;
		this->alfabetoEntrada= alfabetoEntrada;
		this->alfabetoCinta= alfabetoCinta;
		this->inicial= inicial;
		this->finales= finales;
		delta.resize(numeroEstados);
		sort(alfabetoEntrada.begin(),alfabetoEntrada.end());
		sort(alfabetoCinta.begin(),alfabetoCinta.end());
		sort(finales.begin(),finales.end());
	}
	void agregar(int estado, char c, Terna t){
		delta[estado][c] = t; 
        }
	
};


