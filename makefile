objects = $(srcDir)main.o $(libDir)data.o $(libDir)sort.o $(libDir)file.o $(srcDir)/ui/ui.o
srcDir = src/
libDir = $(srcDir)lib/
CC = gcc 
CFLAGS += -std=c11 -pedantic -Werror $(statistics)
ifeq ($(COLLECT_STATS),1)
	CFLAGS += -DCOLLECT_STATS
endif
main : CFLAGS += -g
main : $(objects)
	$(CC) $(CFLAGS) -o main.exe $(objects)
release : CFLAGS += -O3 
release : $(objects)
	$(CC) $(CFLAGS) -o main.exe $(objects)
main.o : $(srcDir)main.c $(libDir)data.o $(libDir)sort.o $(libDir)file.o
	$(CC) $(CFLAGS) -o main.exe $(objects)
from_file: $(srcDir)from_file.o $(libDir)data.o $(libDir)sort.o $(libDir)file.o
	$(CC) $(CFLAGS) -o from_file.exe $(srcDir)from_file.o $(libDir)data.o $(libDir)sort.o $(libDir)file.o
clean:
	-rm $(objects)
