IDIR = include
CC = gcc
CFLAGS = -I$(IDIR)

ODIR = src/obj/
LDIR = lib

dummy_build_folder := $(shell mkdir -p $(ODIR))

LIBS = -lm

_DEPS = gcode.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o gcode.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

silvanoCNC: $(OBJ)
	gcc -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
