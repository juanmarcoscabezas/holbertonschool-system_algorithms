CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -ggdb3 -lm

TASK0 = 0-backtracking_array

$(TASK0): $(TASK0).c 0-main.c libqueues.a
	$(CC) $(CFLAGS) -o $@  $^

.PHONY: clean, check, run

clean:
	rm $(TASK0)

run: $(TASK0)
	@valgrind --leak-check=full ./$^

check:
	betty *.c *.h