CFLAGS= -g -Wall
TARGETS=fork3 fork4
CC:=gcc

all: clean $(TARGETS)

fork: $(TARGETS).o
	$(CC) $(CFLAGS) -o $@ $^
##.PHONY:test
##test: e2
##	ls | ./e2
.PHONY: clean
clean:
	rm -f bin *.o *~ $(TARGETS)
