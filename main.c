#include <stdio.h>
#include <stdlib.h>
#include "alumno.h"
#include "cdll.h"
#include "menu.h"

int main()
{
    CDLL* lista = NULL;
    int opcion;

    do
    {
        opcion = mostrarMenu();

        switch (opcion)
        {
            case 1: {
                printf("Opción seleccionada: Crear una lista\n");
                lista = crearLista();
                printf("Se ha creado una lista.\n");
                break;
            }
            case 2: {
                printf("Opción seleccionada: Ver las listas creadas\n");
                // Aquí iría el código para ver las listas creadas
                // (mostrar sus características, etc.)
                break;
            }
            case 3: {
                printf("Opción seleccionada: Agregar un alumno a la lista\n");
                Alumno alumno;

                printf("Ingrese el nombre del alumno: ");
                scanf("%s", alumno.nombre);

                printf("Ingrese el apellido del alumno: ");
                scanf("%s", alumno.apellido);

                printf("Ingrese el número de cuenta del alumno: ");
                scanf("%d", &alumno.numeroCuenta);

                printf("Ingrese las calificaciones del alumno:\n");
                int i;
                for (i = 0; i < 3; i++)
                {
                    printf("Calificación %d: ", i + 1);
                    scanf("%lf", &alumno.calificaciones[i]);
                }

                agregarNodo(lista, alumno);
                printf("Se ha agregado al alumno a la lista.\n");
                break;
            }
            case 4: {
                printf("Opción seleccionada: Calcular el promedio de la lista\n");
                // Aquí iría el código para calcular el promedio de la lista
                break;
            }
            case 5: {
                printf("Opción seleccionada: Ver la lista en pantalla\n");
                mostrarLista(lista);
                break;
            }
            case 6: {
                printf("Opción seleccionada: Ordenar los promedios de mayor a menor\n");
                ordenarPromedios(lista);
                printf("La lista ha sido ordenada por promedios de mayor a menor.\n");
                break;
            }
            case 7: {
                printf("Opción seleccionada: Salir del menú\n");
                eliminarLista(lista);
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

