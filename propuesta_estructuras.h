#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

typedef struct {
    int id;               
    char destino[100];    
    float peso_kg;         
} Paquete;

typedef struct {
    int id;                
    float capacidad_kg;    
    float carga_actual_kg; 
} Camion;

#endif
