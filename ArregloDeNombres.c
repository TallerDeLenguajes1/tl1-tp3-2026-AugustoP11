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
#define N 2

//___________________________
//DECLARACION DE FUNCIONES
//___________________________
void MostrarPersonas(char *Nombres[]);

int BuscarNombre(char *Nombres[], char *palabra_clave);

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
    
    printf("\nIngrese una palabra clave: ");
    gets(Buff);
    fflush(stdin);
    char *palabra_clave;
    palabra_clave = (char*)malloc(strlen(Buff)*sizeof(char));
    strcpy(palabra_clave, Buff);
    int buscar = BuscarNombre(V, palabra_clave);
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

int BuscarNombre(char *Nombres[], char *palabra_clave)
{
    int flag = 0;
    int i = 0;
    while (flag == 0 && i < N)
    {
        char *coincidencia = strstr(Nombres[i], palabra_clave);
        
        if (coincidencia)
        {
            printf("\nNombre: %s", Nombres[i]);
            flag = 1;
        }
        i++;
    }
    if (flag == 1)
    {
        return 0;
    } else {
        return (-1);
    }
}