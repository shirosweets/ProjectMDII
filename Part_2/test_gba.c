#include "gba_funciones.h"

bool test_all(){
    bool * array_func[2] = {true, true, array_func[2] = test_AleatorizarVertices()};
    for(int i = 0; i<length(array_func)-1; i++){
        if(array_func[i] == false){
            printf("\nNo pasaron todos los tests...");
            return false;
        }
    }
    printf("\nPasaron todos los tests...");
    return true;
}

bool test_AleatorizarVertices(){
    Grafo G = ConstruccionDelGrafo();

    char in1 = AleatorizarVertices(G, 10);
    char in2 = AleatorizarVertices(G, 10);

    char in3 = AleatorizarVertices(G, 2);
    char in4 = AleatorizarVertices(G, 2);

    DestruccionDelGrafo(G);

    return (in1 == in2 && in3 == in4);
}
