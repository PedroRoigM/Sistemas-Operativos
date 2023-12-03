#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
//muestra la cache en la pantalla.
//recorre las filas linea por linea y las imprime desde el final hasta el principio.
//escribe en el archivo logcache.txt el contenido de la cache.
void MostrarCache(T_CACHE_LINE *cache) {
    printf("Contenido de la Cache:\n");

    for (int i = NUM_FILAS - 1; i >= 0; i--) {
        printf("ETQ:%X Data ", cache[i].ETQ);
        for (int j = TAM_LINEA - 1; j >= 0; j--) {
            printf("%02X ", cache[i].Data[j]);
        }
        printf("\n");
    }
    
}