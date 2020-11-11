/*
 * declaracionesTP2.h
 *
 *  Created on: 10 nov. 2020
 *      Author: lp1-2019
 */

#ifndef DECLARACIONESTP2_H_
#define DECLARACIONESTP2_H_
#include "entrada.h"


void ImprimirMatriz(int distancias[PUNTOS][PUNTOS]);

int CaminosPosibles(char origen, char destino);

void PushPila(char PILA[PUNTOS], char elemento);

char PopPila(char PILA[PUNTOS]);



#endif /* DECLARACIONESTP2_H_ */
