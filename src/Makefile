IDIR=../include
CC=gcc
CFLAGS=-O3 -I$(IDIR)
ODIR=.

LIBS=-lm

_DEPS = exact_grep.h
DEPS= $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = exact_grep.o exact_grep_func.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

exact_grep: $(OBJ)
	gcc -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ exact_grep
