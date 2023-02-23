/*
 ============================================================================
 Name        : final-1.c
 Author      : Monsalbo Lucio
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "LinkedList.h"
#include "Monsalbo.h"

int main(void)
{
	setbuf(stdout, NULL);

	int menu;
	int validacion;

	LinkedList* listaMain = ll_newLinkedList();
	LinkedList* listaPorcentaje = NULL;
	LinkedList* listaFiltrada = NULL;

	do
	{
		menu = Controller_menu();
		switch(menu)
		{
		case 1:
			validacion = controller_CargaDeDatosCSV(listaMain, "estudiantes.csv");
			mostrarMensaje("se cargo correctamente el archivo", "no se pudo cargar", validacion);
			break;

		case 2:
			validacion = controller_listar(listaMain);
			mostrarMensaje("", "no se pudo listar", validacion);
			break;

		case 3:
			validacion = controller_ordenarPorNombre(listaMain);
			mostrarMensaje("Ordenado Correctamente", "Error al ordenar", validacion);
			break;
		case 4:
			validacion = controller_GuardarCsv(listaMain,"Ordenado.csv");
			mostrarMensaje(".csv creado correctamente", "Error al crear .csv", validacion);
			break;
		case 5:
			listaPorcentaje = porcentajeDeCarrera(listaMain);
			if(listaPorcentaje != NULL)
			{
				validacion = 0;
			}
			mostrarMensaje("porcentaje calculados correctamente", "Error al calcular porcentajes", validacion);
			break;
		case 6:
			validacion = controller_GuardarCsv(listaPorcentaje,"Mapeado.csv");
			mostrarMensaje(".csv creado correctamente", "Error al crear .csv", validacion);
			break;
		case 7:
			listaFiltrada = controller_filter(listaMain);
			auxiliares_mostrarEstudiantes(listaFiltrada);
			if(listaFiltrada != NULL)
			{
				validacion = 0;
			}
			mostrarMensaje("lista filtrada correctamente", "Error al filtrar la lista", validacion);
			break;
		case 8:
			validacion = controller_GuardarCsv(listaFiltrada,"Filtrado.csv");
			mostrarMensaje(".csv creado correctamente", "Error al crear .csv", validacion);
			break;
		}
	}while(menu != 0);

	return EXIT_SUCCESS;
}













