#ifndef ALUMNO_H
#define ALUMNO_H

/**
 * @file alumno.h
 * @brief Definición de la estructura Alumno.
 * 
 * Este archivo contiene la estructura que representa a un alumno,
 * incluyendo su nombre, apellido, número de cuenta y calificaciones.
 */

/**
 * @struct Alumno
 * @brief Representa a un estudiante con sus datos personales y académicos.
 * 
 * La estructura almacena el nombre, apellido, número de cuenta y 
 * un arreglo con sus calificaciones.
 */
typedef struct
{
    char nombre[50];         /**< Nombre del alumno */
    char apellido[50];       /**< Apellido del alumno */
    int numeroCuenta;        /**< Número de cuenta del alumno */
    double calificaciones[10]; /**< Arreglo con las calificaciones del alumno */
} Alumno;

#endif  /* ALUMNO_H */
