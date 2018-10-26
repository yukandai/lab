CC=gcc
CFLAGS=-Wall

srv: srv.c hijo.c
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)


test: srv
	./srv
