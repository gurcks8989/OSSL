grade : main.c base.o extras.o
<<<<<<< HEAD
	gcc -o grade main.c base.o extras.o 
=======
	gcc -o grade main.c base.o extras.o
>>>>>>> f24d865cea2cec325d50a88d653cbbf738b5b35c

base.o : base.c base.h
	gcc -o base.o -c base.c

extas.o : extras.c extras.h
	gcc -o extras.o -c extras.c

clean :
<<<<<<< HEAD
	rm *.o 
=======
	rm *.o grade
>>>>>>> f24d865cea2cec325d50a88d653cbbf738b5b35c
