/*
 * Estudiante.c
 *
 *  Created on: 14 feb. 2023
 *      Author: UGIO
 */
#include "Estudiante.h"

eEstudiante* estudiante_new()
{
	eEstudiante* this = NULL;

	this = (eEstudiante*)malloc(sizeof(eEstudiante));

	return this;
}
eEstudiante* estudiante_newParametros(char* legajo, char* nombre, char* carrera, char* cantDeMateriasAprobadas, char* porcentajeAprobadas)
{
	eEstudiante* this = NULL;

	this = estudiante_new();

	if(this != NULL)
	{
		if(!(estudiante_SetLegajo(atoi(legajo), this) == 0
			&& estudiante_SetNombre(nombre, this) == 0
			&& estudiante_SetCarrera(carrera, this) == 0
			&& estudiante_SetCantDeMateriasAprobadas(atoi(cantDeMateriasAprobadas), this) == 0
			&& estudiante_SetporcentajeAprobadas(atof(porcentajeAprobadas), this) == 0))
		{
			estudiante_delete(this);
		}
	}
	return this;
}

void estudiante_delete(eEstudiante* this)
{
	if(this != NULL)
	{
		this = NULL;
	}
	free(this);
}

int estudiante_SetLegajo(int legajo, eEstudiante* this)
{
	int retorno = -1;

	if(legajo > 0 && this != NULL)//depende del criterio
	{
		this->legajo = legajo;

		retorno = 0;
	}
	return retorno;
}
int estudiante_GetLegajo(int* legajo, eEstudiante* this)
{
	int retorno = -1;

	if(legajo != NULL && this != NULL)
	{
		*legajo = this->legajo;
		retorno = 0;
	}

	return retorno;
}

int estudiante_SetNombre(char* nombre, eEstudiante* this)
{
	int retorno = -1;

	if(nombre != NULL && this != NULL)
	{
		strcpy(this->nombre, nombre);
		retorno = 0;
	}
	return retorno;
}
int estudiante_GetNombre(char* nombre, eEstudiante* this)
{
	int retorno = -1;

	if(nombre != NULL && this != NULL)
	{
		strcpy(nombre, this->nombre);
		retorno = 0;
	}
	return retorno;
}

int estudiante_SetCarrera(char* carrera, eEstudiante* this)
{
	int retorno = -1;

	if(carrera != NULL && this != NULL)
	{
		strcpy(this->carrera, carrera);
		retorno = 0;
	}
	return retorno;
}
int estudiante_GetCarrera(char* carrera, eEstudiante* this)
{
	int retorno = -1;

	if(carrera != NULL && this != NULL)
	{
		strcpy(carrera, this->carrera);
		retorno = 0;
	}
	return retorno;
}

int estudiante_SetCantDeMateriasAprobadas(int cantMateriasAprobadas, eEstudiante* this)
{
	int retorno = -1;

	if(cantMateriasAprobadas > 0 && this != NULL)//depende del criterio
	{
		this->cantDeMateriasAprobadas = cantMateriasAprobadas;

		retorno = 0;
	}
	return retorno;
}
int estudiante_GetCantDeMateriasAprobadas(int* cantMateriasAprobadas, eEstudiante* this)
{
	int retorno = -1;

	if(cantMateriasAprobadas != NULL && this != NULL)
	{
		*cantMateriasAprobadas = this->cantDeMateriasAprobadas;
		retorno = 0;
	}

	return retorno;
}

int estudiante_SetporcentajeAprobadas(float porcentajeAprobadas, eEstudiante* this)
{
	int retorno = -1;

	if(porcentajeAprobadas > 0 && this != NULL)//depende del criterio
	{
		this->porcentajeAprobadas = porcentajeAprobadas;
		retorno = 0;
	}

	return retorno;
}
int estudiante_GetporcentajeAprobadas(float* porcentajeAprobadas, eEstudiante* this)
{
	int retorno = -1;

	if(porcentajeAprobadas != NULL && this != NULL)
	{
		*porcentajeAprobadas = this->porcentajeAprobadas;
		retorno = 0;
	}

	return retorno;
}
