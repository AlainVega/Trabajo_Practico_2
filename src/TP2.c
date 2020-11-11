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


int main(void) {
	ImprimirMatriz(distancias);
}

int CaminosPosibles(char origen, char destino) {
	int cant_caminosposibles = 0;
	return cant_caminosposibles;
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
	for (i = band_vuelta == 0 ? 0 : next; i < PUNTOS; i++) {
		if (distancias[next][i] != 0) {
			if (i + 'A' == destino) {
				puts("Camino encontrado.");
				printf("Distancia: %d.\n", distancia);
				puts("Recorrido:");
				// TODO: Printear recorrido
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
