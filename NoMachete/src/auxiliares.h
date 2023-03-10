/*
 * auxiliares.h
 *
 *  Created on: 14 feb. 2023
 *      Author: UGIO
 */

#ifndef AUXILIARES_H_
#define AUXILIARES_H_

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Estudiante.h"

int auxiliares_mostrarEstudiantes(LinkedList* listaMain);

int auxiliares_mostrarUnEstudiante(eEstudiante* estudiante);

int auxiliares_ordenarPorNombre(void* pElement1, void* pElement2);

int auxiliares_GuardarCsv(char* path , LinkedList* listaMain);

int auxiliares_PorcentajeMateriasAprobadas(void* pElement);

LinkedList* auxiliares_filtrarCarrera(LinkedList* listaMain);

int auxiliares_filtrarTUP(void* pElement);

int auxiliares_filtrarTUSI(void* pElement);

#endif /* AUXILIARES_H_ */
