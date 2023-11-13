#include<stdio.h>
#include<stdlib.h>
#include"funciones.h"
void TratarFallo(T_CACHE_LINE *tbl, char *MRAM, int ETQ, int linea, int bloque){
	int *variablesG = tami(20, 1);
	//numfallos++;
	printf("T: %d, Fallo de caché %d, addr %04X etq %X linea %02X palabra %02X bloque %02X", variablesG[0], variablesG[1], *MRAM, ETQ, linea, bloque, 1);
	//globaltime+=20;
}
