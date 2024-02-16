TARGET=a.out
CXX=g++
DEBUG=-g
OPT=-O0
WARN=Wall
CXXFLAGS=$(DEBUG) $(OPT) -ljsoncpp
LD=g++
OBJS=main.o
all: $(OBJS)
	$(LD) -o $(TARGET) $(OBJS) $(CXXFLAGS)

main.o: main.cpp
	$(CXX) -c $(CXXFLAGS) main.cpp -o main.o
