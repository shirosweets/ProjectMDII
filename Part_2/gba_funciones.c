#include "gba_funciones.h"

// static void swapFijarOrden(u32 i, Grafo G, u32 j){
//     FijarOrden(i, G, j);
//     FijarOrden(j, G, i);
// }

u32 Greedy(Grafo G){
    //printf("\n\nDentro de Greedy\n");
    u32 n = NumeroDeVertices(G);
    u32 mejor_color = 0;  // color a darle al vértice.

    // k será la cantidad de colores utilizados hasta el momento.
    // Se inicializa en 2 para tener la posicion 0 y 1. La 0 la ignoramos.
    u32 k = 2;

    // primero setear todos los colores de los vertices a 0.
    for (u32 i = 0; i < n; i++){
        FijarColor(0,i,G);
    }
    // print_grafo(G);

    for (u32 i = 0; i < n; i++){
        /* Pido los colores de los vecinos del vertice i y lo guardo en un
        arreglo de tamaño k, con k cantidad de colores usados hasta el momento.*/
        //printf("elemento = %lu\n", Nombre(i,G));
        u32 cantidad_vecinos = Grado(i,G);
        //printf("cantidad_vecinos = %lu\n", cantidad_vecinos);

        // creo el array para guardar los colores.
        u32 colores_vecinos[k];

        // seteo los elementos del arreglo en cero.
        for (u32 a = 0; a < k; a++){
            colores_vecinos[a] = 0;
        }

        // pido y guardo el color del vecino j del vertice i.
        for (u32 j = 0; j < cantidad_vecinos; j++){
            colores_vecinos[ColorVecino(j,i,G)] = 1;
        }

        //printf("Lista de colores de los vecinos\n [ ");
        for (u32 q = 0; q < k; q++){
            //printf("%lu ", colores_vecinos[q]);
        }
        //printf("]\n*******************\n");

        /*  ahora el color a pintar va a ser la posicion del primer
        elemento = 0 del arreglo. Omitiendo la posicion 0. */
        u32 j = 1;
        bool flag = true;
        while (j < k && flag){
            if (colores_vecinos[j] == 0){
                mejor_color = j;
                flag = false;
            }
            else{
                j++;
            }
        }

        /*
        En éste punto si flag = false quiere decir que se encontro el mejor color, por lo tanto coloramos
        el vertice i con dicho color.
        Por el contrario si flag = true, indica que no se encontro, por lo tanto necesitamos un color nuevo
        (k+1).
        */

        if(!flag){
            // en éste punto ya podemos colorear el vértice i con el mejor_color.
            //printf("coloreamos el vertice %lu con %lu\n\n", i, mejor_color);
            FijarColor(mejor_color,i,G);
        }
        else{
            //printf("ELSE: coloreamos el vertice %lu con %lu\n\n", i, k);
            FijarColor(k,i,G);
            k++;
        }
    }

    /*
    Como k lo inicializamos en 2, le restamos 1 que sobra, (la posicion 0)
    */
    return k-1;
}

char AleatorizarVertices(Grafo G,u32 semilla){
    u32 c_vertices = NumeroDeVertices(G);
    u32 position = 0;
    // Cambiamos el orden a natural
    for(u32 i = 0; i < c_vertices; i++){
        FijarOrden(i, G, i);
    }
    srand(semilla); // Para que con cada semilla de los mismos resultados
    bool *pos_usados = calloc(c_vertices,sizeof(bool));
    for (u32 i = 0; i < c_vertices; i++){
        pos_usados[i] = false;
    }
    for (u32 i = 0; i < c_vertices ; i++){
        position = rand();
        position = position % c_vertices;
        if(pos_usados[position] == false){
            pos_usados[position] = true;
            FijarOrden(i,G,position);
        }
        else{
            u32 count = 0;
            u32 j = position;
            while(pos_usados[j] == true && count < c_vertices){
                j++;
                if(j == c_vertices){
                    j = 0;
                }
                count++;
                if(count == c_vertices){
                    printf("error");
                    return '1';
                }
            }
            pos_usados[j] = true;
            FijarOrden(i,G,j);
        }
    }
    return '0';
}