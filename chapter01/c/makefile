CC := gcc

.PHONY: all clean

all: compile run

compile: helloworld.c
	$(CC) -o helloworld $<

gdb: helloworld.c
	$(CC) -g $<

objectFile: helloworld.c
	$(CC) -c $< -o helloworld.o

run: compile
	./helloworld

clean:
	rip helloworld helloworld.o


ll: linkedlist.c
	$(CC) -o linkedlist $< && ./linkedlist
