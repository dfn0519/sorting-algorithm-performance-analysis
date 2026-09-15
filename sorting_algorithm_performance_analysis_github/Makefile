CC = gcc
CFLAGS = -O2 -std=c11 -Wall -Wextra
COMMON = src/sorting/*.c src/datasets/*.c src/benchmark/*.c

.PHONY: all experiment1 experiment2 clean

all: experiment1 experiment2

experiment1:
	mkdir -p bin
	$(CC) $(CFLAGS) src/experiment_1.c $(COMMON) -o bin/experiment1

experiment2:
	mkdir -p bin
	$(CC) $(CFLAGS) src/experiment_2.c $(COMMON) -o bin/experiment2

clean:
	rm -rf bin
