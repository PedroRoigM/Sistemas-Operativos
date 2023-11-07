#include<stdio.h>
#include"funciones.h"

void VolcarCACHE(T_CACHE_LINE *tbl){
	int i = 0;
	printf("T: , Acierto de CACHE, ADDR, ETQ  linea  palabra  DATO \n");
	for(int i = 8; i > 0; i--){

		printf("ETQ:%d Data ", tbl[i].ETQ);
		for(int j = 15; j > 0; j--){
			printf("%d ", tbl[i].Data[j]);
		}
		printf("\n");
	}

}
