target: coord.o readin.o assignment4.o      
	gcc -g -o target coord.o readin.o assignment4.o -lm
coord.o: coord.c coord.h
	gcc -g -c coord.c
readin.o: readin.c
	gcc -g -c readin.c
assignment4.o: assignment4.c coord.h
	gcc -g -c assignment4.c
