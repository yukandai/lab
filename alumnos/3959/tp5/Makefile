CFLAGS= -g -Wall
LDLIBS=-lrt 
CC:=gcc
TARGETS= server 

all: clean $(TARGETS)
server: main.c create_socket.c
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)

.PHONY: test
test:
	./server -d www/
ab-test-ipv4:
	ab -k -c 10 -n 1000 http://127.0.0.1:8080/index.txt

ab-test-ipv6:
	ab -k -c 10 -n 1000 http://[::1]:8080/index.txt

.PHONY: clean
clean:
	rm -f *.o *~ $(TARGETS)
