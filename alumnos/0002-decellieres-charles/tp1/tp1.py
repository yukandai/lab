#!/usr/bin/python




import argparse
import datetime
import sys
import multiprocessing



             
                         
def search(path,pattern):
	fichier = open(path,"r")
	size = mq.get()
	lines = fichier.read(size)
	tmp = ""
	i = 0
	array = []
	for line in lines :
		if line != "\n":
			tmp = tmp + line
		else :
			array.append(tmp)			 
			i = i+1
			tmp = ""	
	list_line =""
	word = ""
	i=0
	for line in array : 
		i = i+1
		list_line = line.split()
		for word in list_line :
			if pattern in word :
				print "line ",i," : ",line
	print
	fichier.close()
	 	


def error_redirection():
	error = open("error_log.txt", "a")  
	date = datetime.datetime.now()
	error.write(str(date))
	error.write( " :\n")
	error.write(str(sys.stderr))
	error.write( "\n\n")
	error.close()


def lecture(path,size = 2048):
	fichier = open(path,"r")
	file_text = fichier.read(size)
	print file_text
	array_word = file_text.split()
	count_word = len(array_word)
	print "There's ", count_word," words\n"
	fichier.close()
				



parser = argparse.ArgumentParser()


parser.add_argument("-f", "--file", dest = "filePath", nargs = 1, required = True, help = "Input file path")
parser.add_argument("-s", "--size", dest = "readSize", nargs = "?", default = 2048, const = 1024, type = int, help = "Reading chunks size")
parser.add_argument("-g", "--grep", dest = "pattern_search",nargs = "?"  ,default =" ZERTYUIOPDFGHJKLXCVBN?DFGHJKRTYUIO",help = "Search a pattern in the file and display his line")

args = parser.parse_args()








p2 = multiprocessing.Process(target = lecture, args = (args.filePath[0],args.readSize))
p1 = multiprocessing.Process(target = search, args = (args.filePath[0],args.pattern_search))
mq = multiprocessing.Queue()

mq.put(args.readSize)

p2.start()
p1.start()

p1.join()
p2.join()

error_redirection()










