all: avlfreq

avlfreq: AVLTree.o
	g++ AVLTree.o -o avlfreq

AVLTree.o: AVLTree.cpp
	g++ -c -std=c++11 AVLTree.cpp

clean:
	rm *.o