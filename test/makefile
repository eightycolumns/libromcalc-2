CFLAGS += -I ..

BUILD_DIR = ../build

.PHONY: all
all: $(BUILD_DIR)/$(TEST_EXE)

OBJECTS = $(patsubst %.c,%.o,$(wildcard *.c))

vpath lib%.a $(BUILD_DIR)

CFLAGS += $(shell pkg-config --cflags check)

LDFLAGS = -L$(BUILD_DIR)
LDLIBS = -l$(LIB_NAME:lib%.a=%)

LDFLAGS += $(shell pkg-config --libs-only-L check)
LDLIBS += $(shell pkg-config --libs-only-l check)

$(BUILD_DIR)/$(TEST_EXE): $(OBJECTS) -l$(LIB_NAME:lib%.a=%) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@ $(LDFLAGS) $(LDLIBS)

HEADERS = $(wildcard *.h) ../src/$(LIB_NAME:lib%.a=%).h

$(OBJECTS): $(HEADERS)

$(BUILD_DIR):
	mkdir -p $@

.PHONY: clean
clean:
	rm -rf $(OBJECTS) $(BUILD_DIR)
