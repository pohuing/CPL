#objectfiles
objects = $(srcDir)main.o $(libDir)data.o $(libDir)sort.o $(libDir)file.o $(srcDir)/ui/ui.o
#directory of source root
srcDir = src/
#directory of library root
libDir = $(srcDir)lib/
#compiler
CC = gcc 
#up to date c11, only allow standard c, error on warnings
CFLAGS += -std=c11 -pedantic -Werror 
#preprocessor flags
ifeq ($(COLLECT_STATS),1)
	CFLAGS += -DCOLLECT_STATS
endif
ifeq ($(LOGGING),1)
	CFLAGS += -DLOGGING
endif
#include debug symbols by default
main : CFLAGS += -g
main : $(objects)
	$(CC) $(CFLAGS) -o main.exe $(objects)
#build optimized release builds
release : CFLAGS += -O3 
release : $(objects)
	$(CC) $(CFLAGS) -o main.exe $(objects)
main.o : $(srcDir)main.c $(libDir)data.o $(libDir)sort.o $(libDir)file.o
	$(CC) $(CFLAGS) -o main.exe $(objects)
from_file: $(srcDir)from_file.o $(libDir)data.o $(libDir)sort.o $(libDir)file.o
	$(CC) $(CFLAGS) -o from_file.exe $(srcDir)from_file.o $(libDir)data.o $(libDir)sort.o $(libDir)file.o
clean:
#ignore errors on cleanup
	-rm $(objects)
