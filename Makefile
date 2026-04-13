CC = gcc

CFLAGS = -Wall -g

all: count-words addresses base menu

count-words: count-words.c
	$(CC) $(CFLAGS) -o count-words count-words.c

# Task 1 Target
# Note: We add the specific -m32 flag here as requested in T1a
addresses: addresses.c
	$(CC) $(CFLAGS) -m32 -o addresses addresses.c

base: base.c
	$(CC) $(CFLAGS) -o base base.c

menu: menu.c
	$(CC) $(CFLAGS) -o menu menu.c

clean:
	rm -f count-words addresses base menu