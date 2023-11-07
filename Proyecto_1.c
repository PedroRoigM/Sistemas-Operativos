#include<stdio.h>
#include<stdlib.h>
#define TAM_LINEA 8 //3 bits de linea 2^3 = 8
double globaltime = 0;
int numfallos = 0;
typedef struct {
        unsigned char ETQ;
        unsigned char Data[TAM_LINEA];
}T_CACHE_LINE;

void LimpiarCACHE(T_CACHE_LINE tbl[NUM_FILAS]);
void VolcarCACHE(T_CACHE_LINE *tbl);
void ParsearDireccion(unsigned int addr, int *ETQ, int *palabra, int *linea, int *bloque);
void TratarFallo(T_CACHE_LINE *tbl, char *MRAM, int ETQ, int linea, int bloque);

//Bus de memoria de 12 bits y usa memoria fisica
//Caché de 8 lineas con correspondencia directa y 16 bytes por linea
//palabra(4 bits), linea(3 bits), etiqueta(5 bits)

int main(){
	T_CACHE_LINE MEMsym[16];

	unsigned char Simul_RAM[4096];

	return 0;
}
void LimpiarCACHE(T_CACHE_LINE tbl[NUM_FILAS]){
	//aqui en teoria hay que inicializar el array de estructuras como pone en el pdf
}
void VolcarCACHE(T_CACHE_LINE *tbl){
	//tiene de mostrar por pantalla los datos
}
void ParsearDireccion(unsigned int addr, int *ETQ, int *palabra, int *linea, int *bloque){

}
void TratarFallo(T_CACHE_LINE *tbl, char *MRAM, int ETQ, int linea, int bloque){
	printf("T: %d, Fallo de CACHE %d, ADDR %04X Label %X linea %02X palabra %02X bloque %02X");
}

