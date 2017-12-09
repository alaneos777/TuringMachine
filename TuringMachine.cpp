#include "Terna.cpp"
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

struct TuringMachine {		//Definición de los elementos que conforman la Máquina de Turing.
	int numeroEstados;			//Número de estados (para crear el conjunto de estados).
	vector<char> alfabetoCinta;		//Alfabeto de cinta en forma de cadena de caracteres.
	int inicial;				//Número de estado inicial
	char blank;				//Símbolo "blanco"
	vector<int> finales;			//Estados finales
	vector<map<char, Terna>> delta;		//Conjunto de transiciones que definen a delta
	
	TuringMachine(int numeroEstados, vector<char> alfabetoCinta, char blank, int inicial, vector<int> finales){	//Constructor de una MT
		this->numeroEstados = numeroEstados;	// Se asigna cada valor a su respectivo campo,
		this->alfabetoCinta = alfabetoCinta;	// además se dimensiona a delta con el número de estados a contener
		this->blank = blank;			// y se ordenan los estados finales para tener un mejor control sobre ellos.
		this->inicial = inicial;
		this->finales = finales;
		delta.resize(numeroEstados);
		sort(finales.begin(), finales.end());
	}
	
	void agregar(int estado, char c, Terna t){	//Agrega una transición nueva para un caracter de cinta y un estado actual
		delta[estado][c] = t; 
    	}

    void imprimirCinta(list<char> cinta, int estado, int posicion){	//Muestra en pantalla el estado actual de la MT
    	cout << "Estado actual: " << estado << "\n";			//y el contenido en curso de la cinta,
    	cout << "Contenido de la cinta:\n";
    	for(char c : cinta){
    		cout << c;
    	}
    	cout << "\n";
    	for(int i = 0; i < cinta.size(); i++){				//indicando con un caracer "|" debajo de la cinta
    		if(i == posicion){					//la posición actual
    			cout << "|";
    		}else{
    			cout << "-";
    		}
    	}
    	cout << "\n";
    }
	
	bool leerEntrada (string & entrada){		//La función se encarga de simular el comportamiento de una MT, esto es,
		list<char> cinta (entrada.begin(), entrada.end());
		int estadoActual = inicial;
		auto simboloActual = cinta.begin();
		int posicion = 0;
		imprimirCinta(cinta, estadoActual, posicion);	//mostrar e cabezal de la cinta en cada transición
		while (delta[estadoActual].count(*simboloActual) > 0 && !binary_search(finales.begin(), finales.end(), estadoActual)){	//verificar la transición correspondiente al estado y símbolo actuales
			Terna t = delta[estadoActual][*simboloActual];
			*simboloActual = t.simbolo;
			switch (t.direccion){
				case -1:{	// para que la cinta se mueva a la izquierda
						if (simboloActual == cinta.begin()){
							cinta.push_front(blank);	//procurando mantener la idea de una cinta infinita 
							simboloActual = cinta.begin();	//insertando "blancos" al inicio
							posicion = 0;
						}else{
							simboloActual--;
							posicion--;
						}
						break;
					}
				case 1:{	// o a la derecha
						simboloActual++;
						posicion++;
						if(simboloActual == cinta.end()){
							cinta.push_back(blank);		//o al final de esta, según se requiera.
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
		return binary_search(finales.begin(), finales.end(), estadoActual);	//Finalmente verifica si el estado actual está contenido dentro de los estados finales.
	}										//deteniendo la máquina
	
};


