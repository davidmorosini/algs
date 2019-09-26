test: test.o linkedlist.o
	gcc test.o linkedlist.o -o test 

grafos: grafos.o linkedlist.o graph.o
	gcc grafos.o linkedlist.o graph.o -o grafos

linkedlist.o: utils/linkedlist.c
	gcc -c utils/linkedlist.c

graph.o: utils/graph.c
	gcc -c utils/graph.c

test.o: test.c
	gcc -c test.c

grafos.o: grafos.c
	gcc -c grafos.c

clean:
	rm -rf *.o
