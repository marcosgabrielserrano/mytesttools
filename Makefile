
CC := gcc

REMOTE_FLAGS := --static

SRC_DIR := src/
BIN_DIR := bin/

DAEMON_SRC := $(SRC_DIR)execute_agent.c
DAEMON_TARGET := $(BIN_DIR)daemon
DAEMON_TARGET_32 := $(DAEMON_TARGET)_32

TEST_SRC := $(SRC_DIR)test_daemon.c
TEST_TARGET := $(BIN_DIR)write_byte

all: 64 32

64: $(DAEMON_TARGET) $(TEST_TARGET)
32: $(DAEMON_TARGET_32)

$(DAEMON_TARGET): $(DAEMON_SRC)
	$(CC) $(REMOTE_FLAGS) $^ -o $@

$(DAEMON_TARGET_32): $(DAEMON_SRC)
	$(CC) -m32 $(REMOTE_FLAGS) $^ -o $@

$(TEST_TARGET): $(TEST_SRC)
	$(CC) $^ -o $@

clean:
	rm -f $(BIN_DIR)*

.PHONY: clean
