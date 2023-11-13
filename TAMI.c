#include<stdio.h>
#include<stdlib.h>
#include"funciones.h"
static int globaltime = 0;
static int numfallos = 0;
int* tami(int tiempo, int fallos){
	globaltime+=tiempo;
	numfallos+=fallos;

	int *variablesGlobales = (int*)malloc(2 * sizeof(int));
	variablesGlobales[0] = globaltime;
	variablesGlobales[1] = numfallos;
	return variablesGlobales;
}
