#include <stdio.h>
#include "menu.h"

/**
 * @brief Muestra el menú principal en pantalla y captura la opción del usuario.
 *
 * @return La opción seleccionada por el usuario como un entero.
 *         - 1: Crear una lista.
 *         - 2: Ver la lista en pantalla.
 *         - 3: Agregar un alumno a la lista.
 *         - 4: Ordenar los promedios de mayor a menor.
 *         - 5: Salir del menú.
 */
int mostrarMenu()
{
    int opcion;

    printf("----- Menú Principal -----\n");
    printf("1) Crear una lista\n");
    printf("2) Ver la lista en pantalla\n");
    printf("3) Agregar un alumno a la lista\n");
    printf("4) Ordenar los promedios de mayor a menor\n");
    printf("5) Salir del menú\n");
    printf("Ingrese una opción: ");
    scanf("%d", &opcion);

    return opcion;
}
