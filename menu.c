#include <stdio.h>
#include "menu.h"

int mostrarMenu()
{
    int opcion;

    printf("----- Menú Principal -----\n");
    printf("1) Crear una lista\n");
    printf("2) Ver la lista en pantalla\n");
    printf("3) Agregar un alumno a la lista\n");
    printf("4) Calcular el promedio de la lista\n");
    printf("5) Ordenar los promedios de mayor a menor\n");
    printf("6) Salir del menú\n");
    printf("Ingrese una opción: ");
    scanf("%d", &opcion);

    return opcion;
}
