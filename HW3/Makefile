all: main

heapsort: heapsort.o heap.o
	g++ heapsort.o heap.o -o heapsort

heapsort.o: heapsort.cpp
	g++ -c -std=c++11 heapsort.cpp

heap.o: heap.cpp
	g++ -c -std=c++11 heap.cpp

clean:
	rm *.o heapsort 