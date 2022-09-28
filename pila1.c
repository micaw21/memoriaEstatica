#include <stdio.h>
#include <stdbool.h>
#define MAX 12

//Definicion de Tipos
typedef int tVector[MAX];

typedef struct{
	tVector pilaDiscos;
	int tope;
}rPilas;

//Variables Globales
rPilas pila;
int respuesta;

//Prototipo de Funciones
void inicializarPilas();
void elegirMenu();
void opcionesMenu();
bool pilaVacia(rPilas);
bool pilaLlena(rPilas);
void cargarPilas(int);
void listarPesos();
void quitarDiscos();
void discoEnTope();
void promedioDeDiscosEnPila();
int discoACargar();
void mostrarCantApilados();
int acumularDiscos();

int main() {
	inicializarPilas();
	elegirMenu();
	return 0;
}

//Implementacion
void inicializarPilas() {
	pila.tope = -1;
	printf("Pila Inicializada!\n\n");
}

void elegirMenu() {
	printf("\n\t\tElija una opcion:\n");
	printf("\t1-Cargar pila con discos\n\t2-Listar pesos de discos apilados\n\t3-Quitar discos\n\t4-Detectar disco en tope\n\t5-Mostrar cantidad de discos apilados\n\t6-Promedio del peso de discos\n\t0-Salir\n\n");
	scanf("%d" ,&respuesta);
	opcionesMenu();
}

void opcionesMenu() {
	switch(respuesta) {
		case 1:
			cargarPilas(discoACargar());
			elegirMenu();
		break;
		case 2:
			listarPesos();
			elegirMenu();
		break;
		case 3:
			quitarDiscos();
			elegirMenu();
		break;
		case 4:
			discoEnTope();
			elegirMenu();
		break;
		case 5:
			mostrarCantApilados();
			elegirMenu();
		break;
		case 6:
			promedioDeDiscosEnPila();
			elegirMenu();
		case 0:
		break;
		default:
			elegirMenu();
		break;
	}
}

bool pilaLlena(rPilas pPila) {
	return(pPila.tope == MAX - 1);
}

bool pilaVacia(rPilas pPila) {
	return(pPila.tope == -1);
}

int discoACargar() {
	int disco;
	printf("Ingrese peso del disco a cargar: ");
	scanf("%d",&disco);
	while (disco < 10 || disco > 100) {
		printf("Ingrese peso del disco a cargar: ");
		scanf("%d",&disco);
	}
	return disco;
}
void cargarPilas(int pDisco) {
	if(pilaLlena(pila)) {
		printf("No queda lugar!\n");	
	} else {
		pila.tope++;
		pila.pilaDiscos[pila.tope] = pDisco;
		printf("Disco cargado!\n");
	}
}

void listarPesos() {
	if(!pilaVacia(pila)) {
		int i;
		int max = pila.tope;
		printf("\t***LISTA DE DISCOS***\n");
		for (i=0;i<=max;i++) {
			printf("\t\t%d\n",pila.pilaDiscos[i]);
		}
		printf("\t*********************\n");
	} else {
		printf("No hay elementos para mostrar!\n");
	}

}

void quitarDiscos() {
	if(pilaVacia(pila)) {
		printf("No hay elementos para quitar!\n");
	} else {
		pila.tope --;
		printf("Elemento eliminado!\n");
	}
}

void discoEnTope() {
	if(!pilaVacia(pila)) {
		int tope = pila.pilaDiscos[pila.tope];
		printf("El disco en tope es de %d kg\n",tope);
	} else {
		printf("No hay discos en tope\n");
	}
}

void mostrarCantApilados() {
	int cantidad = pila.tope+1;
	if (pilaVacia(pila)) {
		printf("No hay discos apilados\n");
	} else {
		printf("La cantidad de discos apilados es de: %d\n",cantidad);
	}
}

int acumularDiscos() {
	int i;
	float acumulador;
	int max = pila.tope;
	for(i=0;i<=max;i++) {
		acumulador += pila.pilaDiscos[i];
	}
	return acumulador;
}

void promedioDeDiscosEnPila() {
	if (!pilaVacia(pila)) {
		float cantidad = pila.tope+1;
		float acumulador = acumularDiscos();
		float promedio = (acumulador / cantidad);
		printf("El promedio de discos en pila es: %.2f%%\n",promedio);
	} else {
		printf("No hay discos en pila!\n");
	}
}
