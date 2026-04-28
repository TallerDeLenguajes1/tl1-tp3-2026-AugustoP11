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



    /*
    MostrarPersonas(V);
    
    int id;
    printf("\nIngrese un ID: ");
    scanf("%d", &id);
    getchar();

    BuscaNombrePorId(V, id);

    
    printf("\nIngrese una palabra clave: ");
    gets(Buff);
    fflush(stdin);
    char *palabra_clave;
    palabra_clave = (char*)malloc(strlen(Buff)*sizeof(char));
    strcpy(palabra_clave, Buff);

        //prueba nueva version de BuscaNombrePorPalabra()
    char palabraClave[] = "ho";
    char * nombreEncontrado = BuscaNombrePorPalabra(V, palabraClave);
    */
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
        char *coincidencia = strstr(Nombres[i], palabra_clave);
        
        if (coincidencia)
        {
            return (Nombres[i]);
        }
        i++;
    }
    return (NULL);
}