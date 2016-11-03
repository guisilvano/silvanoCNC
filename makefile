IDIR = ./include
CC = gcc
CFLAGS = -I$(IDIR)

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

silvanoCNC: $(OBJ)
	gcc -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
