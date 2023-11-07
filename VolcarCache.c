#include<stdio.h>
#include"funciones.h"

void VolcarCACHE(T_CACHE_LINE *tbl){
	int i = 0;
	for(int i = NUM_FILAS - 1; i >= 0; i--){ 

		printf("ETQ:%X Data ", tbl[i].ETQ);
		for(int j = TAM_LINEA; j >= 0; j--){
			printf("%X ", tbl[i].Data[j]);
		}
		printf("\n");
	}

}
