CFLAGS= -g -Wall
TARGETS=fork1 fork2
CC:=gcc

all: clean $(TARGETS)

e2: $(TARGETS).o
	$(CC) $(CFLAGS) -o $@ $^
.PHONY:test
test: e2
	ls | ./e2
.PHONY: clean
clean:
	rm -f bin *.o *~ $(TARGETS)
