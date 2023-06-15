#ifndef CDLL_H
#define CDLL_H

#include "alumno.h"

typedef struct Node
{
    Alumno alumno;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct
{
    Node* first;
    Node* last;
    Node* cursor;
    size_t len;
} CDLL;

CDLL* crearLista();
void agregarNodo(CDLL* lista, Alumno alumno);
void ordenarPromedios(CDLL* lista);
double calcularPromedio(Alumno alumno);
void mostrarLista(CDLL* lista);
void eliminarLista(CDLL* lista);
void añadir_Alumno(CDLL* lista, char nombre[], char apellido[], int cuenta, double calificaciones[]);

#endif  /* CDLL_H */

