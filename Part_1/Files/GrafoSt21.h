#ifndef GRAFO_ST21_H_
#define GRAFO_ST21_H_

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

typedef unsigned long u32;
typedef struct Vertice_t  *Vertice;
typedef struct GrafoSt *Grafo;

struct Vertice_t {
    u32 nombre;             // Nombre del vertice
    u32 grado;              // Grado del vertice
    u32 color;              // Color del vertice
    u32 pos_orden;          // Variable para saber la posicion que tiene el vertice en el orden de G
    u32 capacidad;          // Capacidad de espacio para vecinos
    Vertice *vecinos;       // Arreglo de Vecinos del vertice que son punteros a Vertices
};

struct GrafoSt {
    u32 * nombres;
    u32 c_vertices;                 // Cantidad de Vertices
    u32 c_lados;                    // Cantidad de Lados
    u32 delta;                      // Delta del Grafo
    u32 count;                      // Contador para destruir correctamente el grafo en caso de mal formato de entrada
    u32 **pesos;                    // Matriz para guardar los pesos de los lados
    Vertice * orden;                // Arreglo de punteros a vertices para el orden
    struct Vertice_t * vertices;    // Arreglo de n vertices
    bool * vertices_usados;         // Necesario para darle un index adecuado al vertice
};


/* Saltea las lineas con primer char c */
void saltear_c(FILE * f, char buffer[]);

/* Funciones para la creacion del grafo */

/* Añade un vertice al Grafo y devuelve un puntero a Vertice (Necesario para add_vecino)*/
Vertice add_vertice(Grafo G, u32 vertice);

/* Crea un nuevo vertice */
struct Vertice_t new_vertice(u32 vertice_name);

/* Añade al vertice a el vecino b (tambien se añade el peso,
    pero como son todos nulos no lo tomamos en cuenta,
    simplemente le ponemos peso nulo)*/
void add_vecino(Vertice a, Vertice b, u32 ** pesos);

/* Libera memoria de un vertice */
void DestruccionDelVertice(struct Vertice_t vertice);

/* Calcula el delta de un Grafo*/
u32 get_delta(Grafo G);

/* Devuelve un puntero a vertice, correspondiente con la posicion i en el orden de G pero adaptado al New_G */
Vertice copy_vertice_new(Vertice p_vertice, Grafo New_G, u32 i);

/* Debugeo */
void print_grafo(Grafo G);

/* Para ordenar un arreglo*/

/* Verifica que i sea menor o igual que j*/
bool goes_before (u32 i, u32 j);

/* Realiza un intercambio entre x e y en el arreglo*/
void swap(u32 * orden, u32 x, u32 y);

/* Obtiene el pivot */
u32 partition(u32 * orden, u32 izq, u32 der);

/* Recursion del aloritmo quick_sort */
void quick_sort_rec(u32 * orden, u32 izq, u32 der);

/* Algoritmo de ordenacion rapida */
void quick_sort(u32 * orden, u32 length);

#endif /* GRAFO_ST21_H_*/