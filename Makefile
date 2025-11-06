CFLAGS := -Wall -Wextra -O3 -pedantic
CSTD := c23
LDFLAGS := -lm

BUILD_DIR := build

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/fe: src/fe.h
	$(CC) $(CFLAGS) -x c -std=$(CSTD) -o $(BUILD_DIR)/fe src/fe.h $(LDFLAGS) -DFE_IMPLEMENTATION -DFE_STANDALONE

all: $(BUILD_DIR) $(BUILD_DIR)/fe

clean:
	rm -rf $(BUILD_DIR)