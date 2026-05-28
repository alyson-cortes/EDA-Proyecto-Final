#ifndef CAMIONES_H
#define CAMIONES_H

#include "Aly_propuesta_estructuras.h" 
#include <stdio.h>
#include <stdlib.h>

// --- Estructura del Nodo para la Lista Circular ---
typedef struct NodoCamion {
    Camion dato;
    struct NodoCamion* siguiente;
} NodoCamion;

// --- Prototipos de las Funciones ---
void insertarCamion(NodoCamion** cabeza, Camion nuevoCamion);
void rotarCoches(NodoCamion** cabeza);

// Usamos void* para que el compilador no pida las definiciones exactas aquí
void asignarPaqueteACoche(void* cola, NodoCamion** camionActual, void* topePila);

#endif // CAMIONES_H