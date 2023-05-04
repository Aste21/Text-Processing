# List your *.h files (if you do not have them in your project then leave the variable "headers" empty):
headers = rand_malloc.h

# List your *.c files:
sources = test.c rand_malloc.c

# Specify name of your program:
executable = test

$(executable): $(headers) $(sources)
	gcc -g -Wall -pedantic $(sources) -o $(executable)

.PHONY: clean
clean:
	rm $(executable)

.PHONY: check
check: $(executable)
	valgrind --leak-check=full --track-origins=yes ./$(executable)