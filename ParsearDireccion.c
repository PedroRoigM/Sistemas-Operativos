#include<stdio.h>
#include"funciones.h"

//palabra(4 bits), linea(3 bits), etiqueta(5 bits)
#define BITS_PALABRA 4
#define BITS_LINEA 3
#define BITS_ETQ 5
void ParsearDireccion(unsigned int addr, int *ETQ, int *palabra, int *linea, int *bloque) {
    *palabra = addr & 0xF; 
    *linea = (addr >> BITS_PALABRA) & 0x7;
    *ETQ = (addr >> (BITS_PALABRA + BITS_LINEA)) & 0x1F; 
    *bloque = addr >> (BITS_PALABRA);
}