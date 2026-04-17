CXX = g++
CXXFLAGS = -std=c++23 -Wall

OBJ = build/main.o build/sfuns.o
TARGET = build/mathprog

.PHONY: all run runfile clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

build/main.o: main.cc
	mkdir -p build
	$(CXX) $(CXXFLAGS) -c main.cc -o build/main.o

build/sfuns.o: sfuns.cc
	mkdir -p build
	$(CXX) $(CXXFLAGS) -c sfuns.cc -o build/sfuns.o

run: $(TARGET)
	./$(TARGET)

runfile: $(TARGET)
	./$(TARGET) > Out.txt

Out.txt: $(TARGET)
	./$(TARGET) > Out.txt

clean: 
	rm -rf build




	