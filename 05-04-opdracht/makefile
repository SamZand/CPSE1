EXEC := main.exe

gcc := g++ -std=c++17 -fexceptions
rm := del

.PHONY := all build clean

SOURCES := $(wildcard *.cpp)

all: build
	./$(EXEC)

build:
	$(gcc) -c $(SOURCES) $(INCLUDE)
	$(gcc) *.o -o $(EXEC) $(LIB) $(LIBS) -static

clean:
	$(rm) $(EXEC) *.o