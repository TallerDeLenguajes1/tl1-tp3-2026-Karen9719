#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mostrarPersonas(char *nombres[]);//recibe un arreglo de cadenas(nombres de los alumnos)
void buscarNombre(char *nombres[], int indice);

int main(){
    int posicion;
    char *nombresDeAlumnos[5]; //habrá espacio para 5 nombres, cada posicion guardará la dirección de memoria de un nombre

    char buff[120]; //creo un buffer temporal, sirve para guardar el nombre ingresado por teclado momentáneamente

    for(int i=0; i<5; i++){                         //se repite 5 veces para ingresar 5 alumnos
        printf("Ingrese nombre del alumno: ");
        scanf("%s", buff);                          //s necesita una dirección y 'buff' es la direccion de memoria del arreglo buff[120]
        int cantidadDeCaracteres = strlen(buff);        //sirve para saber que cantidad de reserva debo pedir, calcula cuantos caracteres tiene la cadena
        nombresDeAlumnos[i]=(char*)malloc(sizeof(char)*(cantidadDeCaracteres + 1)); //le sumo 1 porque tiene en cuenta la barra final de frase, reserva de memoria dinamica para el nombre ingresado
        strcpy(nombresDeAlumnos[i], buff);    //copia el contenido de buff al espacio reservado, bff ->'carlos' se copia en nombresDeAlumnos[i]

    }
    mostrarPersonas(nombresDeAlumnos);
    
    printf("\nIngrese el numero posicion del nombre a buscado:  ");
    scanf("%d", &posicion);
    buscarNombre(nombresDeAlumnos,posicion);

    return 0;
}

void mostrarPersonas(char *nombres[]){
    printf("Los alumnos son: \n");
    for(int i =0; i<5; i++){
        printf("%s, \t ", nombres[i]);
    }
}

void buscarNombre(char *nombres[], int indice){ //consultar si esta bien implementado
    if(indice>5 || indice < 1){
        printf("No se encontro el valor buscado.");
    }else{
        printf("El nombre ubicado en la posicion %d es %s ", indice, nombres[indice-1]);
    }
}