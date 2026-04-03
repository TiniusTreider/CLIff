CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

executable = ours
objects = $(patsubst src/%.c,%.o,$(wildcard src/*))

.PHONY: all clean

all: $(executable)

clean:
	rm -f $(executable) *.o

$(executable): $(objects)
	$(CC) $(CFLAGS) $^ -o $@

%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

