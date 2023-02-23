/*
 * Estudiante.h
 *
 *  Created on: 14 feb. 2023
 *      Author: UGIO
 */

#ifndef ESTUDIANTE_H_
#define ESTUDIANTE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{

	int legajo;
	char nombre[15];
	char carrera[15];
	int cantDeMateriasAprobadas;
	float porcentajeAprobadas;

} eEstudiante;

eEstudiante* estudiante_new();
eEstudiante* estudiante_newParametros();

void estudiante_delete();

int estudiante_SetLegajo(int legajo, eEstudiante* this);
int estudiante_GetLegajo(int* legajo, eEstudiante* this);

int estudiante_SetNombre(char* nombre, eEstudiante* this);
int estudiante_GetNombre(char* nombre, eEstudiante* this);

int estudiante_SetCarrera(char* carrera, eEstudiante* this);
int estudiante_GetCarrera(char* carrera, eEstudiante* this);

int estudiante_SetCantDeMateriasAprobadas(int cantMateriasAprobadas, eEstudiante* this);
int estudiante_GetCantDeMateriasAprobadas(int* cantMateriasAprobadas, eEstudiante* this);

int estudiante_SetporcentajeAprobadas(float porcentajeAprobadas, eEstudiante* this);
int estudiante_GetporcentajeAprobadas(float* porcentajeAprobadas, eEstudiante* this);

#endif /* ESTUDIANTE_H_ */
