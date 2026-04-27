#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 15 

void mostrarPersonas(char *nombres[]);
void buscarNombre(char *nombres[], char palabra[]);

int main(){
    char *nombresDeAlumnos[5]; 

    char buff[120];

    for(int i=0; i<5; i++){
        printf("Ingrese nombre del alumno: ");
        scanf("%s", buff);
        int cantidadDeCaracteres = strlen(buff); //sirve para saber que cantidad de reserva debo pedir
        nombresDeAlumnos[i]=(char*)malloc(sizeof(char)*(cantidadDeCaracteres + 1)); //le sumo 1 porque tiene en cuenta la barra final de frase
        strcpy(nombresDeAlumnos[i], buff);

    }
    mostrarPersonas(nombresDeAlumnos);

    char palabra[DIM];

    printf("Ingrese la palabra a buscar: ");
    scanf("%s", palabra);
    buscarNombre(nombresDeAlumnos, palabra);

    return 0;
}

void mostrarPersonas(char *nombres[]){
    printf("Los alumnos son: \n");
    for(int i =0; i<5; i++){
        printf("%s, \t ", nombres[i]);
    }
}

void buscarNombre(char *nombres[], char palabra[]){
    int i=0;
    for(int i=0; i<5; i++ ){
        if(strstr(nombres[i], palabra) != NULL){
            printf("EL nombre que contiene la palabra ingresada es %s", nombres[i]);
            return;
        }
    }
    printf("-1"); 
}