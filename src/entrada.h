/*
 * entrada.h
 *
 *  Created on: 10 nov. 2020
 *      Author: lp1-2019
 */

#ifndef ENTRADA_H_
#define ENTRADA_H_

// valores de distancias
#define PUNTOS 4

int distancias[PUNTOS][PUNTOS] =
 {{0,15,13,5,0,0,0,0,0},
 {0,0,0,0,0,0,0,12,0},
 {0,2,0,18,0,6,0,0,0},
 {0,0,0,0,4,0,0,0,99},
 {0,0,3,0,0,1,9,0,14},
 {0,8,0,0,0,0,0,17,0},
 {0,0,0,0,0,16,0,7,10},
 {0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,11,0}};

/*
int distancias[PUNTOS][PUNTOS] =
 {{0,2,1,20},
 {0,0,0,4},
 {0,3,0,8},
 {0,0,0,0,}};
*/

char x = 'A'; // punto origen
char y = 'I'; // punto destino

#endif /* ENTRADA_H_ */
