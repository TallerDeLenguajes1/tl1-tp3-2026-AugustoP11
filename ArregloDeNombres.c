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
void MostrarPersonas(char *Nombres[]);

void BuscarNombre(char *Nombres[], int id);

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
    
    MostrarPersonas(V);
    
    int id;
    printf("\nIngrese un ID: ");
    scanf("%d", &id);
    getchar();

    BuscarNombre(V, id);

    return 0;
}

//___________________________
//DEFINICION DE FUNCIONES
//___________________________
void MostrarPersonas(char *Nombres[])
{
    for (int i = 0; i < N; i++)
    {
        printf("\nNombre %d: %s", (i+1), Nombres[i]);
    }
}

void BuscarNombre(char *Nombres[], int id)
{
    if (id > N || N < 0)
    {
        printf("\nNo se encontro el valor buscado.\n");
    } else {
        printf("\nNombre: %s\n", Nombres[id]);
    }
}