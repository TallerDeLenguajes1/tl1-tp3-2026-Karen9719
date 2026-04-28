#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

typedef struct {
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
}Producto;

typedef struct{
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos; //El tamaño de este arreglo depende de la variable  “CantidadProductosAPedir”
}Cliente;

//funciones
float calcularCosto(Producto prod);

int main(){
    srand(time(NULL));

    Cliente *pClientes;
    int cantClientes; //lo uso para saber la cantidad de memoria que debo reservar

    printf("Ingrese la cantidad de clientes(1-5): ");
    scanf("%d", &cantClientes);
    getchar(); 

    pClientes = (Cliente*)malloc(cantClientes * sizeof(Cliente));

    for(int i=0; i<cantClientes; i++){
        //para ClienteID
        pClientes[i].ClienteID =1+i;

        //para NombreCliente
        char *buff;
        buff=(char*)malloc(100*sizeof(char));

        printf("\nCliente %d \n", i+1);
        printf("\nIngrese el nombre del cliente: ");
        gets(buff);

        pClientes[i].NombreCliente = (char*)malloc((strlen(buff)+1) * sizeof(char));
        strcpy(pClientes[i].NombreCliente, buff);

        //para cantidadProductosAPedir
        pClientes[i].CantidadProductosAPedir= 1+rand()%5;

        printf("\n-----cliente %d ---------\n", i+1);
        printf("ID: %d\n", pClientes[i].ClienteID);
        printf("Nombre: ");
        puts(pClientes[i].NombreCliente);
        printf("Cantidad de Productos a pedir: %d\n", pClientes[i].CantidadProductosAPedir);
        //para Productos
        Producto *pProductos;
        pProductos = (Producto*)malloc(pClientes[i].CantidadProductosAPedir*sizeof(Producto));

        printf("\n----------PRODUCTOS---------\n");
        for(int j=0; j<pClientes[i].CantidadProductosAPedir; j++){

            pProductos[j].ProductoID=j+1;

            pProductos[j].Cantidad = 1+rand()%10;

            int k = rand()%5;
            pProductos[j].TipoProducto=TiposProductos[k];

            pProductos[j].PrecioUnitario= 1+rand()%100;

            float costo = calcularCosto(pProductos[j]);

            printf("\nDetalles del producto:\n");
            printf("ID: %d\n", pProductos[j].ProductoID);
            printf("Cantidad: %d\n", pProductos[j].Cantidad);
            printf("Tipo: %s\n", pProductos[j].TipoProducto);
            printf("Precio: %.2f\n", pProductos[j].PrecioUnitario);
            printf("Costo Total : %.2f", costo);

        }
        free(buff);
        free(pProductos);
        
    }
    free(pClientes);
    return 0;
}

float calcularCosto(Producto prod){
    float costo;
    costo = prod.Cantidad*prod.PrecioUnitario;
    return costo;
}