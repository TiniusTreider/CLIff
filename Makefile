CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

executable = cliff
builddir = .build
objects = $(patsubst src/%.c,$(builddir)/%.o,$(wildcard src/*))

.PHONY: all clean

all: $(executable)

clean:
	rm -f $(executable) $(builddir)/*

$(executable): $(objects)
	$(CC) $(CFLAGS) $^ -o $@

$(builddir)/%.o: src/%.c | $(builddir)
	$(CC) $(CFLAGS) -c $< -o $@

$(builddir):
	mkdir -p $@

