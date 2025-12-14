# Makefile for Hearing-aid-overlay

CXX = g++
CXXFLAGS = -Wall -Werror -O2 -I. -I/mingw64/include/SDL2
LDFLAGS = -L/mingw64/lib -lmingw32 -lSDL2main -lSDL2
TARGET = hearing-aid-overlay.exe

# Automatically find all .cc files in the project
SOURCES = $(wildcard *.cc arrowoverlay/*.cc overlayconfig/*.cc)
OBJECTS = $(SOURCES:.cc=.o)

# Build target
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	if exist $(subst /,\,$(OBJECTS)) del /Q $(subst /,\,$(OBJECTS))
	if exist $(TARGET) del /Q $(TARGET)
	echo Clean complete

run: $(TARGET)
	.\$(TARGET)

.PHONY: all clean run
