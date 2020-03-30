objects = $(srcDir)main.o $(libDir)data.o $(libDir)sort.o $(libDir)file.o
srcDir = src/
libDir = $(srcDir)lib/
CC = gcc -std=c11 -pedantic


main : $(objects)
	$(CC) -g -o main.exe $(objects)
main.o : $(srcDir)main.c $(libDir)data.o $(libDir)sort.o $(libDir)file.o

clean:
	rm $(srcDir)*.o
	rm $(libDir)*.o