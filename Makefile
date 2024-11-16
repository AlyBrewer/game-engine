# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -g3 -Iinclude

# Directories
SRC_DIR = src/ogl3d
INCLUDE_DIR = include/ogl3d
GAME_DIR = game
OUTPUT_DIR = $(GAME_DIR)/output

# Source and object files
SRCS = $(GAME_DIR)/main.cpp \
       $(SRC_DIR)/game/OGame.cpp \
       $(SRC_DIR)/window/OWindow.cpp

OBJS = $(GAME_DIR)/main.o \
       $(SRC_DIR)/game/OGame.o \
       $(SRC_DIR)/window/OWindow.o

# Output executable
TARGET = $(OUTPUT_DIR)/main.exe

# Default target
all: $(TARGET)

# Build target
$(TARGET): $(OBJS) | $(OUTPUT_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

# Create output directory if it doesn't exist
$(OUTPUT_DIR):
	mkdir -p $(OUTPUT_DIR)

# Compile each source file into an object file explicitly
game/main.o: game/main.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

src/ogl3d/game/OGame.o: src/ogl3d/game/OGame.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

src/ogl3d/window/OWindow.o: src/ogl3d/window/OWindow.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: all clean
