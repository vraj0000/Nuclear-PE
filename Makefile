ODIR = obj
BDIR = build
CDIR = include/nuclear
LDIR = src
TDIR = src/Play_Ground

CORE = nuclear.h core.h particle.h precision.h
DEPS = $(patsubst %,$(CDIR)/%,$(CORE))
OBJ = partical.o

CXX = g++
CXXFLAGS = -Wall -O2

Firework: $(ODIR)/particle.o 
	$(CXX) $(CXXFLAGS) $(ODIR)/particle.o $(TDIR)/Firework.cpp -o $(BDIR)/Firework

ballistic: $(ODIR)/particle.o 
	$(CXX) $(CXXFLAGS) $(ODIR)/particle.o $(TDIR)/ballistic.cpp -o $(BDIR)/ballistic

$(ODIR)/particle.o : $(LDIR)/particle.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)