#ifndef funciones_h
#define funciones_h
#define TAM_LINEA 8 //3 bits de linea 2^3 = 8

double globaltime = 0;
int numfallos = 0;
typedef struct {
        unsigned char ETQ;
        unsigned char Data[TAM_LINEA];
}T_CACHE_LINE;


void LimpiarCACHE(T_CACHE_LINE tbl[]);
void VolcarCACHE(T_CACHE_LINE *tbl);
void ParsearDireccion(unsigned int addr, int *ETQ, int *palabra, int *linea, int *bloque);
void TratarFallo(T_CACHE_LINE *tbl, char *MRAM, int ETQ, int linea, int bloque);



#endif

