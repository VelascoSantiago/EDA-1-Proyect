#ifndef CDLL_H
#define CDLL_H

#include "alumno.h"

/**
 * @file cdll.h
 * @brief Definiciones para la lista doblemente enlazada circular (CDLL).
 * 
 * Este archivo contiene la definición de estructuras y funciones para manejar 
 * una lista doblemente enlazada circular que almacena información de alumnos.
 */

/**
 * @struct Node
 * @brief Nodo de la lista doblemente enlazada circular.
 * 
 * Cada nodo almacena un alumno y tiene punteros al siguiente y al anterior nodo.
 */
typedef struct Node
{
    Alumno alumno;      /**< Información del alumno almacenado en el nodo */
    struct Node* next;  /**< Puntero al siguiente nodo en la lista */
    struct Node* prev;  /**< Puntero al nodo anterior en la lista */
} Node;

/**
 * @struct CDLL
 * @brief Lista doblemente enlazada circular.
 * 
 * Estructura que representa la lista, con punteros al primer, último nodo
 * y un cursor para facilitar las operaciones. También almacena el tamaño de la lista.
 */
typedef struct
{
    Node* first;   /**< Puntero al primer nodo de la lista */
    Node* last;    /**< Puntero al último nodo de la lista */
    Node* cursor;  /**< Puntero auxiliar para recorrer la lista */
    size_t len;    /**< Cantidad de nodos en la lista */
} CDLL;

/**
 * @brief Crea una lista vacía.
 * 
 * @return Un puntero a la lista creada o NULL si falla la asignación de memoria.
 * 
 * @post Se crea una lista en el heap con `first`, `last` y `cursor` en NULL y `len = 0`.
 */
CDLL* crearLista();

/**
 * @brief Agrega un nodo a la lista con la información de un alumno.
 * 
 * @param lista Puntero a la lista donde se agregará el nodo.
 * @param alumno Puntero al alumno que se insertará en la lista.
 * 
 * @post Se añade un nuevo nodo con la información del alumno al final de la lista.
 */
void agregarNodo(CDLL* lista, Alumno *alumno);

/**
 * @brief Ordena la lista de alumnos por promedio.
 * 
 * @param lista Puntero a la lista de alumnos.
 * 
 * @post La lista queda ordenada de menor a mayor promedio.
 */
void ordenarPromedios(CDLL* lista);

/**
 * @brief Calcula el promedio de un alumno.
 * 
 * @param alumno Estructura de tipo Alumno con las calificaciones a promediar.
 * @return El promedio de las calificaciones del alumno.
 */
double calcularPromedio(Alumno alumno);

/**
 * @brief Muestra la lista de alumnos en la consola.
 * 
 * @param lista Puntero a la lista a imprimir.
 * 
 * @post Se imprime en pantalla la información de los alumnos en la lista.
 */
void mostrarLista(CDLL* lista);

/**
 * @brief Elimina todos los nodos de la lista y libera la memoria.
 * 
 * @param lista Puntero a la lista que se eliminará.
 * 
 * @post La lista queda vacía y toda la memoria reservada es liberada.
 */
void eliminarLista(CDLL* lista);

/**
 * @brief Crea un alumno y lo añade a la lista.
 * 
 * @param lista Puntero a la lista donde se añadirá el alumno.
 * @param nombre Nombre del alumno.
 * @param apellido Apellido del alumno.
 * @param cuenta Número de cuenta del alumno.
 * @param calificaciones Arreglo con las calificaciones del alumno.
 * 
 * @post Se añade un nuevo nodo con la información del alumno a la lista.
 */
void añadir_Alumno(CDLL* lista, char nombre[], char apellido[], int cuenta, double calificaciones[]);

#endif  /* CDLL_H */

