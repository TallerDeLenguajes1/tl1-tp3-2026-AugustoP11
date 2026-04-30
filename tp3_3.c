//_________________________
//BIBLIOTECAS
//_________________________
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

//_________________________
//DATOS GLOBALES
//_________________________
#define CANTIDAD_CLIENTES 5;
#define CANTIDAD_PRODUCTOS 10;
char * TiposProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};

//_________________________
//STRUCT
//_________________________
struct Producto {
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; //Aleatorio entre 1 y 10
    char *TipoProducto; //Algun valor del arreglo TiposProductos
    float PrecioUnitario; //Entre 10-100
}typedef Producto;

struct Cliente {
    int ClienteID; //Numerado en ciclo iterativo
    char *NombreCliente; //Ingresado por usuario
    int CantidadProductosAPedir; //aleatorio entre 1 y 5
    Producto *Productos; //El tamaño de este arreglo depende de la variable "CantidadProductosAPedir"
}typedef Cliente;

//_________________________
//DECLARACION DE FUNCIONES
//_________________________
float CalcularCostoTotalProducto(Producto * Productos);

//_________________________
//FUNCION MAIN
//_________________________
int main() {

    //Interfaz donde solicito la cantidad de clientes
    int cantidadDeClientes;
    do
    {
        printf("\nIngrese la cantidad de clientes (entre 1 y 5): ");
        scanf("%d", &cantidadDeClientes);
        fflush(stdin);
    } while (cantidadDeClientes < 1 || cantidadDeClientes > 5);
    
    //Creo los clientes dinamicamente
    Cliente * Clientes = (Cliente *) malloc(cantidadDeClientes * sizeof(Cliente));

    //Solicito a los usuarios la carga de los clientes
    char Buff[50];
    int tamanioNombreCliente;
    srand(time(NULL));

    for (int i = 0; i < cantidadDeClientes; i++)
    {
        //ID del cliente
        (Clientes + i)->ClienteID = i;

        //Nombre del cliente
        printf("\nIngrese el nombre del cliente %d: ", (i+1));
        gets(Buff);
        tamanioNombreCliente = strlen(Buff);
        (Clientes + i)->NombreCliente = (char *) malloc(tamanioNombreCliente * sizeof(char));
        strcpy((Clientes+i)->NombreCliente, Buff);

        //Cantidad de productos a pedir (aleatorio entre 1 y 5)
        //Uso la siguiente formula: aleatorio = lim_inf + rand() % (lim_sup - lim_inf + 1)
        (Clientes+i)->CantidadProductosAPedir = 1 + rand() % (5 - 1 + 1);

        //Procedo a la carga de productos aleatoria ya que tenemos la cantidad de productos a pedir
        (Clientes+i)->Productos = (Producto *) malloc((Clientes+i)->CantidadProductosAPedir * sizeof(Producto));
        for (int j = 0; j < (Clientes+i)->CantidadProductosAPedir; j++)
        {
            //ID del producto
            ((Clientes+i)->Productos+j)->ProductoID = j;

            //Cantidad (entre 1 y 10)
            //Uso la formula: aleatorio = lim_inf + rand() % (lim_sup - lim_inf + 1)
            ((Clientes+i)->Productos+j)->Cantidad = 1 + rand() % (10 - 1 + 1);

            //Tipo producto (algun valor del arreglo TiposProductos)
            int tipoAleatorio = 0 + rand() % (4 - 0 + 1);
            ((Clientes+i)->Productos+j)->TipoProducto = TiposProductos[tipoAleatorio];

            //Precio unitario (entre 10 y 100)
            //Como quiero generar un numero flotante aleatorio, uso la siguiente formula
            //flotante_aleatorio = lim_inf + (float)rand() / ((float)RAND_MAX / (lim_sup - lim_inf))
            //siendo lim_inf y lim_sup flotantes 
            ((Clientes+i)->Productos+j)->PrecioUnitario = 10.00 + (float)rand() / ((float)RAND_MAX / (100.00 - 10.00));
        }
    }
    
    //Funcion que devuelve el costo total de cada producto
    //float costo = CalcularCostoTotalProducto(Clientes->Productos);

    //Mostrar por pantalla todo lo cargado
    printf("\n-------------------------------\n");
    for (int i = 0; i < cantidadDeClientes; i++)
    {
        printf("__________CLIENTE %d__________\n", (i+1));
        printf("ID del cliente: %d\n", (Clientes+i)->ClienteID);
        printf("Nombre del cliente: %s\n", (Clientes+i)->NombreCliente);
        printf("Cantidad de productos que pide: %d\n", (Clientes+i)->CantidadProductosAPedir);
        
        printf("__________PRODUCTOS__________\n");
        float sumatoriaCostos = 0;
        for (int j = 0; j < (Clientes+i)->CantidadProductosAPedir; j++)
        {
            printf("ID del producto: %d\n", ((Clientes+i)->Productos+j)->ProductoID);
            printf("Cantidad: %d\n", ((Clientes+i)->Productos+j)->Cantidad);
            printf("Tipo de producto: %s\n", ((Clientes+i)->Productos+j)->TipoProducto);
            printf("Precio unitario: %.2f\n", ((Clientes+i)->Productos+j)->PrecioUnitario);
            float costo = CalcularCostoTotalProducto((Clientes+i)->Productos+j);
            printf("Costo: %.2f\n\n", costo);
            sumatoriaCostos += costo;
        }
        printf("TOTAL A PAGAR: %.2f", sumatoriaCostos);
        printf("\n-------------------------------\n");
    }

    //Libero memoria
    for (int i = 0; i < cantidadDeClientes; i++)
    {
        free(Clientes[i].Productos);
    }
    free(Clientes);

    return 0;
}

//_________________________
//DEFINICION DE FUNCIONES
//_________________________
float CalcularCostoTotalProducto(Producto * Productos)
{
    float costoTotal = Productos->Cantidad * Productos->PrecioUnitario;
    return(costoTotal);
}