CFLAGS := -Wall -Wextra -O3 -DFE_STANDALONE -pedantic
CSTD := c23
LDFLAGS := -lm

BUILD_DIR := build

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/fe: src/fe.c src/fe.h
	$(CC) $(CFLAGS) -std=$(CSTD) -o $(BUILD_DIR)/fe src/fe.c $(LDFLAGS)

all: $(BUILD_DIR) $(BUILD_DIR)/fe

clean:
	rm -rf $(BUILD_DIR)