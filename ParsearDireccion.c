#include<stdio.h>
#include"funciones.h"

//palabra(4 bits), linea(3 bits), etiqueta(5 bits)
#define BITS_PALABRA 4
#define BITS_LINEA 3
#define BITS_ETQ 5
// descompone una dirección de memoria
// Obtiene el valor de la palabra (los últimos 4 bits de la dirección)
// Calcula el número de línea en la cache.
// Desplaza la dirección 4 bits a la derecha (bits de palabra)
// Calcula la etiqueta de la línea de cache.
// Desplaza la dirección a la derecha sumando los bits de palabra y linea
// Calcula el número de bloque en la memoria principal.
// Desplaza la dirección 4 bits a la derecha (bits de palabra)
void ParsearDireccion(unsigned int addr, int *ETQ, int *palabra, int *linea, int *bloque) {
    *palabra = addr & 0xF; 
    *linea = (addr >> BITS_PALABRA) & 0x7;
    *ETQ = (addr >> (BITS_PALABRA + BITS_LINEA)) & 0x1F; 
    *bloque = addr >> (BITS_PALABRA);
}
