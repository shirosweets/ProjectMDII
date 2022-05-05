#include "RomaVictor.h"

int main(){
    Grafo G = ConstruccionDelGrafo();
    if (G == NULL){
        return 0;
    }
    //print_grafo(G);
    //for(u32 i = 0; i < NumeroDeVertices(G); i++){
        FijarOrden(0,G,0);
    //}
    //print_grafo(G);
    DestruccionDelGrafo(G);

    /*
    printf("\n--------------------------------------------------\n");
    printf(">>>> Inicio del programa n_n\n");

    printf("Construir el Grafo G...\n");
    Grafo G = ConstruccionDelGrafo();
    if (G == NULL){
        return 0;
    }
    printf("G nro vert: %lu\n", NumeroDeVertices(G));
    printf("G nro lados: %lu\n", NumeroDeLados(G));
    printf("Grafo G:\n");
    print_grafo(G);

    
    printf("Fijar pesos con los vecinos...\n");
    for(u32 i = 0; i < G->c_vertices; i++){
        for(u32 j = 0; j < G->orden[i]->grado; j++){
            FijarPesoLadoConVecino(j, i, i, G);
        }
    }
    printf("Comprobamos los pesos...");
    print_grafo(G);
    
    printf("Copiamos el grafo G en New_G\n");
    Grafo New_G = CopiarGrafo(G);
    printf("New_G nro vert: %lu\n", NumeroDeVertices(New_G));
    printf("New_G nro lados: %lu\n", NumeroDeLados(New_G));
    printf("Grafo New_G:\n");
    print_grafo(New_G);

    printf("Fijamos colores...");
    for(u32 i = 0; i < G->c_vertices; i++){
        FijarColor(i, i, G);
    }
    printf("Grafo G:\n");
    print_grafo(G);

    printf("\nfijarOrden\n");
    u32 num1 = 2;
    u32 num2 = 8;
    FijarOrden(num1, G, num2);
    printf("\nFijarOrden(%lu, G, %lu)\n", num1, num2);
    printf("Grafo G:\n");
    print_grafo(G);

    printf("\n--------------------------------------------------\n");

    printf("nro vert: %lu\n", NumeroDeVertices(G));
    printf("nro lados: %lu\n", NumeroDeLados(G));
    printf("Delta: %lu\n", Delta(G));
    printf("Color vert nro 3: %lu\n", Color(2,G));
    printf("Grado del vert nro 7: %lu\n", Grado(6,G));
    printf("Nombre de vecino nro 3 del vertice nro 1: %lu\n", NombreVecino(2,0,G));
    printf("Orden del vecino nro 3 del vertice nro 1: %lu\n", OrdenVecino(2,0,G));

    printf("Destrucción del Grafo New_G...\n");
    DestruccionDelGrafo(New_G);
    printf("Destrucción del Grafo G...\n");
    DestruccionDelGrafo(G);
    printf(">>>> Fin programa n_n");
    printf("\n--------------------------------------------------\n");

    */
    return 0;
}


