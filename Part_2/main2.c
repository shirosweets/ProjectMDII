#include "gba_funciones.h"

static void mostrarGrafo(Grafo G){
    printf("\nGrafo G: ");
    print_grafo(G);
    printf("\n");
}

static void correrGreedy(Grafo G){
    printf("Greedy: %lu\n", Greedy(G));
}

static void correrAleatorizar(Grafo G){
    u32 alea1 = 20;
    printf("\nAleatorizar de %lu", alea1);
    AleatorizarVertices(G, alea1);

    //mostrarGrafo(G);
}

int main(){
    printf("dsfg");
    Grafo G = ConstruccionDelGrafo();  // Siempre queda
    //mostrarGrafo(G);
    // printf("dsfg");
    // for(u32 i = 0; i < NumeroDeVertices(G);i++){
    //     FijarOrden(i,G,i);
    // }
    // correrGreedy(G);
    //correrAleatorizar(G);
    DestruccionDelGrafo(G); // Siempre queda
    printf("\n");
    return 0;
}
