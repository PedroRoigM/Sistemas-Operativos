#include<stdio.h>
#include"funciones.h"

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
