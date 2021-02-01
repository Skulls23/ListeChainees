CC=g++
CXXFLAGS=-Wall -g

mainTemplate: mainTemplate.o

mainTemplate.o: listeTemplate.o

listeTemplate.o: listeTemplate.cpp listeTemplate.h

clean:
	rm -rf *.o 

mrproper: clean
	rm -rf mainTemplate