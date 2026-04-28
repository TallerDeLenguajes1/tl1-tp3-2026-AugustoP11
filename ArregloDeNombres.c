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

void BuscaNombrePorId(char *Nombres[], int id);

char * BuscaNombrePorPalabra(char *Nombres[], char *palabra_clave);

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
    
    //___________________________
    //INTERFAZ DE USUARIO
    //___________________________

    printf("____________BUSQUEDA DE NOMBRE____________\n1. Ingrese '1' para realiar una busqueda por ID\n2. Ingrese '2' para realizar una busqueda por palabra clave\n");
    int opcion;
    int id;

    do {
        scanf("%d", &opcion);
        fflush(stdin);
        switch (opcion)
        {
        case 1:
            printf("\nIngrese un ID: ");
            scanf("%d", &id);
            getchar();
            BuscaNombrePorId(V, id);
            break;
        
        case 2:
            printf("\nIngrese una palabra clave: ");
            gets(Buff);
            char * palabraClave = (char *) malloc(strlen(Buff) * sizeof(char) + 1);
            strcpy(palabraClave, Buff);
            char * nombreEncontrado = BuscaNombrePorPalabra(V, palabraClave);
            if (nombreEncontrado != NULL)
            {
                printf("\n");
                puts(nombreEncontrado);
            } else {
                printf("\nNo se encontro ningun nombre\n");
            }
            free(palabraClave);
            break;
        default:
            printf("\nIngrese una opcion valida\n");
            break;
        }
    } while (opcion != 1 && opcion != 2);

    //Libero memoria
    free(V);

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

void BuscaNombrePorId(char *Nombres[], int id)
{
    if (id > N || N < 0)
    {
        printf("\nNo se encontro el valor buscado.\n");
    } else {
        printf("\nNombre: %s\n", Nombres[id]);
    }
}

char * BuscaNombrePorPalabra(char *Nombres[], char *palabra_clave)
{
    int i = 0;
    while (i < N)
    {
        char *coincidencia;
        coincidencia = strstr(Nombres[i], palabra_clave);
        
        if (coincidencia)
        {
            return (Nombres[i]);
        }
        i++;
    }
    return (NULL);
}