CFLAGS := -Wall -Wextra -O3 -pedantic
CSTD := c11
LDFLAGS := -lm

BUILD_DIR := build

all: $(BUILD_DIR) $(BUILD_DIR)/fe doc

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)/doc

$(BUILD_DIR)/doc:
	mkdir -p $(BUILD_DIR)/doc

$(BUILD_DIR)/fe: src/fe.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) -x c -std=$(CSTD) -o $@ src/fe.h $(LDFLAGS) -DFE_IMPLEMENTATION -DFE_STANDALONE

$(BUILD_DIR)/doq: | $(BUILD_DIR)
	git clone https://github.com/rxi/doq.git $(BUILD_DIR)/doq_src
	$(CC) $(CFLAGS) -o $@ $(BUILD_DIR)/doq_src/doq.c

doc: $(BUILD_DIR)/doc/index.html

$(BUILD_DIR)/doc/index.html: README.md $(BUILD_DIR)/doq | $(BUILD_DIR)/doc
	./$(BUILD_DIR)/doq README.md > $(BUILD_DIR)/doc/index.html
	./$(BUILD_DIR)/doq doc/capi.md > $(BUILD_DIR)/doc/capi.html
	./$(BUILD_DIR)/doq doc/impl.md > $(BUILD_DIR)/doc/impl.html
	./$(BUILD_DIR)/doq doc/lang.md > $(BUILD_DIR)/doc/lang.html

clean:
	rm -rf $(BUILD_DIR)
