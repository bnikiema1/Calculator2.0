CXX = g++
LD = $(CXX)
STRIP = strip 

TARGET = myCalc.exe

SRC = calc.cpp basic.cpp

CFLAGS = -Wall -Wextra -g
LDFLAGS =

OBJS = $(wildcard %.cpp, %.o, $(SRC))
DEPS = $(wildcard %.cpp, %.d, $(SRC))

.PHONY: all

all: $(TARGET)

$(TARGET) : $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $^


%.o: %.cpp
	$(CXX) -c $(CFLAGS) -o $@ $^

run:
	./$(TARGET)

clean:
	del $(TARGET)