CC = gcc 
CFLAGS= -g -Wall
TARGETS = tp4
all: $(TARGETS)

tp4: main.c parser.c http_worker.c recurso.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -fv $(TARGETS) *.o  
