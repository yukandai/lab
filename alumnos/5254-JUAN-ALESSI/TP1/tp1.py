#!/usr/bin/python
# -*- coding: utf-8 -*-

from multiprocessing import Process, Queue
import os
import time
import multiprocessing
import sys
import getopt



def ayuda():
    print("./tp1.py -f <archivo> -n <tamaño_bloque> -p <hijos>")
      
    print('./tp1.py -f /etc/services -n 1024 -p 2\n')
 
def func1(mq,i):
	
	fin= True
	while fin == True:
	
			a = len(mq.get().split(" "))
			#print " estoy en try"
			print "Soy el proceso %d y acabo de leer la cantidad de palabras: " % (i + 1) , a, os.getpid(),os.getppid()
			#mq.put(a) esto me estaba dando errores
			time.sleep(5)
			if mq.empty() is True:
				fin=False


def cuenta(texto):
	contador=0
	palabras=0

	resutl=str(texto).split(" ")
	++contador
	palabras=contador

	print "cantidad de palabras" + palabras

def salir():
	print "gracias"



try:
	(opts, args) = getopt.getopt(sys.argv[1:], 'hf:n:p:')
except getopt.GetoptError as err:
	print(err)
	sys.exit(2)



if len(opts) != 0:
	for (o,a) in opts:
		if o in ('-h'):
			ayuda()
			sys.exit()
		elif o in ('-f'):
			archivo_origen= sys.argv[2]
		elif o in ('-n'):
			bloque= sys.argv[4]
		elif o in ('-p'):
			hijos= sys.argv[6]
		else:
			ayuda()
			sys.exit(2)
else:
	ayuda()
	sys.exit(2)
print "soy el padre"
print  "el nombre del archivo de origen es: " ,archivo_origen
print "el bloque determinado es: " , bloque
print "la cantidad de hijos a crear es: " , hijos

processes = []

fdo = os.open( archivo_origen, os.O_RDONLY )
total = os.stat(archivo_origen).st_size

EOF = False
mq = Queue()


for i in range(int(hijos)):
	p = Process(target=func1, args=(mq,i))
	processes.append(p)
	p.start()


while EOF == False:
	leido = os.read(fdo, int(bloque))
	print "total leido del archivo: " , len(leido)
	mq.put(leido)
	if len(leido) != int(bloque):
		EOF = True

#for process in processes:
#	processes[i].start()
#	process.join()

#h1 = multiprocessing.Process(target=func1,  args=())
#h2 = multiprocessing.Process(target=func2,  args=())

#h1.start()
#h2.start()



time.sleep(5)


#h2.join()
#h1.join()

for process in processes:
		process.join()

print "terminaron los hijos"

while mq.empty() is False:
	print mq.get()

	
