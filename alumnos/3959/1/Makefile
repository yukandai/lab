CFLAGS= -g -Wall
TARGETS=e1
CC:=gcc

all: clean $(TARGETS)

e1: $(TARGETS).o
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean
clean:
	rm -f bin *.o *~ $(TARGETS)
