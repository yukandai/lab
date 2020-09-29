#!/usr/bin/python3

from socketserver import *
import os
# import pickle
import logging

# default level of WARNING
logging.basicConfig(level=logging.DEBUG)
logging.basicConfig(filename="test.log", level=logging.DEBUG)

class MyTCPHandler(BaseRequestHandler):

	def handle(self):
		try:
			response = {
				'200' : '200 OK',
				'400' : '400 Bad Request',
				'404' : '404 Not Found',
				'500' : '500 Internal Server Error' }

			logging.debug("Nueva Conexion: ({})".format(self.client_address))

			self.data  = self.request.recv(1024)
			encabezado = self.data.decode().splitlines()[0] # GET /pagina.html HTTP/1.1
			self.archivo = encabezado.split()[1] 			# /pagina.html
			http = encabezado.split()[2]					# HTTP/1.1

			# si me piden la raiz ( / )
			if len(self.archivo) == 1:
				self.archivo = "index.html"
			else:
				# si me piden un archivo en particular (le sacamos la barra del comienzo)
				self.archivo = self.archivo[1:len(self.archivo)]

			# si hemos indicado un document-root
			if self.server.base_path:
				self.archivo = self.server.base_path + '/' + self.archivo

			# si existe el archivo pedido
			if self.isIndexFile() == True:
				http += " " + response['200']
			elif os.path.isfile(self.archivo) == False:
				http += " " + response['404']
				self.archivo = "./error.html"
			else:
				http += " " + response['200']

			logging.debug("Peticion: ({}) Resultado: ({})".format(self.archivo, http))

			ext = self.getExtensionFile()
			if ext == 'ppm':
				# procesamos archivos ppm
				logging.debug("Archivo ppm, lanzando ({}) hilos".format(self.server.size))
				self.processPPMFile()
			else:
				# procesamos el resto de los archivos
				if self.isIndexFile() == True:
					# si pidieron el index lo generamos
					logging.debug("Generando Indice...")
					self.body = self.generateIndex()
				else:
					fd = os.open(self.archivo, os.O_RDONLY)
					temp = os.read(fd, self.server.size)
					self.body = b""
					while temp:
						self.body = bytearray(self.body + temp)
						temp = os.read(fd, 1000)
					os.close(fd)

			logging.debug("Procesando respuesta...")

			ctype = "Content-type: " + self.getContentType()
			clength = "Content-length: " + str(len(self.body))
			header = bytearray(http + "\r\n" + ctype + "\r\n" + clength + "\r\n\r\n", "utf8")

			respuesta = header + self.body	 # respuesta = self.request.sendall(enviado.upper())
			self.request.send(respuesta) # self.request.send(pickle.dumps(respuesta))

			# tambien puede hacerse
			# self.request.send(header)
			# self.request.send(body)

		except Exception as e:
			# ejemplos = pasa parametros erroneos, o le pide filtro a un self.archivo pdf
			# http = http  + " " + response['500']
			raise e

	''' Lanzamos una cantidad de hilos determinada por 'size' que procesen la imagen a ser devuelta '''
	def processPPMFile(self):
		# threads = []
		logging.debug("Creando hilos...")
		# for h in range(1, self.server.size): #4
		#	h = threading.Thread(target=self.process_color, args=())
		#	threads.append(h)
		#	h.start()

		# Espero a q los hilos terminen
		# for h in threads:
		#	h.join()

		# TODO: borrar esto cdo implemente los hilos

		fd = os.open(self.archivo, os.O_RDONLY)
		temp = os.read(fd, self.server.size)
		self.body = b""
		while temp:
			self.body = bytearray(self.body + temp)
			temp = os.read(fd, 1000)
		os.close(fd)

	''' Devuelve la extension del archivo pedido '''
	def getExtensionFile(self):
		pos  = self.archivo.rfind('.', 0, len(self.archivo))+1
		ext = self.archivo[pos:len(self.archivo)]
		return ext

	''' Devuelve el content-type segun archivo '''
	def getContentType(self):
		pos  = self.archivo.rfind('.', 0, len(self.archivo))+1
		tipo = self.archivo[pos:len(self.archivo)]

		content = {
			'html': 'text/html', 
			'pdf' : 'application/pdf',
			'jpg' : 'image/jpeg',
			'ppm' : 'image/x-portable-pixmap' }

		return content[tipo]

	''' Me indica si el archivo a ser mostrado es el index '''
	def isIndexFile(self):
		pos  = self.archivo.rfind('/', 0, len(self.archivo))+1
		fileName = self.archivo[pos:len(self.archivo)]

		if (fileName == 'index.html'):
			return True
		else:
			return False

	''' Recorremos todos los directorios y archivos bajo un path '''
	def generateIndex(self):
		allowed = ['html', 'pdf', 'jpg', 'ppm']

		path = '.'
		if self.server.base_path:
			path = self.server.base_path

		html  = '<html>'
		html += '	<head>'
		html += '		<title>Directorio WEB</title>'
		html += '		<link data-rh="true" rel="icon" href="https://cdn-static-1.medium.com/_/fp/icons/favicon-rebrand-medium.3Y6xpZ-0FSdWDnPM3hSBIA.ico" />'
		html += '	</head>'
		html += '	<body>'
		html += '		<p>Directorio:</p>'
		html += '		<ul>'
		for base, dirs, files in os.walk(path):
			pos  = self.archivo.rfind('/', 0, len(self.archivo))+1
			new_base = base[pos:len(base)]
			for file in files:
				# TODO: modificar y usar la funcion "self.getExtensionFile()"
				pos  = file.rfind('.', 0, len(file))+1
				ext = file[pos:len(file)]
				if ext in allowed:
					# solo mostramos los archivos permitidos
					html += '	<li><a href="' + new_base + '/' + file + '">' + new_base + '/' + file + '</a></li>'
		html += '		</ul>'
		html += '	</body>'
		html += '</html>'

		self.body = bytearray(html, 'utf8')

		return self.body

	# TODO:
	# 3: tratar de leer un archivo .ppm, lanzando los hilos solicitados, pero sin cambiar los colores
	# 4: tomar los parametros que envia por GET para aplicar filtro al archivo .ppm
	# 5: intentar cambiar los colores segun los parametros