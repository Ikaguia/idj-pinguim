CC=g++
EXT=.cpp

CFLAGS=-I $(IDIR) -std=c++11 -O2 -Wno-unused-result $(pkg-config --cflags --libs sdl2)

IDIR=../include
ODIR=obj

OUTNAME=pinguim


_DEPS = game.hpp state.hpp sprite.hpp SDL.h SDL_image.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = game.o state.o sprite.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))	


$(ODIR)/%.o: %$(EXT) $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(OBJ)
	$(CC) -o $(OUTNAME) $^ $(CFLAGS) $(LIBS)


clean:
	rm -f $(ODIR)/*.o