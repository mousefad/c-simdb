
BUILD_DIR = build
SRC = $(wildcard *.c)
OBJ = $(addprefix $(BUILD_DIR)/,$(subst .c,.o,$(SRC)))
TARGET = $(BUILD_DIR)/demo

.PHONY: clean run check

$(TARGET) : $(OBJ)
	$(CC) -o $@ $(LFLAGS) $^

$(BUILD_DIR) :
	mkdir $(BUILD_DIR)

$(BUILD_DIR)/%.o : %.c $(BUILD_DIR)
	$(CC) -c -o $@ $(CFLAGS) $<

# For github workflow
check : $(TARGET)
	$(TARGET) 2>&1 | grep -q FATAL

clean :
	rm -f $(OBJ) $(TARGET)

