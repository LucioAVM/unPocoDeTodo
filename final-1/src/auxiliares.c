/*
 * auxiliares.c
 *
 *  Created on: 14 feb. 2023
 *      Author: UGIO
 */
#include "auxiliares.h"


int auxiliares_mostrarEstudiantes(LinkedList* listaMain)
{
	int retorno = 0;
	int tam;

	eEstudiante* estudiante = NULL;

	tam = ll_len(listaMain);

	for(int i = 0; i < tam ; i++)
	{
		estudiante = ll_get(listaMain, i);

		if(estudiante != NULL)
		{
			retorno = auxiliares_mostrarUnEstudiante(estudiante);
		}else{
			retorno = -1;
			break;
		}
	}
	return retorno;
}

int auxiliares_mostrarUnEstudiante(eEstudiante* estudiante)
{
	int retorno = -1;

	int legajo;
	char nombre[15];
	char carrera[15];
	int cantDeMateriasAprobadas;
	float porcentajeAprobadas;

	/*

		if(estudiante_GetLegajo(&legajo, estudiante) == 0)
		{
			printf("\nlagajo ok --> %d\n",legajo);
		}

		if(estudiante_GetNombre(nombre, estudiante) == 0)
		{
			printf("\nnombre ok --> %s\n",nombre);
		}

		if(estudiante_GetCarrera(carrera, estudiante) == 0)
		{
			printf("\ncarrera ok\n --> %s", carrera);
		}

		if(estudiante_GetCantDeMateriasAprobadas(&cantDeMateriasAprobadas, estudiante) == 0)
		{
			printf("\ncantDeMateriasAprobadas ok --> %d\n", cantDeMateriasAprobadas);
		}

		if(estudiante_GetporcentajeAprobadas(&porcentajeAprobadas, estudiante) == 0)
		{
			printf("\ncantDeMateriasAprobadas ok --> %f\n",porcentajeAprobadas);
		}
*/
	//*

	if(estudiante_GetLegajo(&legajo, estudiante) == 0
				&& estudiante_GetNombre(nombre, estudiante) == 0
				&& estudiante_GetCarrera(carrera, estudiante) == 0
				&& estudiante_GetCantDeMateriasAprobadas(&cantDeMateriasAprobadas, estudiante) == 0
				&& estudiante_GetporcentajeAprobadas(&porcentajeAprobadas, estudiante) == 0)
	{
		printf("%-5d - %-30s - %10s - %-5d - %-5.2f\n",legajo, nombre, carrera, cantDeMateriasAprobadas, porcentajeAprobadas);
		retorno = 0;
	}
//*/
	return retorno;
}
//		ORDENAR

int auxiliares_ordenarPorNombre(void* pElement1, void* pElement2)
{
	int retorno = -1;

	char primero[25];
	char segundo[25];

	retorno = 0;//no hace nada en ll_sort

	if(!(estudiante_GetNombre(primero, pElement1)) && !(estudiante_GetNombre(segundo, pElement2)))
	{
		retorno = strcmp(primero,segundo);
	}
	return retorno;
}

int auxiliares_GuardarCsv(char* path , LinkedList* listaMain)
{
	int retorno;

	FILE* pArchivoTexto;
	eEstudiante* estudiante;
	int tam;
	int i;

	retorno = -1;
	tam = ll_len(listaMain);

	if(path != NULL && listaMain !=NULL)
	{
		pArchivoTexto = fopen(path,"wt");

		if(pArchivoTexto !=NULL)
		{
			for(i=0;i<tam;i++)
			{
				estudiante = (eEstudiante*)ll_get(listaMain,i);
				fprintf(pArchivoTexto, "%-5d - %-30s - %10s - %-5d - %-5.2f\n",
						estudiante->legajo,
						estudiante->nombre,
						estudiante->carrera,
						estudiante->cantDeMateriasAprobadas,
						estudiante->porcentajeAprobadas);
	//			fwrite(estudiante,sizeof(eEstudiante),1,pArchivoTexto);
			}
		}
		fclose(pArchivoTexto);
		retorno = 0;
	}
	return retorno;
}


int auxiliares_PorcentajeMateriasAprobadas(void* pElement)
{
	int retorno = -1;

	int materias = 0;

	char carrera[15];

	float porcentajeAprobadas;

	if(estudiante_GetCantDeMateriasAprobadas(&materias, pElement) == 0 && estudiante_GetCarrera(carrera, pElement) == 0)
	{
		if(strcmp(carrera, "TUP") == 0)
		{
			porcentajeAprobadas = materias*100/20;
		}else if(strcmp(carrera, "TUSI") == 0)
		{
			porcentajeAprobadas = materias*100/14;
		}
		estudiante_SetporcentajeAprobadas(porcentajeAprobadas, pElement);
		retorno = 0;
	}
	return retorno;
}

int auxiliares_filter(LinkedList* listaMain)
{
	int retorno = -1;

	int opcion;

	printf("CARRERAS:\n"
			"1) TUP\n"
			"2) TUSI\n");
	fflush();
	scanf("%d",&opcion);

	return retorno;
}
