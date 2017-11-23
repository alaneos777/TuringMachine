#include "Terna.cpp"
#include <vector>
#include <list>
#include <map>
#include <algorithm>

using namespace std;

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
	
	bool leerEntrada (string entrada){
		list<char> cinta (entrada.begin(), entrada.end());
		int estadoActual = inicial;
		auto simboloActual = cinta.begin();	/* auto -> list::iterator<char> */
		while (delta[estadoActual].count(*simboloActual) > 0){
			Terna t = delta[estadoActual][*simboloActual];
			estadoActual = t.estado;
			*simboloActual = t.simbolo;
			switch (t.direccion){
				case -1:
					if (simboloActual == cinta.begin()){
						cinta.push_front(blank);
					}
					simboloActual--;
					break;
				case 1:
					simboloActual ++;
					if(simboloActual == cinta.end()){
						cinta.push_back(blank);
					}
					break;
			}
		}
		return binary_search(finales.begin(),finales.end(),estadoActual);
	}
	
};


