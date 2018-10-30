compile:stat.o
	gcc stat.o
run:
	./a.out
clean:
	rm *.o ./a.out
file.o: stat.c stat.h
gcc -c stat.c
