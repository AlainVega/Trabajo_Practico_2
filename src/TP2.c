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
	int distancia = 0;
	int band_vuelta = 0;
	int next_fila, next_columna;
	while (1) {
		for (i = band_vuelta == 1 ? next_columna : 0; i < PUNTOS; i++) {
			// TODO: QUE HACER SI DISTANCIAS[][] ES < 0?
			if (distancias[next_fila][i] > 0) {
				if (BuscarNodo(PILA, i + 'A') == 0) {
					// Se intenta volver a un espacio ya recorrido, ignorar
					continue;
				}
				PushPila(PILA, i + 'A');
				distancia += distancias[next_fila][i];
				if (i + 'A' == destino) {
					// Se llego al destino, printear el camino y volver
					puts("Camino encontrado.");
					printf("Distancia: %d.\n", distancia);
					puts("Recorrido:");
					//PrintearRecorrido(PILA);
					band_vuelta = 1;
					next_fila = PILA[ULTIMO - 1];
					// TODO: Que hacer con esta linea si estamos en la ultima columna?
					next_columna = PILA[ULTIMO - 2] + 1;
					PopPila(PILA);
				}
				else {
					// Se encontro un nodo al que se puede seguir, seguirlo
					next_fila = i;
					next_columna = 0;
					band_vuelta = 0;
				}
			}
			else {
				if (i == PUNTOS - 1) {
					// Llegamos a la ultima columna de una fila y no se entro a ningun camino, volver
					band_vuelta = 1;
					next_fila = PILA[ULTIMO - 1];
					next_columna = PILA[ULTIMO - 2] + 1;
					PopPila();
				}
			}
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
