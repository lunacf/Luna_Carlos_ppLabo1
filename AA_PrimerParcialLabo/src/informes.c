/*
 * informes.c
 *
 *  Created on: 11 oct 2021
 *      Author: Luna Carlos Facundo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aviones.h"
#include "marcas.h"
#include "viajes.h"
#include "fecha.h"
#include "informes.h"

char menuInformes(){
	int opcionElegida;

		printf("------- MENU DE INFORMES -------\n");
		printf("\nIngrese una opcion para operar: \n");
		printf("[1] - Informar aviones por marca.\n");
		printf("[2] - .\n");
		printf("[3] - .\n");
		printf("[4] - .\n");
		printf("[5] - .\n");
		printf("[6] - .\n");
		printf("[7] - .\n");
		printf("[8] - Salir del menu.\n");
		fflush(stdin);
		scanf("%d",&opcionElegida);
		opcionElegida = tolower(opcionElegida);

		return opcionElegida;
}

void informarAvionesPorMarca(eAvion aviones[], int tamAviones, eMarca arrayM[],
		int tamM, eViajes arrayV[], int tamV) {
	int cantAviones = 0;
	int resMarca;
	int i;
	system("cls");
	printf(
			"#######################################################################\n\n");
	printf(
			"##############################Lista de aviones de la misma marca######################### \n\n");

	if (arrayM != NULL && arrayV != NULL && aviones != NULL && tamAviones > 0 && tamM > 0 && tamV > 0) {
		listarMarcas(arrayM, tamM);
		utn_getNumero(&resMarca, "Ingrese id de la marca a mostrar", "Error.\n\n", 1000, 4000, 3);
			for (i = 0; i < tamAviones; i++) {
				if (resMarca == aviones[i].idMarca) {
					printf("ID   Matricula     Fecha       Viaje     Marca        Modelo                Asientos\n\n");
						mostrarAvion(aviones[i], arrayM, tamM, arrayV, tamV);
						cantAviones = 1;
				}
			}

		if (cantAviones == 0) {
			printf(
					"ID   Matricula     Fecha       IDviaje  Marca   Modelo    Asientos\n\n");
			printf(" Marca %10s -     No tiene aviones cargadas\n\n");
		}
	}
	printf(
			"#######################################################################\n\n");
}
