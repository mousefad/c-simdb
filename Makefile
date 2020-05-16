
BUILD_DIR = build
CFLAGS += -DDEBUG -g
LFLAGS += 
CXXFLAGS += $(CFLAGS)
LXXFLAGS += 
CSRC = $(wildcard *.c)
CXXSRC = $(wildcard *.cpp)
CXXOBJ = $(addprefix $(BUILD_DIR)/,$(subst .cpp,.o,$(CXXSRC)))
COBJ = $(addprefix $(BUILD_DIR)/,$(subst .c,.o,$(CSRC)))
OBJ = $(CXXOBJ) $(COBJ)
CC = gcc
CXX = g++
TARGET = $(BUILD_DIR)/test

.PHONY: clean run

run: $(TARGET)
	$(TARGET)

$(TARGET) : $(OBJ)
	$(CXX) -o $@ $(LXXFLAGS) $^

$(BUILD_DIR)/%.o : %.cpp
	$(CXX) -c -o $@ $(CXXFLAGS) $<

$(BUILD_DIR)/%.o : %.c
	$(CC) -c -o $@ $(CFLAGS) $<

clean:
	rm -f $(OBJ) $(TARGET)

