#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include"funciones.h"
//Bus de memoria de 12 bits y usa memoria fisica
//Caché de 8 lineas con correspondencia directa y 16 bytes por linea
//palabra(4 bits), linea(3 bits), etiqueta(5 bits)

int main() {
    T_CACHE_LINE cache[NUM_FILAS];
    unsigned char Simul_RAM[4096];
    unsigned int time = 1;
    unsigned int numfallos = 0;
    unsigned int numaccesos = 0;
    FILE *file;
    char line[5];  // Para leer las direcciones de memoria
    char texto[TAM_RAM] = {0};  // Para almacenar el texto leído de la caché
    int texto_idx = 0;
    // Inicializa la cache
    LimpiarCACHE(cache);
    // Carga el contenido de la RAM desde el archivo
    file = fopen("CONTENTS_RAM.bin", "rb");
    if (!file) {
        perror("Error al abrir CONTENTS_RAM.bin");
        return -1;
    }
    fread(Simul_RAM, sizeof(unsigned char), 4096, file);
    fclose(file);

    // Procesa las direcciones de memoria desde el archivo
    file = fopen("accesos_memoria.txt", "r");
    if (!file) {
        perror("Error al abrir dirs_memoria.txt");
        return -1;
    }

    while (fgets(line, sizeof(line), file)) {
        unsigned int addr;
        int ETQ, palabra, linea, bloque;

        sscanf(line, "%x", &addr);
        ParsearDireccion(addr, &ETQ, &palabra, &linea, &bloque);
		
        numaccesos++;

        // Comprobacion de cache
        if (cache[linea].ETQ == ETQ) {
            // Acierto de cache
            
			unsigned char dato = cache[linea].Data[palabra];
			texto[texto_idx++] = dato;
            printf("T: %u, Acierto de cache, addr %04X etq %X linea %02X dato %02X\n", 
                   time, addr, ETQ, linea, dato);
            time += 1;
        } else {
            // Fallo de caché
            TratarFallo(cache, Simul_RAM, ETQ, linea, bloque);
			
			unsigned char dato = cache[linea].Data[palabra];
			texto[texto_idx++] = dato;
            numfallos++;
			
            printf("T: %u, Fallo de CACHE %d, ADDR %02X ETQ %02X linea %02X palabra %02X bloque %02X\n", 
                   time, numfallos, addr, ETQ, linea, palabra, bloque);
            printf("Cargando el bloque %02X en la linea %02X\n", bloque, linea);
            time += 20;
        }
		
		
		
		
        sleep(1); // Simulación de delay
    }

    fclose(file);

    // Mostrar el contenido de la cache
    MostrarCache(cache);

    // Estadisticas finales
    printf("Numero total de accesos: %u\n", numaccesos);
    printf("Numero de fallos: %u\n", numfallos);
    printf("Tiempo medio de acceso: %.2f\n", (double)time / numaccesos);
    printf("Texto leido: %s\n", texto);
    // Guardar el contenido final de la cache en un archivo
    VolcarCACHE(cache);

    return 0;
}


