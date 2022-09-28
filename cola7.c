#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 30

//Definicion de Tipos
typedef char tString[50];
typedef struct{
	tString embarcacion[MAX];
	int frente;
	int final;
}rCola;

//Variables Globales
rCola barcos;
int contador = 0;

//Prototipo de Funciones
void inicializarCola();
bool colaVacia(rCola);
bool colaLlena(rCola);
void menu();
void opcionesMenu(int);
void ingresarBarco();
void listadoEmbarcaciones();
bool disponibilidad();
void consultarDisponibilidad();
void eliminarBarco();

//Funcion Principal
int main(){
	inicializarCola();
	menu();
	return 0;
}

//Implementacion
void inicializarCola(){
	barcos.frente = -1;
	barcos.final = -1;
	printf("Cola inicializada!\n\n");
}

bool colaVacia(rCola pCola){
	return(barcos.final == -1);
}

bool colaLlena(rCola pCola){
	return(barcos.final == MAX - 1);
}

void menu() {
	int respuesta = 0;
	printf("Elegir una opcion:\n");
	printf("1-Ingresar embarcacion\n2-Visualizar embarcaciones registradas\n3-Consultar disponibilidad\n4-Eliminar embarcacion\n5-Salir: ");
	scanf("%d",&respuesta);
	opcionesMenu(respuesta);
}

void opcionesMenu(int pOpciones){
	switch(pOpciones){
		case 1:
			ingresarBarco();
			menu();
		break;
		case 2:
			listadoEmbarcaciones();
			menu();
		break;
		case 3:
			consultarDisponibilidad();
			menu();
		break;
		case 4:
			eliminarBarco();
			menu();
		break;
		case 5:
		break;
		default:
			printf("Opcion Incorrecta!\n");
			menu();
		break;
	}
}

void ingresarBarco(){
	if(colaLlena(barcos)){
		printf("La cola esta llena!\n");
	}else{
		barcos.final++;
		contador++;
		printf("Ingrese el nombre de la embarcacion: ");
		fflush(stdin);
		gets(barcos.embarcacion[barcos.final]);
		fflush(stdin);
		if(barcos.final == 0){
			barcos.frente = 0;
		}
		printf("\tEmbarcacion ingresada!\n");
	}
}

void listadoEmbarcaciones(){
	int i;
	if(colaVacia(barcos)){
		printf("No hay embarcaciones!\n");
	} else {
		printf("Embarcaciones registradas: \n");
		for(i=barcos.frente;i<=barcos.final;i++){
			printf("Embarcacion: %s\n",barcos.embarcacion[i]);
		}
	}
}

bool disponibilidad() {
	return(contador < MAX-1);
}

void consultarDisponibilidad(){
	if(disponibilidad()){
		printf("Hay disponiblidad!\n");
	} else {
		printf("No hay disponibilidad!\n");
	}
}

void eliminarBarco(){
	tString nombreElim = "";
	int i;
	if(colaVacia(barcos)){
		printf("No hay embarcaciones por eliminar!\n");
	} else {
		strcpy(nombreElim,barcos.embarcacion[barcos.frente]);
		for (i=barcos.frente;i<=barcos.final;i++){
			strcpy(barcos.embarcacion[i],barcos.embarcacion[i+1]);
		}
		strcpy(barcos.embarcacion[barcos.final],"");
		if(barcos.final == barcos.frente){
			inicializarCola();
		}else{
			barcos.final--;
		}
		printf("Embarcacion %s eliminada!\n",nombreElim);
		contador--;
	}
}

