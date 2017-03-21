CC=g++
EXT=.cpp

#CFLAGS=-I $(IDIR) -std=c++11 -O2 -Wno-unused-result
#CFLAGS=-I $(IDIR) -I $(IDIR)/SDL2 -std=c++11 -O2 -Wno-unused-result
CFLAGS=-I $(IDIR) -std=c++11 -O2 -Wno-unused-result -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
#CFLAGS=-I $(IDIR) -I $(IDIR)/SDL2 -std=c++11 -O2 -Wno-unused-result -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
#CFLAGS=-I $(IDIR) -std=c++11 -O2 -Wno-unused-result -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
#CFLAGS=-I $(IDIR) -std=c++11 -O2 -Wno-unused-result -L $(IDIR)SDL2/ -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

IDIR=../include
ODIR=obj

OUTNAME=pinguim


_DEPS = game.hpp state.hpp sprite.hpp geometry.hpp gameObject.hpp face.hpp
#SDL.h SDL_image.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o game.o state.o sprite.o geometry.o face.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))	


$(ODIR)/%.o: %$(EXT) $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(OBJ)
	$(CC) -o $(OUTNAME) $^ $(CFLAGS) $(LIBS)


clean:
	rm -f $(ODIR)/*.o