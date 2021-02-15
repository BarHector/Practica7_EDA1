#include <stdio.h>
#include <stdlib.h>

typedef struct _Nodo{
	char name[15];
	int number;
	struct _Nodo *siguiente;
}Nodo;

Nodo *primer = NULL;
Nodo *ultimo = NULL;

void agregar(Nodo *nodo){
	nodo -> siguiente = NULL;

	if(primer == NULL){
		primer = nodo;
		ultimo = nodo;
	}else{
        ultimo -> siguiente = nodo;
		ultimo = nodo;
	}
}

void buscar(Nodo *nodo){
	int a=0;
	Nodo *aux;
	aux = primer;
	while(a==0){
		if(primer!=NULL){
			if(*aux->name == *nodo->name){
				printf("Su numero es: %i\n", aux->number);
				a=1;
				aux=NULL;
				free(aux);
				nodo=NULL;
				free(nodo);
			}else{
				aux=aux->siguiente;
				
				if(aux == NULL){
					printf("El nombre que buscas no ha sido ingresado\n");
					a=1;
				}
			}
    	}else{
			printf(" ------- Lista vacia -------");
	        free(nodo);
			a=1;
		}
	}
}

void imprimir(){
    if(primer==NULL){
        printf("------- Lista vacia -------\n");
    }else{
		Nodo *nod;
    	nod = primer;
	
		printf("------- Nombres ingresados -------\n\tNombre \tNumero\n");
		while(nod!=NULL){
	        printf("\t%s\t%i\n", nod->name, nod->number);
        	nod = nod->siguiente;
    	}
	}
}

void Eliminar(){
    if(primer!=NULL){
    	Nodo *borrar;
    	borrar = primer;
    	while(borrar->siguiente!=NULL){
        	borrar = borrar->siguiente;
        	free(borrar);
    	}
	}
}

int main(){
  	char name[20];
	int nao=1;
	int opcion=0;
	
	do{
		printf("%cQue deseas hacer?\n1. Agregar datos\n2. Buscar datos\n3. Imprimir todo\n4. Salir\nOpcion: ", 168);
		scanf("%i", &opcion);
		printf("\n");
		switch (opcion){
			case 1:	printf("Agrega el nombre:  ");
					Nodo *snodo = (Nodo*)malloc(sizeof(Nodo));
					scanf("%s", snodo->name);
					printf("Agrega su numero:  ");
					scanf("%d", &snodo->number);
					agregar(snodo);
					break;
			case 2: printf("Ingresa el nombre que quieres buscar, devolveremos su numero\nNombre:  ");
					Nodo *Buscar = (Nodo*) malloc(sizeof(Nodo));
					scanf("%s", Buscar->name);
					buscar(Buscar);	
					break;
			case 3: imprimir();
					break;
			case 4:	nao=2;
					break;
			default: printf("OPCION INVALIDA, INRGESA UNA QUE NO LO SEA\n");
					break;
		}
		printf("\n");
	}while(nao==1);
	
	return 0;
}