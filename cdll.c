#include <stdio.h>
#include <stdlib.h>
#include "cdll.h"

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

void mostrarLista(CDLL* lista)
{
    if (lista->len == 0)
    {
        printf("La lista est� vac�a.\n");
        return;
    }

    Node* actual = lista->first;
    int i = 1;

    while (actual != NULL)
    {
        printf("Alumno %d:\n", i);
        printf("Nombre: %s\n", actual->alumno.nombre);
        printf("Apellido: %s\n", actual->alumno.apellido);
        printf("N�mero de cuenta: %d\n", actual->alumno.numeroCuenta);

        // Aqu� ir�a el c�digo para mostrar las calificaciones del alumno actual

        printf("\n");

        actual = actual->next;
        i++;
    }
}

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