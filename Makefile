CC=gcc
CFLAGS=-Wall -Wextra -Werror -I.
RM=rm -f
BUF_F = 10
SRC = get_next_line_utils.c get_next_line.c
DEPS = get_next_line.h
OBJ = $(SRC:.c=.o)

%.o: %.c $(DEPS)
	$(CC) -c -o $@ -D BUFFER_SIZE=$(BUF_F) $< $(CFLAGS)

get_next_line: $(OBJ)
	$(CC) -o $@ -D BUFFER_SIZE=$(BUF_F) $^ $(CFLAGS)

clean:
	$(RM) $(OBJ)