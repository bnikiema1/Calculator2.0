CXX = g++
STRIP = strip 

TARGET = myCalc.exe

SRC_DIR = src

CFLAGS = -Wall -Wextra -g
LDFLAGS =

BUILD = build

# OBJS = $(SRC:.cpp =$(BUILD)/%.o)
SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRC:$(SRC_DIR)/%.cpp=$(BUILD)/%.o)


.PHONY: all

all: $(TARGET)

$(TARGET) : $(OBJS)
	@if not exist $(BUILD) mkdir $(BUILD)
	$(CXX) $(LDFLAGS) -o $@ $^


$(BUILD)/%.o: src/%.cpp
	@if not exist $(BUILD) mkdir $(BUILD)
	$(CXX) $(CFLAGS) -c $< -o $@

run:
	./$(TARGET)

clean:
	if exist "$(BUILD)" rmdir /s /q "$(BUILD)"
	if exist "$(TARGET)" del /f /q "$(TARGET)"