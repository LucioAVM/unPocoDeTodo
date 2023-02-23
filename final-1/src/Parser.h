/*
 * Parser.h
 *
 *  Created on: 14 feb. 2023
 *      Author: Monsalbo Lucio
 */

#ifndef PARSER_H_
#define PARSER_H_

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Estudiante.h"

int parser_CargarCSV(LinkedList* listaPrincipal, FILE* pArchivo);

#endif /* PARSER_H_ */
