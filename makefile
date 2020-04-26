grade : main.c base.o extras.o
	gcc -o grade main.c base.o extras.o 

base.o : base.c base.h
	gcc -o base.o -c base.c

extas.o : extras.c extras.h
	gcc -o extras.o -c extras.c

clean :
	rm *.o 
