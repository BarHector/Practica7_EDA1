#include<stdio.h>
#include<stdlib.h>

typedef struct _Nodo{
	char dato;
	struct _Nodo *siguiente;
}Nodo;

Nodo *primer = NULL;
Nodo *ultimo = NULL;

void agregar(Nodo *nodo){
	nodo -> siguiente = NULL;

	if(primer == NULL){
		primer = nodo;
		ultimo = nodo;
	}
	else{
        ultimo -> siguiente = nodo;
		ultimo = nodo;
	}
}

int main(){
	char a1, a2, a3;

	printf("Digite 3 caracteres: ");
	scanf("%c %c %c",&a1,&a2,&a3);

	Nodo *primer = (Nodo *)malloc(sizeof(Nodo));
	primer -> dato = a1;

	Nodo *segundo = (Nodo *)malloc(sizeof(Nodo));
	segundo -> dato = a2;

	Nodo *tercero = (Nodo *)malloc(sizeof(Nodo));
	tercero -> dato = a3;

	agregar(primer);
	agregar(segundo);
	agregar(tercero);

	//Recorriendo Nodos
	Nodo *i = primer;

	while(i != NULL){
		printf("| %c ",i->dato);
		i = i->siguiente;
	}

	return 0;
}