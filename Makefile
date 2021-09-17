
CC := gcc

SRC_DIR := src/
BIN_DIR := bin/

DAEMON_SRC := $(SRC_DIR)execute_agent.c
DAEMON_TARGET := $(BIN_DIR)daemon

TEST_SRC := $(SRC_DIR)test_daemon.c
TEST_TARGET := $(BIN_DIR)write_byte

all: $(DAEMON_TARGET) $(TEST_TARGET)

$(DAEMON_TARGET): $(DAEMON_SRC)
	$(CC) $^ -o $@

$(TEST_TARGET): $(TEST_SRC)
	$(CC) $^ -o $@

clean:
	rm -f $(BIN_DIR)*

.PHONY: clean
