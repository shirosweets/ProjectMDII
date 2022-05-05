#ifndef GBA_FUNCIONES_H_
#define GBA_FUNCIONES_H_

#include "../Parte_1/Files/RomaVictor.h"

/* Devuelve el número de colores que se obtiene.*/
u32 Greedy(Grafo G);
/* “Aleatoriza” el orden de los vértices de G, usando como semilla de aleatoridad el número R.Retorna 0 si todo anduvo bien y 1 si hubo algún problema. */
char AleatorizarVertices(Grafo G, u32 semilla);

#endif /* GBA_FUNCIONES_H_ */