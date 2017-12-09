struct Terna{		//Definición de terna para transiciones de función delta
	int estado;		//Estado a transitar
	char simbolo;		//Símbolo a reemplazar en la cinta de la MT
	int direccion;		//Dirección a mover la cinta (1: derecha, 0: estática, -1: izquierda)
};
