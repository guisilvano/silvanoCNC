IDIR = ./include
CC = gcc
CFLAGS = -I$(IDIR)

ODIR = ./src/obj
LDIR = ./lib

dummy_build_folder := $(shell mkdir -p $(ODIR))

LIBS =

_DEPS = gcode.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

_OBJ = main.o gcode.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))v 

silvanoCNC: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
