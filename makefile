IDIR = ./include
CC = gcc
CFLAGS = -I $(IDIR) -ansi

SDIR = ./src
ODIR = ./src/obj
LDIR = ./lib

BUILD_ODIR := $(shell mkdir -p $(ODIR))

LIBS =

_DEPS = gcode.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o gcode.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

silvano-cnc: $(OBJ)
	gcc -o $@ $^ $(CFLAGS) $(LIBS)

install:
	sudo cp silvano-cnc /bin

.PHONY: clean

clean:
	rm -r -f $(ODIR) *~ core $(INCDIR)/*~ 
