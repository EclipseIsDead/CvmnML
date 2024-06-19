CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
BUILD_DIR = build

OBJS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(wildcard $(SRC_DIR)/*.c))

TARGET = $(BUILD_DIR)/mlp

all: $(TARGET)

# mlp target
mlp: $(BUILD_DIR)/mlp.o $(BUILD_DIR)/mlp
	@echo "Built mlp executable"

$(BUILD_DIR):
	mkdir -p $@

$(TARGET): $(OBJS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $^ -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean mlp
