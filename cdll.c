#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cdll.h"


/**
 * @brief Crea la lista de alumnos.
 *
 * @post Una lista existente en el heap.
 *
 */
CDLL* crearLista()
{
    CDLL* lista = (CDLL*)malloc(sizeof(CDLL));
    if (lista == NULL)
    {
        printf("Error: No se pudo asignar memoria para la lista.\n");
        return NULL;
    }

    lista->first = NULL;
    lista->last = NULL;
    lista->cursor = NULL;
    lista->len = 0;

    return lista;
}

/**
 * @brief Agrega un nodo a la lista.
 *
 * @param lista Una referencia a la lista.
 * @param item El nodo a colocar.
 *
 * @post Coloca al cursor en el nuevo nodo.
 *
 */
void agregarNodo(CDLL* lista, Alumno* alumno)
{
    Node* nuevoNodo = (Node*)malloc(sizeof(Node));
    if (nuevoNodo == NULL)
    {
        printf("Error: No se pudo asignar memoria para el nuevo nodo.\n");
        return;
    }

    nuevoNodo->alumno = *alumno;
    nuevoNodo->next = NULL;
    nuevoNodo->prev = NULL;

    if (lista->first == NULL)
    {
        lista->first = nuevoNodo;
        lista->last = nuevoNodo;
    }
    else
    {
        nuevoNodo->prev = lista->last;
        lista->last->next = nuevoNodo;
        lista->last = nuevoNodo;
    }

    lista->len++;
}

 /**
* @brief Ordena la lista en orden de promedios.
*
* @param lista Una referencia a la lista.
*
* @post La lista queda ordenada según lo que se pidió.
*
*/

 
void ordenarPromedios(CDLL* lista)
{
    Node* actual = lista->first;
    int swapped;

    if (actual == NULL)
        return;

    do {
        swapped = 0;
        actual = lista->first;

        while (actual->next != NULL) {
            double promedio_actual = calcularPromedio(actual->alumno);
            double promedio_siguiente = calcularPromedio(actual->next->alumno);

            if (promedio_actual < promedio_siguiente) {
                Alumno temp = actual->alumno;
                actual->alumno = actual->next->alumno;
                actual->next->alumno = temp;
                swapped = 1;
            }

            actual = actual->next;
        }
    } while (swapped);
}

/**
 * @brief Agrega un nodo a la lista.
 *
 * @param alumno El alumno del que se obtendra el promedio.
 *
 * @return El promedio del alumno.
 *
 */
double calcularPromedio(Alumno alumno)
{
    double suma = 0.0;
    for (int i = 0; i < 3; i++) {
        suma += alumno.calificaciones[i];
    }
    return suma / 3.0;
}

/**
 * @brief Muestra la lista en pantalla.
 *
 * @param lista Una referencia a la lista que se mostrará.
 *
 */
void mostrarLista(CDLL* lista)
{
    if ( NULL == lista )
    {
        printf( "La lista no existe\n" );
        return;
    }
    printf( "\tNombre\t\t\t\tApellido\t\t\tNo. de cuenta\t\t\t\tPromedio\n");

    Node* actual = lista->first;
    int i = 1;

    while (actual != NULL)
    {
        printf("%d\t", i);
        printf("%s\t\t\t\t", actual->alumno.nombre);
        printf("%s\t\t\t", actual->alumno.apellido);
        printf("%d\t\t\t\t", actual->alumno.numeroCuenta);
        printf("%.2lf", calcularPromedio(actual->alumno));

        printf("\n");

        actual = actual->next;
        i++;
    }
}

/**
 * @brief Destruye una lista.
 *
 * @param lista Una lista.
 */
void eliminarLista(CDLL* lista)
{
    Node* actual = lista->first;
    Node* siguiente;

    while (actual != NULL)
    {
        siguiente = actual->next;
        free(actual);
        actual = siguiente;
    }

    free(lista);
}

/**
 * @brief Agrega un alumno a la lista
 *
 * @param lista Una referencia a la lista
 * @param nombre El nombre del alumno
 * @param apellido El apellido del alumno
 * @param cuenta El número de cuenta del alumno
 * @param calificaciones Las calificaciones del alumno
 *
 * @post Un alumno nuevo en la lista
 *
 */
void añadir_Alumno(CDLL* lista, char nombre[], char apellido[], int cuenta, double calificaciones[])
{

    Alumno* alumno = ( Alumno* ) malloc ( sizeof ( Alumno ) );
    strncpy(alumno->nombre, nombre, 50);
    strncpy(alumno->apellido, apellido, 50);
    alumno->numeroCuenta = cuenta;
    int i;
    for( i = 0; i < 3; i++)
    {
        alumno->calificaciones[i] = calificaciones[i];
    }  

    agregarNodo(lista, alumno);
    printf("Se ha agregado al alumno a la lista.\n");
}