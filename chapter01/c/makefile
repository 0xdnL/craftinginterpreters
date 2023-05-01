COMPILER := gcc
# COMPILER := cc

.PHONY: all clean

all: compile run

compile: helloworld.c
	$(COMPILER) -o helloworld $<

compileDebugging: helloworld.c
	$(COMPILER) -g $<

run: compile
	./helloworld

clean:
	rip helloworld
