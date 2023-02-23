/*
 * Parce.c
 *
 *  Created on: 14 feb. 2023
 *      Author: Monsalbo Lucio
 */
#include "Parser.h"

/***********************************************************************************
									PARSER

		PASA LOS DATOS DESDE EL ARCHIVO .CSV A VARIABLES DE UNA ESTRUCTURA

***********************************************************************************/

int parser_CargarCSV(LinkedList* listaPrincipal, FILE* pArchivo)
{
	int retorno = -1;
	char legajo[15];
	char nombre[15];
	char carrera[15];
	char cantDeMateriasAprobadas[15];
	char porcentajeAprobadas[15];

	int validacion;

	eEstudiante* estudiante;

	fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", legajo,nombre, carrera, cantDeMateriasAprobadas, porcentajeAprobadas);

	do
	{
		retorno = 0;
		validacion = fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", legajo,nombre, carrera, cantDeMateriasAprobadas, porcentajeAprobadas);

		if(validacion == 5)
		{
			estudiante = estudiante_newParametros(legajo, nombre, carrera, cantDeMateriasAprobadas, porcentajeAprobadas);

			if(estudiante != NULL)
			{
				if(ll_add(listaPrincipal, estudiante) != 0)
				{
					retorno = -1;
					break;//borrar ll
				}
			}
		}
	}while(!feof(pArchivo));

	return retorno;
}
