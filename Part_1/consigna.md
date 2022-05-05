# Proyecto de Matemática Discreta II-2021-Primera Parte

# Contenido
- [1- Introducción]()</p>
    - [1.1- Entrega](#1.1-entrega)</p>
    - [1.2- Restricciones generales](#1.2-restricciones-generales)</p>
    - [1.3- Formato de Entrega](#1.3-formato-de-entrega)</p>
- [2- Tipos de datos]()</p>
- [3- ]()</p>
- [4- ]()</p>
- [5- ]()</p>
- [6- ]()</p>
- [7- ]()</p>
- [8- Funciones para modificar datos de los vértices](#8-funciones-para-modificar-datos-de-los-vértices)</p>
- [9- Consideraciones finales para esta primera etapa](#9-consideraciones-finales-para-esta-primera-etapa)</p>


## 1.1 Entrega
Deben entregar vı́a e-mail a daniel.penazzi arroba unc.edu.ar los archivos que implementan el proyecto.
Las funciones que estan descriptas en esta etapa serán usadas luego por otras funciones que especificaremos mas adelante.
En esta etapa las funciones consisten basicamente en las funciones que permiten leer los datos de un grafo y cargarlos en una
estructura adecuada, mas funciones que permiten manipular esos datos.

## 1.2 Restricciones generales
1. No se puede incluir NINGUNA libreria externa que no sea una de las básicas de C. (eg, stdlib.h, stdio.h, strings.h,
stdbool.h, assert.h etc, si, pero otras no. Especificamente, glibc NO).
2. El código debe ser razonablemente portable, aunque no tengo acceso a un sistema de Apple, y en general lo testearé
con Linux, puedo tambien testearlo desde Windows.
3. No pueden usar archivos llamados aux.c o aux.h
4. No pueden tener archivos tales que la unica diferencia en su nombre sea diferencia en la capitalización.
5. No pueden usar getline.
6. El uso de macros esta permitido pero como siempre, sean cuidadosos si los usan.
7. Pueden consultar con otros grupos, pero si vemos copiado de grandes fragmentos de código la van a pasar mal, espe-
cialmente si descubrimos intento de engañarnos haciendo cambios cosméticos en el código de otro grupo.
8. En años anteriores se les pedia entregar todas las funciones juntas, estas mas algunas de las que pediremos en otras
etapas, lo cual hacia que los grupos pudieran usar en algunas funciones la estructura interna del grafo tal como estaba
guardado, en vez de hacer un llamado a las funciones auxiliares correspondientes. Algunos grupos tomaban ventaja de
esto creando una estructura interna del grafo con campos auxiliares extras que les permitia correr las otras funciones
mas rapidamente, y eso estaba bien en esos años. Este año uds. podrán hacer eso con las funciones de esta etapa, pero
no con las funciones de las siguientes etapas: las funciones de las siguientes etapas deberán ser programadas de forma
tal de usar las funciones de esta primera etapa, llamandolas, pero no pudiendo acceder a la estructura interna del grafo.
2Nos aseguraremos de esto ademas de obviamente leyendo el código, testeando las funciones de las etapas posteriores
con nuestras funciones de esta primera etapa, no con las suyas.
Una consecuencia que tiene esto es que si detectamos en su estructura campos que no son necesarios pero que podrı́an
ser utiles para posibles funciones extras no listadas en este documento que los quisieran acceder, supondremos que en
realidad copiaron el código de alguna función similar de años anteriores. No está mal usar códigos anteriores como
referencias, lo que está mal es copiarlos en bloque sin entenderlos, y si dejan un bloque de código que no tiene sentido
en 2021, asumiremos que no entienden el código que entregaron.

## 1.3 Formato de Entrega
Los archivos del programa deben ser todos archivos .c o .h.</p>
No debe haber ningun ejecutable.</p>
Los .c que entreguen deben hacer un include de un archivo RomaVictor.h donde se declaran las funciones y, obviamente,
de cualquier otro .h que uds necesiten, los cuales deben ser entregados.</p>
RomaVictor.h debe tener simplemente la declaración de las funciones, la declaración del tipo de datos 2.3 definida mas
abajo y un include de otro .h, GrafoSt21.h que es donde pueden poner cosas extras si quieren, incluyendo los dos primeros
tipos de datos de la sección 2
Para evitar errores de tipeo con las declaraciones de las funciones, subiremos una copia de RomaVictor.h a la página del
Aula Virtual.</p>
Para testear deberán hacer por su cuenta uno o mas .c que incluyan un main que les ayude a testear sus funciones,
incluyendo funciones nuevas que ustedes quieran usar para testear cosas. Estos archivos NO deben ser entregados.
El mail de entrega debe ser hecho con copia a los demas integrantes del grupo, pero ademas deben adjuntar un archivo
ASCII donde conste el nombre, apellido y email de todos los integrantes del grupo.</p>

# 8 Funciones para modificar datos de los vértices
## 8.1 FijarColor()
Prototipo de función:
char FijarColor(u32 x,u32 i,Grafo G);
Si i es menor que el número de vértices, le asigna el color x al vértice número i en el orden guardado en ese momento en
G y retorna 0.
De lo contrario, retorna 1.
Esta función debe ser usada con cuidado pues puede provocar que queden colores no asignados a ningún vértice (pej,
dando un coloreo con colores 0,1,4,7)

## 8.2 FijarOrden()
Prototipo de función:
char FijarOrden(u32 i,Grafo G,u32 N);
Si i y N son menores que el número de vértices, fija que el vértice i en el orden guardado en G será el N -ésimo vértice
del orden “natural”(el que se obtiene al ordenar los vértices en orden creciente de sus “nombres” reales) y retorna 0. De lo
contrario retorna 1.
Esta función debe ser usada con cuidado pues puede provocar que quede un orden interno que no sea un orden de todos
los vértices o que haya vértices repetidos en el orden.

## 8.3 FijarPesoLadoConVecino()
Prototipo de función:
u32 FijarPesoLadoConVecino(u32 j,u32 i,u32 p,Grafo G);
Hace que el lado formado por el i-ésimo vértice de G en el orden interno con el j-ésimo vecino de ese vértice tenga peso p.

# 9 Consideraciones finales para esta primera etapa
En esta etapa, la mayoria de las funciones son muy fáciles si piensan primero bien la estructura con la cual van a cargar el
grafo.
Las cosas mas dificiles de esta primera etapa son:
• Definir la estructura en forma adecuada.
• Programar en forma eficiente la construcción del grafo. Algunos grafos tendrán millones de vértices, por lo tanto una
construcción que sea O(n 2 ) no terminará de cargar el grafo en ningún tiempo razonable.
• Copiar el grafo. Es algo que parece obvio como hacerlo pero en otros años algunos alumnos se las han arreglado para
hacerlo muy mal.
• FijarOrden. No por la función en si, sino porque muchos malinterpretan lo que dice por no leer las especificaciones
adecuadamente.