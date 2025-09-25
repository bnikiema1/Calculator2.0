CXX = g++
LD = $(CXX)
STRIP = strip 

TARGET = myCalc.exe

SRC = calc.cpp basic.cpp

CFLAGS = -Wall -Wextra -g
LDFLAGS =

BUILD = build

# OBJS = $(SRC:.cpp =$(BUILD)/%.o)
OBJS = $(addprefix $(BUILD)/, $(SRC:.cpp=.o))
DEPS = $(wildcard %.cpp, %.d, $(SRC))

.PHONY: all

all: $(TARGET)

$(TARGET) : $(OBJS)
	@if not exist $(BUILD) mkdir $(BUILD)
	$(LD) $(LDFLAGS) -o $@ $^


$(BUILD)/%.o: %.cpp
	@if not exist $(BUILD) mkdir $(BUILD)
	$(CXX) $(CFLAGS) -c $< -o $@

run:
	./$(TARGET)

clean:
	if exist "$(BUILD)" rmdir /s /q "$(BUILD)"
	if exist "$(TARGET)" del /f /q "$(TARGET)"