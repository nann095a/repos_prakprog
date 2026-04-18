CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -O -std=c++23

TARGET = main
SRCS = main.cpp sfuns.cpp
OBJS = $(SRCS:.cpp=.o)

LDLIBS = -lm

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) $(LDLIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

-include $(OBJS:.o=.d)

CXXFLAGS += -MMD -MP

Out.txt: $(TARGET)
	./$(TARGET) > Out.txt
	cat Out.txt

.PHONY: run runfile clean

run: $(TARGET)
	./$(TARGET)

runfile: $(TARGET)
	./$(TARGET) > Out.txt
	cat Out.txt

clean:
	rm -f $(TARGET) $(OBJS) $(OBJS:.o=.d) Out.txt
