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

void PushPila(char PILA[PUNTOS], char elemento) {
	if (ULTIMO >= PUNTOS - 1) { //preguntamos si la pila esta llena
		printf("ERROR Pila llena, checkear la dimension del array pila\n");
	} else {
		//no esta llena, podemos agregar un elemento
		PILA[ULTIMO + 1] = elemento;
		ULTIMO++;
	}
}

char PopPila(char PILA[PUNTOS]) {
	if (ULTIMO <= 0) {
		printf("ERROR Pila vacia, no es posible hacer un pop de una pila vacia.\n");
		return '?'; //retornamos ? a modo de saber que la pila esta vacia
	} else {
		// no esta vacia
		return PILA[ULTIMO--]; //retornamos el elemento al que hicimos pop
	}
}
