program: get_name.o
	gcc -ansi -Wall get_name.o -o program

get_name.o: get_name.c
	gcc -c -ansi -Wall get_name.c