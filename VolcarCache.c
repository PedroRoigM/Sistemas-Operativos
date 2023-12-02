#include<stdio.h>
#include"funciones.h"

// escribe el contenido actual de la cache en un archivo binario.
// abre el archivo
// recorre cada fila de la tabla de cache.
// escribe los datos de cada linea en el archivo
//cierra el archivo
void VolcarCACHE(T_CACHE_LINE *tbl){
    FILE *file = fopen("CONTENTS_CACHE.bin", "wb");
    if (file == NULL) {
        perror("Error al abrir el archivo");
        return;
    }
    for (int i = 0; i < NUM_FILAS; i++) {
        fwrite(tbl[i].Data, sizeof(unsigned char), TAM_LINEA, file);
    }
    fclose(file);
}

