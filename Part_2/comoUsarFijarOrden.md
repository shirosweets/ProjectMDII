Ademas de lo dicho en el foro, puede haber quedado la duda de como puede usarse 
FijarOrden si luego de hacer FijarOrden una vez, lo que queda no es un orden.

Por eso en las especificaciones se dice que hay que usarla con cuidado.
Quizas diciendo como deberian usarla luego, se entienda mas ahora.

==================================================================================
La forma de usarla correctamente es hacer un for recorriendo todas las posiciones,
asegurandose que al final del for, lo que quede es un orden.
=================================================================================


Para cambiar el orden interno quizas se pueda tratar de ir cambiando el orden "in situ"
sin usar mas que O(1) memoria extra, pero al menos la vez que quise hacerlo me salio bastante engorroso y lento asi que conclui que el costo de velocidad era demasiado
comparado con el ahorro de memoria. (quizas alguno de ustedes lo pueda hacer en forma mas eficiente)

Lo mas eficiente parece ser usar O(n) memoria temporal extra
creando un array auxiliar, ordenando el array, y luego transfiriendo
los resultados a la estructura interna del grafo usando un for de FijarOrden.


En el arreglo auxiliar, pueden hacer dos cosas:

1) Hacer un arreglo auxiliar A tal que A[i] indique cual es el N del orden natural
que corresponde al vertice que debe ir en la posicion i del orden interno.

En ese caso, hay que hacer
```c++
u32 n = NumerodeVertices(G);
for(u32 i = 0; i < n; i++) {
    FijarOrden(i, G, A[i]);
}
```

2) Hacer un arreglo auxiliar B tal que B[N] indique en que lugar i del orden 
interno debe ir el vertice que tiene orden N en el orden natural.

En ese caso hay que hacer 
```c++
u32 n = NumerodeVertices(G);
for(u32 N = 0; N < n; N++) {
    FijarOrden(B[N], G, N);
}
```