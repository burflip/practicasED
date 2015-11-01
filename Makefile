CC=g++
CFLAGS=-c -Wall -std=c++11
LDFLAGS=
SOURCES=principal.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=principal

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@


