/*
 * Controller.h
 *
 *  Created on: 14 feb. 2023
 *      Author: Monsalbo Lucio
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <stdio.h>
#include <stdlib.h>
#include "auxiliares.h"
#include "LinkedList.h"
#include "Parser.h"

/**
 * muestra menu y devuelve opcion
 */
int Controller_menu(void);

int controller_CargaDeDatosCSV(LinkedList* this, char* path);

int controller_listar(LinkedList* listaMain);

int controller_ordenarPorNombre(LinkedList* listaMain);

int controller_GuardarCsv(LinkedList* listaMain);

#endif /* CONTROLLER_H_ */
