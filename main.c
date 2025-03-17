/**
 * @file main.c
 * @brief Programa principal para gestionar una lista doblemente enlazada circular de alumnos.
 * 
 * Este programa permite crear una lista de alumnos, agregar alumnos, mostrar la lista,
 * ordenar los alumnos por promedio y eliminar la lista antes de salir.
 */

#include <stdio.h>
#include <stdlib.h>
#include "alumno.h"
#include "cdll.h"
#include "menu.h"

/**
 * @brief Función principal del programa.
 * 
 * @return Retorna 0 al finalizar el programa correctamente.
 * 
 * El programa ejecuta un menú interactivo que permite gestionar la lista de alumnos.
 */
int main()
{
    CDLL* lista = NULL;  /**< Puntero a la lista de alumnos */
    int opcion;          /**< Variable para almacenar la opción del menú */

    do
    {
        opcion = mostrarMenu(); /**< Llama a la función para mostrar el menú y obtiene la opción seleccionada */

        switch (opcion)
        {
            case 1: {
                printf("Opción seleccionada: Crear una lista\n");
                lista = crearLista();
                printf("Se ha creado una lista.\n");
                break;
            }
            case 2: {
                printf("Opción seleccionada: Ver la lista en pantalla\n");
                mostrarLista(lista);
                break;
            }
            case 3: {
                printf("Opción seleccionada: Agregar un alumno a la lista\n");
                char nombre[50], apellido[50];
                int cuenta;
                double calif[3];

                printf("Ingrese el nombre del alumno: ");
                scanf("%s", nombre);

                printf("Ingrese el apellido del alumno: ");
                scanf("%s", apellido);

                printf("Ingrese el número de cuenta del alumno: ");
                scanf("%d", &cuenta);

                printf("Ingrese las calificaciones del alumno:\n");
                for (int i = 0; i < 3; i++)
                {
                    printf("Calificación %d: ", i + 1);
                    scanf("%lf", &calif[i]);
                }

                añadir_Alumno(lista, nombre, apellido, cuenta, calif);
                break;
            }
            case 4: {
                printf("Opción seleccionada: Ordenar los promedios de mayor a menor\n");
                ordenarPromedios(lista);
                printf("La lista ha sido ordenada por promedios de mayor a menor.\n");
                break;
            }
            case 5: {
                printf("Opción seleccionada: Salir del menú\n");
                eliminarLista(lista);
                exit(-1);
                break;
            }
            default: {
                printf("Opción inválida. Por favor, seleccione una opción válida.\n");
                break;
            }
        }

        printf("\n");
    } while (opcion != 7);

    return 0;
}