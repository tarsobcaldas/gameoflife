# *  Define the name of the makefile.                                        *

MAKNAM = makefile

# *  Define the directories in which to search for library files.            *

LIBDRS =

# *  Define the directories in which to search for include files.            *

INCDRS =

# *  Define the library files.                                               *

LIBFLS =

# *  Define the source files.                                                *

SRCFLS = gameoflife.c \
				 generation.c \
				 
OBJFLS = gameoflife.o \
				 generation.o

# *  Define the executable.                                                  *

EXE    = gameoflife

# *  Define the compile and link options.                                    *

CC     = gcc
LL     = gcc
CFLAGS = -Wall -g
LFLAGS =

# *  Define the rules.                                                       *

$(EXE): $(OBJFLS)
	$(LL) $(LFLAGS) -o $@ $(OBJFLS) $(LIBDRS) $(LIBFLS)

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $(INCDRS) $<

all:
	make -f $(MAKNAM) clean
	make -f $(MAKNAM) $(EXE)

clean:
	-rm $(EXE)
	-rm $(OBJFLS)

# DO NOT DELETE THIS LINE -- make depend depends on it.


# mutator.o: bool.h globals.h list.h bistree.h bistree.c
# heap.o: heap.h globals.h heap.c
# bistree.o: bool.h bistree.h bistree.c
# list.o: bool.h list.h list.c
