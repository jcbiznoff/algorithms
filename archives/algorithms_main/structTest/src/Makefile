IDIR = ../include
CC = gcc
CFLAGS = -Wall -I$(IDIR)

ODIR=obj
LDIR =../lib

_DEPS = structtest.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = structtest.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

structtest: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
