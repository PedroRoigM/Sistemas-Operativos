#ifndef funciones_h
#define funciones_h
#define TAM_LINEA 16
#define NUM_FILAS 8
#define TAM_PALABRA 4
#define TAM_ETIQUETA 5
#define TAM_RAM 4096


typedef struct {
        unsigned char ETQ;
        unsigned char Data[TAM_LINEA];
}T_CACHE_LINE;


void LimpiarCACHE(T_CACHE_LINE tbl[]);
void VolcarCACHE(T_CACHE_LINE *tbl);
void ParsearDireccion(unsigned int addr, int *ETQ, int *palabra, int *linea, int *bloque);
void TratarFallo(T_CACHE_LINE *tbl, char *MRAM, int ETQ, int linea, int bloque);
void MostrarCache(T_CACHE_LINE *cache);

#endif

