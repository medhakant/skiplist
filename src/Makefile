IDIR =../include
CC=g++
CFLAGS=-I$(IDIR)

ODIR=./obj

_DEPS = Entry.h QuadNode.h SkipList.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = Entry.o QuadNode.o SkipList.o Main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

skiplist: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o 