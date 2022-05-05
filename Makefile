CC = gcc
CFLAGS_F = $(CFLAGS)
CFLAGS = -Wall -Wextra -O3 -std=c99
OBJS_P1 = $(PATH_P1)main.o $(PATH_P1)RomaVictor.o $(PATH_P1)GrafoFunciones.o
VALGRIND = valgrind --leak-check=full --show-reachable=yes
PATH_P1 = Parte_1/Files/
PATH_P2 = Parte_2/

part1: small_graphs grafos_grandes k_grafos

part2: $(PATH_P1)RomaVictor.o $(PATH_P1)GrafoFunciones.o $(PATH_P2)gba_funciones.o $(PATH_P2)main2.o
		$(CC) $(CFLAGS) -o p_2 $(PATH_P1)RomaVictor.o $(PATH_P1)GrafoFunciones.o $(PATH_P2)gba_funciones.o $(PATH_P2)main2.o
		#./p_2 < SmallGraphs/Grafo_mas_chico.txt
		#./p_2 < SmallGraphs/Grafo_chico.txt
		#./p_2 < SmallGraphs/n=100_m=1470.txt
		#./p_2 < SmallGraphs/n=1010_m=60980.txt
		#./p_2 < SmallGraphs/n=169_m=3328.txt
		#./p_2 < SmallGraphs/n=3779_m=371357.txt
		#./p_2 < SmallGraphs/n=385_m=19095.txt
		#./p_2 < K_Grafos/K1000.txt
		#./p_2 < K_Grafos/K100.txt
		#./p_2 < K_Grafos/K500.txt
		#./p_2 < Grafos_grandes/Bipartito.txt
		#./p_2 < Grafos_grandes/Grafo_aleatorio.txt
		#./p_2 < Grafos_grandes/Grafo_comprimido.txt
		#./p_2 < Grafos_grandes/n=2210104_m=8807410.txt
		#./p_2 < Grafos_grandes/n=221651_m=12528006.txt
		#./p_2 < Grafos_grandes/n=23658_m=5586907.txt
		#./p_2 < Grafos_grandes/n=3080_m=4m.txt


small_graphs: $(OBJS_P1)
		$(CC) $(CFLAGS) -o p_1 $(OBJS_P1)
		./p_1 < SmallGraphs/Grafo_mas_chico.txt
		#./p_1 < SmallGraphs/Grafo_chico.txt
		#./p_1 < SmallGraphs/n=100_m=1470.txt
		#./p_1 < SmallGraphs/n=1010_m=60980.txt
		#./p_1 < SmallGraphs/n=169_m=3328.txt
		#./p_1 < SmallGraphs/n=3779_m=371357.txt
		#./p_1 < SmallGraphs/n=385_m=19095.txt

k_grafos: $(OBJS_P1)
		$(CC) $(CFLAGS) -o p_1 $(OBJS_P1)
		./p_1 < K_Grafos/K1000.txt
		./p_1 < K_Grafos/K100.txt
		./p_1 < K_Grafos/K500.txt

grafos_grandes: $(OBJS_P1)
		$(CC) $(CFLAGS) -o p_1 $(OBJS_P1)
		#./p_1 < Grafos_grandes/Bipartito.txt
		#./p_1 < Grafos_grandes/Grafo_aleatorio.txt
		#./p_1 < Grafos_grandes/Grafo_comprimido.txt
		#./p_1 < Grafos_grandes/n=2210104_m=8807410.txt
		./p_1 < Grafos_grandes/n=221651_m=12528006.txt
		#./p_1 < Grafos_grandes/n=23658_m=5586907.txt
		#./p_1 < Grafos_grandes/n=3080_m=4m.txt

main.o:
		$(CC) $(CFLAGS) -c $(PATH_P1)main.c


GrafoFunciones.o: $(PATH_P1)GrafoSt21.h
		$(CC) $(CFLAGS) -c $(PATH_P1)GrafoFunciones.c

RomaVictor.o: $(PATH_P1)RomaVictor.h $(PATH_P1)GrafoSt21.h
		$(CC) $(CFLAGS) -c $(PATH_P1)RomaVictor.c

gba_funciones.o: $(PATH_P2)gba_funciones.h $(PATH_P1)RomaVictor.h
		$(CC) $(CFLAGS) -c $(PATH_P2)gba_funciones.c

main2.o:
		$(CC) $(CFLAGS) -c $(PATH_P2)main2.c

clean:
		rm $(OBJS_P1) $(PATH_P2)gba_funciones.o $(PATH_P2)main2.o p_1 p_2
