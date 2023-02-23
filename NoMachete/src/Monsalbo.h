/*
 * Monsalbo.h
 *
 *  Created on: 14 feb. 2023
 *      Author: Monsalbo Lucio
 */

#ifndef MONSALBO_H_
#define MONSALBO_H_

int getFloat(float* resultado, char* mensaje, int minimo, int maximo);

int getInt(char* mensaje, int minimo, int maximo, int* numero);

int getChar(char resultado[], char *mensaje);

void getStringLetras(char mensaje[], char input[]);

void getString(char mensaje[],char input[]);

int soloLetras(char str[]);

int getNumeros(char mensaje[], int* numero);

int getDataNum(char mensaje[]);

int validacionS_N(char *texto);

int validacionS_NParametrizadoInt(char *texto, int parametro);

void mostrarMensaje(char* mensajeOk, char* mensajeError, int funcion);


#endif /* MONSALBO_H_ */
