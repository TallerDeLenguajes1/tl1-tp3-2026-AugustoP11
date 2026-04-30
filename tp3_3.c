//_________________________
//BIBLIOTECAS
//_________________________
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

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
    int ProductoID;
    int Cantidad;
    char *TiposProducto;
    float PrecioUnitario;
}typedef Producto;

struct Cliente {
    int ClienteID;
    char *NombreCliente;
    int CantidadProductosAPedir;
    Producto *Productos;
}typedef Cliente;

//aleatorio = lim_inf + rand() % (lim_sup - lim_inf + 1)

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
    for (int i = 0; i < (cantidadDeClientes - 1); i++)
    {
        (Clientes + i)->ClienteID = i;
        printf("\nIngrese ");
    }
    

    return 0;
}

