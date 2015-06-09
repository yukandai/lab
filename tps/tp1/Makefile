CC=gcc
CFLAGS=-g -Wall


sol: sol.c
	$(CC) $(CFLAGS) -o $@ $^


test: sol
	echo "hola mono! cómo andás?, todo bien?" | ./sol


clean:
	rm -f sol *~


