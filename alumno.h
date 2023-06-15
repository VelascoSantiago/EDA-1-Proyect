#ifndef ALUMNO_H
#define ALUMNO_H

typedef struct
{
    char nombre[50];
    char apellido[50];
    int numeroCuenta;
    double calificaciones[3];
} Alumno;

#endif  /* ALUMNO_H */
