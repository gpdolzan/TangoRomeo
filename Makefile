CC = gcc
CFLAGS = -Wextra -g
EXEC = server client

SRC = $(wildcard *.c)
OBJS = $(SRC:.c=.o)

.PHONY: all clean purge run help

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	-rm -f $(OBJS) *~

purge: clean
	-rm -f $(EXEC)

run: $(EXEC)
	sudo ./server & sudo ./client

help:
	@echo "Targets in Makefile:"
	@echo "server: Compiles and links the server code"
	@echo "client: Compiles and links the client code"
	@echo "clean: Removes object files and temporary files"
	@echo "purge: Removes object files, executables, and temporary files"
	@echo "run: Runs both the server and client executables"
	@echo "help: Prints this help message"
