#include "Terna.cpp"
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

struct TuringMachine {
	int numeroEstados;
	vector<char> alfabetoCinta;
	int inicial;
	char blank;
	vector<int> finales;
	vector<map<char, Terna>> delta;
	
	TuringMachine(int numeroEstados, vector<char> alfabetoCinta, char blank, int inicial, vector<int> finales){
		this->numeroEstados = numeroEstados;
		this->alfabetoCinta = alfabetoCinta;
		this->blank = blank;
		this->inicial = inicial;
		this->finales = finales;
		delta.resize(numeroEstados);
		sort(finales.begin(), finales.end());
	}
	
	void agregar(int estado, char c, Terna t){
		delta[estado][c] = t; 
    }

    void imprimirCinta(list<char> cinta, int estado, int posicion){
    	cout << "Estado actual: " << estado << "\n";
    	cout << "Contenido de la cinta:\n";
    	for(char c : cinta){
    		cout << c;
    	}
    	cout << "\n";
    	for(int i = 0; i < cinta.size(); i++){
    		if(i == posicion){
    			cout << "|";
    		}else{
    			cout << "-";
    		}
    	}
    	cout << "\n";
    }
	
	bool leerEntrada (string & entrada){
		list<char> cinta (entrada.begin(), entrada.end());
		int estadoActual = inicial;
		auto simboloActual = cinta.begin();	/* auto -> list::iterator<char> */
		int posicion = 0;
		imprimirCinta(cinta, estadoActual, posicion);
		while (delta[estadoActual].count(*simboloActual) > 0 && !binary_search(finales.begin(), finales.end(), estadoActual)){
			Terna t = delta[estadoActual][*simboloActual];
			*simboloActual = t.simbolo;
			switch (t.direccion){
				case -1:{
						if (simboloActual == cinta.begin()){
							cinta.push_front(blank);
							simboloActual = cinta.begin();
							posicion = 0;
						}else{
							simboloActual--;
							posicion--;
						}
						break;
					}
				case 1:{
						simboloActual++;
						posicion++;
						if(simboloActual == cinta.end()){
							cinta.push_back(blank);
							simboloActual = cinta.end();
							simboloActual--;
						}
						break;
					}
			}
			estadoActual = t.estado;
			imprimirCinta(cinta, estadoActual, posicion);
		}
		while(cinta.back() == blank){
			cinta.pop_back();
		}
		while(cinta.front() == blank){
			cinta.pop_front();
		}
		entrada = string(cinta.begin(), cinta.end());
		return binary_search(finales.begin(), finales.end(), estadoActual);
	}
	
};


