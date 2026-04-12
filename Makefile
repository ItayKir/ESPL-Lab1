CC = gcc

CFLAGS = -Wall -g

all: count-words addresses

count-words: count-words.c
	$(CC) $(CFLAGS) -o count-words count-words.c

# Task 1 Target
# Note: We add the specific -m32 flag here as requested in T1a
addresses: addresses.c
	$(CC) $(CFLAGS) -m32 -o addresses addresses.c

clean:
	rm -f count-words addresses