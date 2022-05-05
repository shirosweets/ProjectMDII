#include "RomaVictor.h"
#include <math.h>


Grafo ConstruccionDelGrafo(){
    /* Lectura del FILE hasta p edge */
    FILE * f = stdin;
    char buffer[128];
    saltear_c(f,buffer);
    if(buffer[0] != 'p'){
        printf("Formato de entrada invalido\n");
        exit(-1);
    }
    char p = ' ';
    char *edge = calloc(5,sizeof(char));
    u32 c_vertices = 0;
    u32 c_lados = 0;
    sscanf(buffer, "%c %s %lu %lu", &p, edge, &c_vertices, &c_lados);
    if (strncmp(edge, "edge", 4) != 0 && c_vertices >= 2 && c_lados >= 1) {
        printf("Formato de entrada invalido\n");
        exit(-1);
    }
    free(edge);

    /* Una vez llegado a este punto empezamos a dar memoria al grafo */
    Grafo G = NULL;
    G = malloc(1 * sizeof(struct GrafoSt));
    G->nombres = calloc(c_vertices,sizeof(u32));
    G->c_vertices = c_vertices;
    G->c_lados = c_lados;
    G->orden = calloc(c_vertices, sizeof(Vertice));
    G->vertices = calloc(c_vertices, sizeof(struct Vertice_t));
    G->vertices_usados = calloc(c_vertices, sizeof(bool));
    G->pesos = calloc(c_vertices, sizeof(u32 *));
    for(u32 i = 0; i < c_vertices; i++){
        G->vertices_usados[i] = false;
        G->pesos[i] = calloc(1, sizeof(u32));
    }

    /* Comenzamos a rellenar el Grafo */
    u32 extremo_a, extremo_b;           // Variables para leer el FILE (linea : e x y) x= extremo_a , y = extremo_b
    Vertice p_vertice_a = NULL;         // Punteros a Vertices
    Vertice p_vertice_b = NULL;
    G->count = 0;
    for (u32 i = 0; i < c_lados; i++) {
        if(fgets(buffer, 128, f) != NULL) {
            sscanf(buffer, "%c %lu %lu", &p, &extremo_a, &extremo_b);
            if (p != 'e') {
                printf("Lado mal puesto\n");
                DestruccionDelGrafo(G);
                return NULL;
            }
            else {
                p_vertice_a = add_vertice(G, extremo_a);
                p_vertice_b = add_vertice(G, extremo_b);
                add_vecino(p_vertice_a, p_vertice_b, G->pesos);
                add_vecino(p_vertice_b, p_vertice_a, G->pesos);
            }
        }
        else {
            printf("Formato de entrada invalido\n");
            DestruccionDelGrafo(G);
            return NULL;
        }
    }
    for(u32 i = 0; i < G->c_vertices; i++){
        G->orden[i]->color = i;
        G->nombres[i] = G->orden[i]->nombre;
    }
    G->delta = get_delta(G);
    return G;
}

void DestruccionDelGrafo(Grafo G){
    for(u32 i = 0; i < G->count; i++){
        DestruccionDelVertice(G->vertices[i]);
    }
    for(u32 i = 0; i < G->c_vertices; i++){
        free(G->pesos[i]);
    }
    free(G->pesos);
    free(G->vertices);
    free(G->vertices_usados);
    free(G->orden);
    free(G);
}

Grafo CopiarGrafo(Grafo G){
    /* Alocamos memoria para el Nuevo Grafo */
    Grafo New_G = NULL;
    New_G = malloc(1 * sizeof(struct GrafoSt));
    New_G->c_vertices = NumeroDeVertices(G);
    New_G->c_lados = NumeroDeLados(G);
    New_G->delta = Delta(G);
    New_G->count = G->count;
    New_G->orden = calloc(New_G->c_vertices, sizeof(Vertice));
    New_G->vertices = calloc(New_G->c_vertices, sizeof(struct Vertice_t));
    New_G->vertices_usados = calloc(New_G->c_vertices, sizeof(bool));
    New_G->pesos = NULL;
    /* Empezamos a copiar el Grafo al Nuevo Grafo */
    Vertice p_vertice_a = NULL;         // Punteros a Vertices
    Vertice p_vertice_b = NULL;
    for (u32 i = 0; i < G->c_vertices; i++) {
        p_vertice_a = copy_vertice_new(G->orden[i],New_G,i);
        /* Agregamos los vecinos a cada vertice */
        for(u32 j = 0; j < G->orden[i]->grado; j++){
            p_vertice_b = copy_vertice_new(G->orden[i]->vecinos[j], New_G, G->orden[i]->vecinos[j]->pos_orden);
            p_vertice_a->vecinos[j] = p_vertice_b;
        }
    }
    /* Copiamos la Matriz Peso */
    New_G->pesos = calloc(New_G->c_vertices, sizeof(u32 *));
    for(u32 i = 0; i < G->c_vertices; i++){
        New_G->pesos[i] = calloc(New_G->orden[i]->grado, sizeof(u32));
        for(u32 j = 0; j < G->orden[i]->grado; j++){
            New_G->pesos[i][j] = G->pesos[i][j];
        }
    }
    return New_G;
}

u32 NumeroDeVertices(Grafo G){
    return (G->c_vertices);
}

u32 NumeroDeLados(Grafo G){
    return (G->c_lados);
}

u32 Delta(Grafo G){
    return (G->delta);
}

u32 Nombre(u32 i, Grafo G){
    return (G->orden[i]->nombre);
}

u32 Color(u32 i, Grafo G){
    if(i >= G->c_vertices){
        return (u32)((pow(2,32))-1);
    }
    return G->orden[i]->color;
}

u32 Grado(u32 i, Grafo G){
    if(i >= G->c_vertices){
        return (u32)(pow(2,32) - 1);
    }
    return G->orden[i]->grado;
}

u32 ColorVecino(u32 j, u32 i, Grafo G){
    if(i >= G->c_vertices || j >= G->orden[i]->grado){
        return (u32)((pow(2,32))-1);
    }
    return (G->orden[i]->vecinos[j]->color);
}

u32 NombreVecino(u32 j, u32 i, Grafo G){
    return (G->orden[i]->vecinos[j]->nombre);
}

u32 OrdenVecino(u32 j, u32 i, Grafo G){
    u32 k = 0;
    for(u32 r = 0; r < G->c_vertices; r++){
        if(G->orden[i]->vecinos[j]->nombre == G->orden[r]->nombre){
            k = r;
            break;
        }
    }
    return k;
}

u32 PesoLadoConVecino(u32 j, u32 i, Grafo G){
    return G->pesos[i][j];
}

char FijarColor(u32 x, u32 i, Grafo G){
    if(i < G->c_vertices){
        G->orden[i]->color = x;
        return 0;
    }
    else{
        return 1;
    }
}

char FijarOrden(u32 i, Grafo G, u32 N){
    if(i < G->c_vertices && N < G->c_vertices){
        quick_sort(G->nombres,G->c_vertices);
        // for(u32 j = 0; j<G->c_vertices; j++){
        //     printf("%lu-",G->nombres[j]);
        // }
        return 0;
    }
    else{
        return 1;
    }
}

u32 FijarPesoLadoConVecino(u32 j, u32 i, u32 p, Grafo G){
    G->pesos[i][j] = p;
    return 0;
}
