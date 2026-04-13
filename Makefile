CC = gcc

CFLAGS = -Wall -g -m32

all: count-words addresses base menu_map

count-words: count-words.c
	$(CC) $(CFLAGS) -o count-words count-words.c

addresses: addresses.c
	$(CC) $(CFLAGS) -m32 -o addresses addresses.c

base: base.c
	$(CC) $(CFLAGS) -o base base.c

menu_map: menu_map.c base.c
	$(CC) $(CFLAGS) -o menu_map menu_map.c base.c

clean:
	rm -f count-words addresses base menu_map menu_program