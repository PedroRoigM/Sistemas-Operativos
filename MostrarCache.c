#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
void MostrarCache(T_CACHE_LINE *cache) {
    // Mostrar en la pantalla
    printf("Contenido de la Cache:\n");

    for (int i = NUM_FILAS - 1; i >= 0; i--) {
        printf("ETQ:%X Data ", cache[i].ETQ);
        for (int j = TAM_LINEA - 1; j >= 0; j--) {
            printf("%02X ", cache[i].Data[j]);
        }
        printf("\n");
    }

    // Abrir el archivo en modo de escritura (sobrescribir) y escribir el contenido de la cache
    FILE *archivo = fopen("logcache.txt", "w");
    if (archivo != NULL) {
        fprintf(archivo, "Contenido de la Cache:\n");

        for (int i = NUM_FILAS - 1; i >= 0; i--) {
            fprintf(archivo, "ETQ:%X Data ", cache[i].ETQ);
            for (int j = TAM_LINEA - 1; j >= 0; j--) {
                fprintf(archivo, "%02X ", cache[i].Data[j]);
            }
            fprintf(archivo, "\n");
        }

        fclose(archivo);
    } else {
        printf("Error al abrir el archivo.\n");
    }
}