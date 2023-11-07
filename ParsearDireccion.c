#include<stdio.h>
#include"funciones.h"

void ParsearDireccion(unsigned int addr, int *ETQ, int *palabra, int *linea, int *bloque) {
    *palabra = addr & 0xF; 
    *linea = (addr >> TAM_PALABRA) & 0x7;
    *ETQ = (addr >> (TAM_PALABRA + TAM_LINEA)) & 0x1F; 
    *bloque = (addr >> TAM_PALABRA) & 0xFF; 
}