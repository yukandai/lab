CFLAGS= -g -Wall
TARGETS=e2
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
