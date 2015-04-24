FLAGS= -g -Wall
TARGETS=TP1
CC:=gcc

all: clean $(TARGETS)


.PHONY:test1
test1: $(TARGETS) 
	cat mensaje.txt |./TP1

.PHONY:test2
test2:	$(TARGETS)
	cat mensaje.txt |./TP1 -o mensaje-filtrado.txt
.PHONY:test3
test3:  $(TARGETS) 
	./TP1 -h
.PHONY: clean
clean:
	rm -f bin *.o *~ $(TARGETS) mensaje-filtrado.txt
