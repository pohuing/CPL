objects = $(srcDir)main.o $(libDir)data.o $(libDir)sort.o
srcDir = src/
libDir = $(srcDir)lib/

main : $(objects)
	cc -o main.exe $(objects)
main.o : $(srcDir)main.c $(libDir)data.o $(libDir)sort.o

clean:
	rm -rf $(srcDir)*.o
	rm -rf $(libDir)*.o