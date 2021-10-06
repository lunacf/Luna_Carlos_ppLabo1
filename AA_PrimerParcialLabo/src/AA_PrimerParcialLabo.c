/*
 ============================================================================
 Name        : AA_PrimerParcialLabo.c
 Author      : Luna Carlos Facundo
 Version     :
 Copyright   : ABM
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "carloslunavalidates.h"
#include "aviones.h"
#include "marcas.h"
#include "viajes.h"

#define CANT_AVION 5
#define CANT_MARCAS 4
#define CANT_VIAJES 5

#define TEXT_SIZE 51

int main(void) {
	setbuf(stdout,NULL);
	char opcionMain='s';
	char confirma='s';


	eAvion aviones[CANT_AVION] /*= {
			{0, 1000, 10, 100, 1000, 1999, 5},
			{1, 1001, 11, 101, 1001, 2000, 6},
			{2, 1002, 12, 102, 1002, 2009, 7},
			{3, 1003, 13, 103, 1003, 2010, 11},
			{4, 1004, 14, 100, 1004, 2020, 21}
	}*/;

	eMarca marcas[CANT_MARCAS] = {
			{1000,	"Boeing"},
			{1001,	"Airbus"	},
			{1002,	"ATR"	},
			{1003,	"Bombardier"	},

	};

	eViajes viajes[] =  {
			{100,"Salta",1462.5},
			{101, "Tucuman",1247.6},
			{102, "Neuquen", 1139.4},
			{103, "Corrientes", 670},
			{104, "Chubut",1735.8}
	};

	int idAvionFree=0;
	int flagAvion=0;
	int auxIndice;
	int auxID;
	if(inicializarArray(aviones, CANT_AVION) == 0)//Inicializo array
		{
			printf("Array inicializado correctamente. \n\n");
			hardcodeoAvion(aviones,CANT_AVION);
			flagAvion=1;
		}

		do {
			switch(menu()){
				case 1: //DAR DE ALTA
					auxIndice = buscarEspacioLibre(aviones, CANT_AVION);
					if(auxIndice >= 0)
					{
						if(altaAvion(aviones, CANT_AVION, auxIndice, &idAvionFree)== 0)
						{
						   printf("Carga exitosa.\n\n");
						    }
						       }
						    else{
						    	printf("\nNo hay mas lugar en el array. ");
						    	}
							break;
				case 2: //MODIFICAR AVIONES
					if(utn_getNumero(&auxID,"\nIngrese matricula para modificar empleado: ", "\nError, matricula invalida ", 1000, 1004, 2)==0) {
						auxIndice = buscarAvionPorMatricula(aviones, CANT_AVION, auxID);
							}
					if(auxIndice != -1) {
						modificarAvion(aviones, CANT_AVION, auxIndice);
							printf("Modificacion realizada con exito.\n");
											}
								else{
								printf("ID no encontrado.\n");
													}
							break;
				case 3: //BAJA AVION
					mostrarAvion(aviones,CANT_AVION,marcas, CANT_MARCAS);
						if(utn_getNumero(&auxID,"\nIngrese matricula de avion a dar de baja: ","\nError, ID invalido. Reingrese ID:",1000,1004, 3)==0)
							{
							auxIndice = buscarAvionPorMatricula(aviones, CANT_AVION, auxID);
							if(auxIndice >= 0 && bajaAvion(aviones, CANT_AVION, auxIndice)== 0)
											{
												printf("\nBaja realizada con exito.");
											}
										}

						break;
				case 4:
					mostrarAvion(aviones, CANT_AVION, marcas, CANT_MARCAS);
						break;
				case 5: //listar viajes
					listarViajes(viajes,CANT_VIAJES);
						break;
				case 6:
					listarMarcas(marcas,CANT_MARCAS);
						break;
		case 7:
			printf("Confirma salir?.\n\n");
			if(confirma=='s'){
				opcionMain='n';
			}
			break;
		default:
			printf("\nOpcion invalida, vuelva a elegir: \n");
			break;
		}
		system("pause");
	}while(opcionMain=='s');


	puts("asd"); /* prints asd */
	return EXIT_SUCCESS;
}