# Computación II: TP3: Comunicación entre procesos con memoria compartida.
# <federico.hernandez@um.edu.ar>
# <carlos.taffernaberry@um.edu.ar>

CC=gcc
CFLAGS=-g -Wall
RM = tp3

# objetivo: dependencias
tp3: 	tp3.c	padre.c	hijo.c
	$(CC) $(CFLAGS) -o $@ $^ 

#test: tp3
#	cat file.txt | ./tp3

#cat new-file.txt | ./tp3

#justify-text:
	# justify text at 80 characters
#	par 80j < file.txt > new-file.txt

clean:
	rm -f $(RM) *.o *~

