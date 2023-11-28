#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
void MostrarCache(T_CACHE_LINE *cache) {
    printf("Contenido de la Cache:\n");
    int i = 0;
	for(int i = NUM_FILAS - 1; i >= 0; i--){ 

		printf("ETQ:%X Data ", cache[i].ETQ);
		for(int j = TAM_LINEA - 1; j >= 0; j--){
			printf("%02X ", cache[i].Data[j]);
		}
		printf("\n");
	}
}
