//___________________________
//BIBLIOTECAS
//___________________________
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

//___________________________
//constantes
//___________________________
#define N 5

//___________________________
//DECLARACION DE FUNCIONES
//___________________________
void mostrarPersonas(char *Nombres[]);

//___________________________
//funcion main
//___________________________
int main(){

    int i;
    char *V[N];
    char Buff[50];
    for (int i = 0; i < N; i++)
    {
        printf("\nIngrese el nombre de la persona %d: ", (i+1));
        gets(Buff);
        fflush(stdin);
        int longitud = strlen(Buff);
        V[i] = (char*)malloc((sizeof(char) * longitud + 1));
        strcpy(V[i], Buff);
    }
    
    mostrarPersonas(V);
    
    return 0;
}

//___________________________
//DEFINICION DE FUNCIONES
//___________________________
void mostrarPersonas(char *Nombres[])
{
    for (int i = 0; i < N; i++)
    {
        printf("\nNombre %d: %s", (i+1), Nombres[i]);
    }
}