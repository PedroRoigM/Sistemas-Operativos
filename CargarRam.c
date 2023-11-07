#include<stdio.h>
#include"funciones.h"

int CargarRam(unsigned char *Simul_RAM) {
    FILE *archivo = fopen("CONTENTS_RAM.bin", "rb");
    if (archivo == NULL) {
        perror("Error al abrir el archivo CONTENTS_RAM.bin");
        return -1;
    }
    size_t bytesLeidos = fread(Simul_RAM, sizeof(unsigned char), TAM_RAM, archivo);
    if (bytesLeidos < TAM_RAM) {
        if (feof(archivo)) {
            fprintf(stderr, "Error: El archivo 'CONTENTS_RAM.bin' es más pequeño de lo esperado.\n");
        } else {
            perror("Error al leer el archivo");
        }
        fclose(archivo);
        return -1; 
    }
    fclose(archivo); 
    return 0; 
}