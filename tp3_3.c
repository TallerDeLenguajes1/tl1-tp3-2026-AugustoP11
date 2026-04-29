//_________________________
//BIBLIOTECAS
//_________________________
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

//_________________________
//ARREGLO GLOBAL
//_________________________
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


    return 0;
}

