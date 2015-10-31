CC = gcc 
CFLAGS= -g -pthread -Wall
TARGETS = tp5
all: $(TARGETS)

tp5: main.c parser.c http_worker.c recurso.c server.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -fv $(TARGETS) *.o  
