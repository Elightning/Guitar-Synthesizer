# Makefile for GuitarSynthesizer
# Eamon Lightning

GXX = g++
GXXFLAGS = -Wall -Werror -ansi -pedantic

all: GuitarSynthesizer

GuitarSynthesizer: GuitarSynthesizer.o RingBuffer.o GuitarString.o
	$(GXX) GuitarSynthesizer.o GuitarString.o RingBuffer.o -o GuitarSynthesizer $(GXXFLAGS) -lsfml-audio -lsfml-window -lsfml-graphics -lsfml-system

GuitarSynthesizer.o: GuitarSynthesizer.cpp GuitarString.hpp
	$(GXX) -c GuitarSynthesizer.cpp $(GXXFLAGS) 

GuitarString.o: GuitarString.cpp GuitarString.hpp RingBuffer.hpp
	$(GXX) -c GuitarString.cpp $(GXXFLAGS) 

RingerBuffer.o: RingBuffer.cpp RingBuffer.hpp
	$(GXX) -c RingBuffer.cpp $(GXXFLAGS)

clean:
	rm *~ *.o GuitarSynthesizer 