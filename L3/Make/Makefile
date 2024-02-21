CC := g++

SRC_DIR := src
BUILD_DIR := build
INCLUDE_DIR := include

SOURCES := $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SOURCES))

EXECUTABLE := vpl_execution

ENTITIES_OBJECTS := $(BUILD_DIR)/Cilindro.o $(BUILD_DIR)/Ponto.o $(BUILD_DIR)/Circulo.o

all: ./$(EXECUTABLE)

./$(EXECUTABLE): $(OBJECTS) $(ENTITIES_OBJECTS)
	$(CC) $^ -o $@ 

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) -I$(INCLUDE_DIR) -c $< -o $@

$(BUILD_DIR)/Cilindro.o: $(SRC_DIR)/entidades/Cilindro.cpp
	$(CC) -I$(INCLUDE_DIR) -c $< -o $@

$(BUILD_DIR)/Ponto.o: $(SRC_DIR)/entidades/Ponto.cpp
	$(CC) -I$(INCLUDE_DIR) -c $< -o $@

$(BUILD_DIR)/Circulo.o: $(SRC_DIR)/entidades/Circulo.cpp
	$(CC) -I$(INCLUDE_DIR) -c $< -o $@

clean:
	rm -f $(BUILD_DIR)/*.o ./$(EXECUTABLE)

run: all
	././$(EXECUTABLE)