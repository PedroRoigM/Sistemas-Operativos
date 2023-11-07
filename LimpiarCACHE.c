#include<stdio.h>
#include"funciones.h"

void LimpiarCache(T_CACHE_LINE tbl[]){
	for (int i = 0; i < NUM_FILAS; ++i) {
        tbl[i].ETQ = 0xFF; 
        for (int j = 0; j < TAM_LINEA; ++j) {
            tbl[i].Data[j] = 0x23; 
        }
    }
}
