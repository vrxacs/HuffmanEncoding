CC = g++
CFLAGS = -Wall -pedantic -std=c++0x -O3

all: Huffman.out

Huffman.out: test.cpp
	$(CC) $(CFLAGS) test.cpp