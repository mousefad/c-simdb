
BUILD_DIR = build
SRC = $(wildcard *.c)
OBJ = $(addprefix $(BUILD_DIR)/,$(subst .c,.o,$(SRC)))
TARGET = $(BUILD_DIR)/demo

.PHONY: clean run

$(TARGET) : $(OBJ)
	$(CC) -o $@ $(LFLAGS) $^

$(BUILD_DIR)/%.o : %.c
	$(CC) -c -o $@ $(CFLAGS) $<

clean:
	rm -f $(OBJ) $(TARGET)

