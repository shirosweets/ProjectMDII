#include "GrafoSt21.h"

Vertice add_vertice(Grafo G, u32 vertice_name){
    Vertice p_vertice = NULL;
    u32 n = G->c_vertices;
    u32 index_vertice = vertice_name % n;    // Obtenemos un index del vertice
    u32 i = 0;

    /* Casos del while*/
    /* Puede ser que el vertice exista, con lo cual solo hay que pasarle la direccion de memoria del vertice */
    /* Puede ser que haya que cambiarle el index al vertice, porque colisiono con el index de otro,
    se cambia hasta encontrar el vertice o hasta encontrarle un lugar libre*/
    /* i nunca podria llegar a ser n, si llega a n hay una mala carga de datos, ya que un vertice
        no encontró su posicion */
    while( G->vertices_usados[index_vertice] && i < n ) {
        i++;
        if (G->vertices[index_vertice].nombre == vertice_name) {
            p_vertice = &G->vertices[index_vertice];
            i = 0;
            break;
        }
        else {
            index_vertice++;
            if (index_vertice == n)
                index_vertice = 0;
        }
    }
    if(i == n){
        printf("Error en la carga de vertices");
        exit(-1);
    }

    /* Si el puntero sale del while siendo NULL, significa que encontro un lugar libre y agrega el vertice */
    if(p_vertice == NULL) {
        struct Vertice_t new_v = new_vertice(vertice_name);
        G->vertices[index_vertice] = new_v;
        p_vertice = &G->vertices[index_vertice];
        G->vertices_usados[index_vertice] = true;
        G->orden[index_vertice] = p_vertice;
        p_vertice->pos_orden = index_vertice;
        G->count++;
    }

    return p_vertice;
}

/*Crea un nuevo vertice inicializando su estructura*/
struct Vertice_t new_vertice(u32 vertice_name) {
    struct Vertice_t new_vertice;
	new_vertice.nombre = vertice_name;
	new_vertice.color = 0;
	new_vertice.grado = 0;
    new_vertice.capacidad = 1;
	new_vertice.vecinos = calloc(new_vertice.capacidad, sizeof(Vertice));
    return(new_vertice);
}

/* Añade el vecino del vertice a*/
void add_vecino(Vertice a, Vertice b, u32 ** pesos) {
    u32 grado = a->grado;
    if(grado == a->capacidad) {
        /* A medida que necesitamos mas memoria la agregamos */
		Vertice *vecinos;
        vecinos = realloc(a->vecinos, (a->capacidad + 1) *sizeof(Vertice));
        /* Este if es necesario para por la funcion copiar grafo*/
        if(pesos != NULL){
            u32 * p;
            p = realloc(pesos[a->pos_orden], (a->capacidad + 1) *sizeof(u32));
            pesos[a->pos_orden] = p;
        }
        a->capacidad = a->capacidad + 1;
		a->vecinos = vecinos;
    }
    a->vecinos[a->grado] = b;
    /* Este if es necesario para por la funcion copiar grafo*/
    if(pesos != NULL){
        pesos[a->pos_orden][a->grado] = 0;
    }
    a->grado++;
}

/* Libera la memoria allocada de los vecinos de un vertice*/
void DestruccionDelVertice(struct Vertice_t vertice){
    free(vertice.vecinos);
}

/* Obtiene el delta del grafo dado*/
u32 get_delta(Grafo G){
    u32 max = G->vertices[0].grado;
    for(u32 i = 1; i < G->c_vertices;i++){
        if (max < G->vertices[i].grado){
            max = G->vertices[i].grado;
        }
    }
    return max;
}


Vertice copy_vertice_new(Vertice p_vertice, Grafo New_G, u32 pos_orden){
    /* Si el vertice ya esta creado solo devuelve el puntero a ese vertice */
    if(New_G->vertices_usados[pos_orden] == true){
        Vertice p_vertice_new = NULL;
        p_vertice_new = New_G->orden[pos_orden];
        return p_vertice_new;
    }
    /* si el vertice no existe se crea */
    struct Vertice_t new_vertice;
    new_vertice.nombre = p_vertice->nombre;
	new_vertice.color = p_vertice->color;
	new_vertice.grado = p_vertice->grado;
    new_vertice.capacidad = p_vertice->capacidad;
    new_vertice.vecinos = calloc(p_vertice->grado, sizeof(Vertice));
    New_G->vertices[p_vertice->pos_orden] = new_vertice;
    Vertice p_vertice_new = NULL;
    p_vertice_new = &New_G->vertices[p_vertice->pos_orden];
    New_G->orden[p_vertice->pos_orden] = p_vertice_new;
    New_G->vertices_usados[pos_orden] = true;
    return p_vertice_new;
}

/* Funcion para printear cosas del grafo*/
void print_grafo(Grafo G){
    /*
    printf("Vertices_c : %lu || ",G->c_vertices);
    printf("Lados_c : %lu\n",G->c_lados);

    printf("Vertices : [");
    for(u32 i = 0; i < G->c_vertices-1; i++){
        printf(" %lu, ", G->vertices[i].nombre);
    }
    printf(" %lu]\n",G->vertices[G->c_vertices-1].nombre);
    for(u32 i = 0; i < G->c_vertices; i++){
        printf("Vertice: %lu -> Vecinos : [", G->vertices[i].nombre);
        for(u32 j = 0; j < G->vertices[i].grado; j++){
            printf(" %lu", G->vertices[i].vecinos[j]->nombre);
            if(G->vertices[i].grado -1 != j){
                printf(",");
            }
        }
        printf("]\n");
    }
    */
    printf("Orden: [");
    for(u32 i = 0; i < G->c_vertices-1; i++){
        printf(" %lu, ", G->orden[i]->nombre);
    }
    printf(" %lu]\n", G->orden[G->c_vertices - 1]->nombre);
    /*
    printf("Colores: [");
    for (u32 i = 0; i< G->c_vertices-1; i++){
        printf(" %lu, ", G->orden[i]->color);
    }
    printf(" %lu]\n", G->orden[G->c_vertices - 1]->color);

    printf("Pesos: \n");
    for(u32 i = 0; i < G->c_vertices; i++){
        for(u32 j = 0; j < G->orden[i]->grado; j++){
            printf(" [%lu<->%lu:%lu]", G->orden[i]->nombre, G->orden[i]->vecinos[j]->nombre, G->pesos[i][j]);
        }
        printf("\n");
    }
    */
}

/* Funcion para saltear los comentarios */
void saltear_c(FILE * f, char buffer[]){
    buffer[0] = 'c';
    while (buffer[0] == 'c'){
        if(fgets(buffer, 128, f) == NULL){
            printf("Error al aplicar fgets.");
            exit(-1);
        };
    }
}

bool goes_before (u32 i, u32 j){
    if (i <= j){
        return true;
    }else{
        return false;
    }
}

void swap(u32 * orden, u32 x, u32 y){
    u32 tmp = orden[x];
    orden[x] = orden[y];
    orden[y] = tmp;
}


u32 partition(u32 * orden, u32 izq, u32 der){
    u32 piv= izq;
    u32 i = izq+1;
    u32 j = der;
	while (goes_before(i,j)){
		if (goes_before(orden[i], orden[piv])){i=i+1;}
		else if (goes_before(orden[piv], orden[j])){j=j-1;}
		else if (goes_before(orden[piv], orden[i]) && (goes_before(orden[j], orden[piv]))){swap(orden, i, j);}
	}
	swap(orden,piv,j);
	piv = j;
	return piv;
}

void quick_sort_rec(u32 * orden, u32 izq, u32 der){
    u32 piv;
    if (der > izq){
        piv = partition(orden, izq, der);
        if (piv == 0){
            quick_sort_rec(orden, piv+1, der);
        }
        else{
            quick_sort_rec(orden, izq, piv-1);
            quick_sort_rec(orden, piv+1, der);
        }
    }
}

void quick_sort(u32 * orden, u32 length){
    quick_sort_rec(orden, 0, (length == 0) ? 0 : length - 1);
}
