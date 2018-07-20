CXX = g++ 
CXXFLAGS = -Wall -Wpedantic -Wextra -Werror
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)
TARGET = saper

.PHONY: all
all: $(TARGET)

%.o: %.cpp %.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@   

$(TARGET): $(OBJS)
	$(CXX) $^ -o $@

.PHONY: clean
clean:
	rm $(TARGET) *.o
