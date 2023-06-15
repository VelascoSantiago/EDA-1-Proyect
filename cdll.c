#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cdll.h"


/**
 * @brief Crea la lista de alumnos
 *
 * @post Una lista existente en el heap
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
 * @brief Agrega un nodo a la lista
 *
 * @param lista Una referencia a la lista
 * @param item El nodo a colocar
 *
 * @post Coloca al cursor en el nuevo nodo
 *
 */
void agregarNodo(CDLL* lista, Alumno alumno)
{
    Node* nuevoNodo = (Node*)malloc(sizeof(Node));
    if (nuevoNodo == NULL)
    {
        printf("Error: No se pudo asignar memoria para el nuevo nodo.\n");
        return;
    }

    nuevoNodo->alumno = alumno;
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

double calcularPromedio(Alumno alumno)
{
    // Aqu� ir�a el c�digo para calcular el promedio del alumno actual
    return 0.0;
}

/**
 * @brief Muestra la lista en pantalla
 *
 * @param lista Una referencia a la lista que se mostrará
 *
 */
void mostrarLista(CDLL* lista)
{
    printf( "\tNombre\t\t\tApellido\t\t\tNo. de cuenta\n");

    Node* actual = lista->first;
    int i = 1;

    while (actual != NULL)
    {
        printf("%d\t", i);
        printf("%s\t\t\t", actual->alumno.nombre);
        printf("%s\t\t\t", actual->alumno.apellido);
        printf("%d", actual->alumno.numeroCuenta);

        // Aqu� ir�a el c�digo para mostrar las calificaciones del alumno actual

        printf("\n");

        actual = actual->next;
        i++;
    }
}

/**
 * @brief Destruye una lista.
 *
 * @param this Una lista.
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

void ordenarPromedios(CDLL* lista)
{
    // Aqu� ir�a el c�digo para ordenar los promedios de mayor a menor
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
    Alumno alumno;
    strncpy(alumno.nombre, nombre, 50);
    strncpy(alumno.apellido, apellido, 50);
    alumno.numeroCuenta = cuenta;
    int i;
    for( i = 0; i < 3; i++)
    {
        alumno.calificaciones[i] = calificaciones[i];
    }  

    agregarNodo(lista, alumno);
    printf("Se ha agregado al alumno a la lista.\n");
}