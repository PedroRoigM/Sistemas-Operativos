#include<stdio.h>
#include<stdlib.h>
#include"funciones.h"
//maneja los fallos en la cache actualizando la línea de cache correspondiente.
// calcula la dirección de comienzo del bloque en la memoria principal
// recorre cada elemento de la línea de cache.
//actualiza la cache con los datos correspondientes de la MRAM.
//suma el desplazamiento i a la dirección de comienzo para obtener la posicion correcta en la MRAM.
// actualiza la etiqueta de la línea de cache
void TratarFallo(T_CACHE_LINE *tbl, char *MRAM, int ETQ, int linea, int bloque){
    int dirComienzo = bloque * TAM_LINEA;   
    for (int i = 0; i < TAM_LINEA; i++) {
        tbl[linea].Data[i] = MRAM[dirComienzo + i];
    }
    tbl[linea].ETQ = ETQ;
}


