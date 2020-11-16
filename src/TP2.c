/*
 ============================================================================
 Name        : TP2.c
 Author      : Alain Vega y Mathias Martinez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "entrada.h"
#include "declaracionesTP2.h"

char PILA[PUNTOS]; // pila que contiene los nodos de un camino actual
int ULTIMO = 0; // indice que indica cual es el ultimo elemento de la pila

int main(void) {
	ImprimirMatriz(distancias);
}

void ImprimirMatriz(int distancias[PUNTOS][PUNTOS]) {
	int i, j;
	for (i = 0; i < PUNTOS; i++){
		for (j = 0; j < PUNTOS; j++){
			printf("| %d ", distancias[i][j]);
		}
		printf("| \n");
	}
}

void CalcularCaminos(char origen, char destino) {
	// origen: fila de la que partis
	// destino: columna de destino
	int i;
	int next = destino - 'A';
	int previous = 0;
	int distancia = 0;
	/*while (1) {
		for (i = 0; i < PUNTOS; i++) {
			if (distancias[next][i] != 0) {
				if (distancias[next][i] != 0 && i + 'A' == destino) {
					puts("Camino encontrado");
					printf("Distancia: %d.\n", distancia);
				}
				//Push() de Alain
				distancia += distancias[next][i];
				next = i;
			}
		}
	}*/
	int band_vuelta = 0;
	for (i = band_vuelta == 1 ? next : 0; i < PUNTOS; i++) {
		if (distancias[next][i] != 0) {
			if (i + 'A' == destino) {
				puts("Camino encontrado.");
				printf("Distancia: %d.\n", distancia);
				puts("Recorrido:");
				//PrintearRecorrido(PILA);
			}
			//Push(i) de Alain
			distancia += distancias[next][i];
			previous = i;
			next = i;
		}
		else {
			next = previous;
			band_vuelta = 1;
		}
	}
}

/*
 * Funcion PushPila: para agregar un elemento a la pila.
 * Recibe el vector pila y el elemento para introducir en la pila.
 * No retorna nada.
 */
void PushPila(char PILA[PUNTOS], char elemento) {
	if (ULTIMO >= PUNTOS - 1) { //preguntamos si la pila esta llena
		printf("ERROR Pila llena, checkear la dimension del array pila\n");
	} else {
		//no esta llena, podemos agregar un elemento
		PILA[ULTIMO + 1] = elemento;
		ULTIMO++;
	}
}

/*
 * Funcion PopPila: para sacar 1 elemento de la pila.
 * Recibe el vector pila.
 * Retorna el elemento que se saco de la pila.
 */
char PopPila(char PILA[PUNTOS]) {
	if (ULTIMO <= 0) {
		printf("ERROR Pila vacia, no es posible hacer un pop de una pila vacia.\n");
		return '?'; //retornamos ? a modo de saber que la pila esta vacia
	} else {
		// no esta vacia
		return PILA[ULTIMO--]; //retornamos el elemento al que hicimos pop
	}
}

/*
 * Funcion BuscarNodo: para buscar si hay un nodo anotado en la pila.
 * Recibe la pila y el indice el cual representa un nodo.
 * Retorna 1 si el nodo esta en la pila y 0 si no esta.
 */
int BuscarNodo(char PILA[PUNTOS], int indice){
	int i, booleano;
	for (i = 0; i < ULTIMO; i++){
		if (PILA[i] == PILA[indice]) {
			booleano = 1; //ese valor si esta en la pila
		}else {
			booleano = 0;
		}
	}
	return booleano;
}

/*
 *Funcion ImprimirCamino: para imprimir el camino actual (el que esta en la pila)
 *Recibe la pila y la suma total de distancias de origen a destino
 *No retorna nada.
 */
void ImprimirCamino(char PILA[PUNTOS], int suma){
	int i;
	for (i = 0; i < ULTIMO; i++) {
		if (i == ULTIMO) {
			printf("%c = %d\n", PILA[i], suma);
		}else {
			printf("%c -->",PILA[i]);
		}
	}
}
