# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -std=c++17 -O2

# Debug flags
DEBUG_FLAGS = -g -DDEBUG

# Libraries
LIBS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

# Directories
SRCDIR = src
OBJDIR = obj
SOURCES = $(wildcard *.cpp) $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

# Output executable
TARGET = game

# Default target
all: $(TARGET)

# Create object directory
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Build target
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET) $(LIBS)

# Compile source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean target
clean:
	rm -f $(TARGET) *.o $(SRCDIR)/*.o

# Run target
run: $(TARGET)
	./$(TARGET)

# Debug target
debug: CXXFLAGS += $(DEBUG_FLAGS)
debug: clean $(TARGET)

# Install dependencies (if needed)
install-deps:
	sudo pacman -S raylib gcc make cmake git

.PHONY: all clean run debug install-deps
