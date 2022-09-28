#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 20


//Definicion de Tipos
typedef char tString[50];
typedef struct{
	tString modelo;
	tString marca;
	int matricula;
}rVehiculos;

typedef struct{
	rVehiculos autos[MAX];
	int frente;
	int final;
}rCola;

//Variables Globales
rCola carril;
int contador = 0;

//Prototipo de Funciones
void inicializarCola();
bool carrilVacio(rCola);
bool carrilLleno(rCola);
void menu();
void menuOpciones(int);
void ingresarVehiculo();
void visualizarCarril();
void disponibilidadCarril();
void eliminarAutos(); //Frente Fijo
int contarVehiculos();

//Funcion Principal
int main() {
	inicializarCola();
	menu();
	return 0;
}

//Implementacion
void inicializarCola(){
	carril.frente = -1;
	carril.final = -1;
	printf("Cola inicializada!\n");
}

bool carrilVacio(rCola pCola){
	return(carril.frente == -1);
}

bool carrilLleno(rCola pCola){
	return(carril.final == MAX - 1);
}

void menu(){
	int respuesta = 0;
	printf("Elegir una opcion: \n");
	printf("1-Ingresar vehiculo\n2-Visualizar carril\n3-Disponibilidad de carril\n4-Eliminar vehiculo\n5-Salir: ");
	scanf("%d",&respuesta);
	menuOpciones(respuesta);
}

void menuOpciones(int pOpcion){
	switch(pOpcion){
		case 1:
			ingresarVehiculo();
			menu();
		break;
		case 2:
			visualizarCarril();
			menu();
		break;
		case 3:
			disponibilidadCarril();
			menu();
		break;
		case 4:
			eliminarAutos();
			menu();
		break;
		case 5:
		break;
		default:
			printf("Opcion incorrecta!\n");
			menu();
		break;
	}
}

void ingresarVehiculo(){
	int respuesta = 0;
	do{
		if(carrilLleno(carril)){
			printf("El carril esta lleno!\n");
			break;
		} else {
			carril.final++;
			contador++;
			printf("Ingrese la matricula del vehiculo: ");
			scanf("%d",&carril.autos[carril.final].matricula);
			printf("Ingrese la marca del vehiculo: ");
			fflush(stdin);
			gets(carril.autos[carril.final].marca);
			printf("Ingrese el modelo del vehiculo: ");
			fflush(stdin);
			gets(carril.autos[carril.final].modelo);
			fflush(stdin);
			if(carril.final == 0){
				carril.frente = 0;
			}
			printf("Desea ingresar otro? 1-Si 2-No: ");
			scanf("%d",&respuesta);
		}
	} while (respuesta == 1);
}


void visualizarCarril(){
	int i;
	if(carrilVacio(carril)){
		printf("No hay vehiculos para visualizar!\n");
	} else {
		printf("Vehiculos en carril: \n");
		for(i=carril.frente;i<= carril.final;i++){
			printf("Matricula: %d, Modelo: %s, Marca: %s\n",carril.autos[i].matricula,carril.autos[i].modelo, carril.autos[i].marca);
		}
	}
}

void disponibilidadCarril(){
	int cantidad = (MAX - contador);
	if(contador == MAX) {
		printf("No hay disponibilidad!\n");
	} else {
		if(carrilLleno(carril)) {
			printf("Hay disponibilidad pero el carril esta lleno!\n");
		} else {
			printf("Hay una disponibilidad de %d vehiculos!\n",cantidad);
		}
	}
}

void eliminarAutos(){
	int matriculaElim = 0;
	int i;
	if(carrilVacio(carril)){
		
		printf("El carril esta vacio!\n");
		
	} else {
		
		matriculaElim = carril.autos[carril.frente].matricula;
		
		for(i=carril.frente;i<carril.final;i++){
			carril.autos[i].matricula = carril.autos[i+1].matricula;
			strcpy(carril.autos[i].marca,carril.autos[i+1].marca);
			strcpy(carril.autos[i].modelo,carril.autos[i+1].modelo);
		}
		
		carril.autos[carril.final].matricula = 0;
		strcpy(carril.autos[carril.final].marca,"");
		strcpy(carril.autos[carril.final].modelo,"");
		
		if(carril.final == carril.frente) {
			inicializarCola();
		} else {
			carril.final--;
		}
		printf("Vehiculo eliminado: Matricula %d\n",matriculaElim);
		contador--;
	}
}
	









































