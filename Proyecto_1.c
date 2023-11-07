#include<stdio.h>
#include<stdlib.h>
#include"funciones.h"


//Bus de memoria de 12 bits y usa memoria fisica
//Caché de 8 lineas con correspondencia directa y 16 bytes por linea
//palabra(4 bits), linea(3 bits), etiqueta(5 bits)

int main(){
	T_CACHE_LINE MEMsym[NUM_FILAS];

	unsigned char Simul_RAM[TAM_RAM];
	//En caso de error hay que hacer un return -1
	//LimpiarCACHE(MEMsym);
	CargarRam(Simul_RAM);

	return 0;
}


