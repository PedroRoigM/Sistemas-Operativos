#include<stdio.h>
#include<stdlib.h>
#include"funciones.h"
void TratarFallo(T_CACHE_LINE *tbl, char *MRAM, int ETQ, int linea, int bloque){
    int startAddress = bloque * TAM_LINEA;  
    for (int i = 0; i < TAM_LINEA; i++) {
        tbl[linea].Data[i] = MRAM[startAddress + i];
    }
    tbl[linea].ETQ = ETQ;
}

