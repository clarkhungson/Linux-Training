test: output.o input.o main.o
	gcc -o test output.o input.o main.o
output.o: output.c di_io.h
	gcc -c -o output.o output.c
input.o: input.c di_io.h
	gcc -c -o input.o input.c
main.o: main.c di_io.h
	gcc -c -o main.o main.c
clean:
	rm *.o test
