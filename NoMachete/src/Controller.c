/*
 * Controller.c
 *
 *  Created on: 14 feb. 2023
 *      Author: Monsalbo Lucio
 */

#include "Controller.h"


/***********************************************************************************
									MENU

		EL USUARIO INGRESA LA OPCION QUE QUIERA Y LO DEVUELVE AL MAIN

***********************************************************************************/
int Controller_menu (void)
{
	int opcion;
	int bandera = 0;

	do
	{
		printf("\nMENU\n"
				"1) Cargar archivo\n"
				"2) Listar\n"
				"3) Ordenar por Nombre\n"
				"4) Guardar ´Ordenado.csv´\n"
				"5) ll_map para porcentaje de carrera\n"
				"6) guardar ´mapeado.csv´\n"
				"7) filtrar por carrera\n"
				"8) guardar ll filtrada\n"
				"11- SALIR\n\t-->");

		if(bandera == 1)
		{
			printf("\nERROR, opcion incorrecta\n");
		}
		fflush(stdout);
		scanf("%d", &opcion);
		bandera = 1;
	}while(!(opcion > 0 && opcion < 12));

	return opcion;
}

/***********************************************************************************
							CARGAR DESDE TEXTO .CSV

					PASA LOS DATOS DEL .CSV A LA LINKEDLIST

***********************************************************************************/


int controller_CargaDeDatosCSV(LinkedList* this, char* path)
{
	FILE* pArchivo = NULL;
	int retorno = -1;

	if(ll_isEmpty(this) == 1 && path != NULL)
	{
		pArchivo = fopen(path, "r");

		if(pArchivo != NULL)
		{
			if(parser_CargarCSV(this, pArchivo) == 0)
			{
				retorno = 0;
			}else{
				printf("error al cargar la lista");
			}
		}
		fclose(pArchivo);
	}
	return retorno;
}

/***********************************************************************************
									LISTAR

				MUESTRA LOS DATOS CARGADOS EN LA LINKEDLIST

***********************************************************************************/

int controller_listar(LinkedList* listaMain)
{
	int retorno = -1;

	if(ll_isEmpty(listaMain) == 0)
	{
		retorno = auxiliares_mostrarEstudiantes(listaMain);
	}
	return retorno;
}

/***********************************************************************************
								ORDENA POR NOMBRE

				ORDENA LA LINKEDLIST PASADA POR PARAMETRO POR NOMBRE

***********************************************************************************/

int controller_ordenarPorNombre(LinkedList* listaMain)
{
	int retorno = -1;

	if(ll_isEmpty(listaMain) == 0)
	{
		retorno = ll_sort(listaMain, auxiliares_ordenarPorNombre, 1);
	}

	return retorno;
}

/***********************************************************************************
							GUARDAR EN ARCHIVO .CSV

GUARDA LA LINKEDLIST INGRESADA EN UN ARCHIVO .CSV CON EL NOMBRE INGRESADO POR PARAMETRO

***********************************************************************************/

int controller_GuardarCsv(LinkedList* listaMain, char* path)
{
	int retorno = -1;

	if(ll_isEmpty(listaMain) == 0)
	{
		retorno = auxiliares_GuardarCsv(path, listaMain);
	}

	return retorno;
}

/***********************************************************************************
									LL_MAP

	USA LA FUNCION MAP PARA CAMBIAR UN DATO DE LA LINKEDLIST

***********************************************************************************/

LinkedList* porcentajeDeCarrera(LinkedList* listaMain)
{
	LinkedList* nuevaLista = ll_newLinkedList();

	if(ll_isEmpty(listaMain) == 0)
	{
		nuevaLista = ll_map(listaMain, auxiliares_PorcentajeMateriasAprobadas);
	}
	return nuevaLista;
}

/***********************************************************************************
									LL_FILTER

	USA LA FUNCION FILTER PARA FILTRAR LA LISTA POR UNA DE SUS VARIABLES

***********************************************************************************/

LinkedList* controller_filter(LinkedList* listaMain)
{
	LinkedList* listaFiltrada = NULL;

	if(ll_isEmpty(listaMain) == 0)
	{
		listaFiltrada = auxiliares_filtrarCarrera(listaMain);
	}
	return listaFiltrada;
}
