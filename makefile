CC=g++
EXT=.cpp

CFLAGS=-I $(IDIR) -std=c++11 -O2 -Wno-unused-result -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
#CFLAGS=-I $(IDIR) -std=c++11 -O2 -Wno-unused-result -L $(IDIR)SDL2/ -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

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