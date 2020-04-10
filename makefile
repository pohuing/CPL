objects = $(srcDir)main.o $(libDir)data.o $(libDir)sort.o $(libDir)file.o $(srcDir)/ui/ui.o
srcDir = src/
libDir = $(srcDir)lib/
statistics = 
CC = gcc 
CFLAGS += -std=c11 -pedantic -Werror $(statistics)
main : CFLAGS += -g
main : $(objects)
	$(CC) -o main.exe $(objects)
release : CFLAGS += -O3 
release : $(objects)
	$(CC) -o main.exe $(objects)
main.o : $(srcDir)main.c $(libDir)data.o $(libDir)sort.o $(libDir)file.o

clean:
	rm $(objects)
