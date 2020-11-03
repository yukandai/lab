#!/usr/bin/python3

import os
import asyncio 
#from urllib.parse import urlparse

async def handle_echo(reader, writer):
    data = await reader.read(100)
    request = data.split(b'\r\n')

	encabezado = data.decode().splitlines()[0] 	# GET /pagina.html HTTP/1.1
	archivo = encabezado.split()[1]				# /pagina.html
	http = encabezado.split()[2]				# HTTP/1.1

    addr = writer.get_extra_info('peername')

    logger = asyncio.create_task(complementarias.mostrar_direccion(addr,directorio))
    peticion = asyncio.create_task(devolver_peticion(request_recibida,writer,directorio,cantidad_lectura))

    await logger
    await peticion

    writer.close()

async def handle(self):
	#data = await reader.read(100)

	data  = self.request.recv(1024)
	encabezado = data.decode().splitlines()[0] # GET /pagina.html HTTP/1.1
	archivo = encabezado.split()[1] 			# /pagina.html
	http = encabezado.split()[2]					# HTTP/1.1

	fd = os.open(archivo, os.O_RDONLY)
	temp = os.read(fd, self.server.size)
	body = b""
	while temp:
		body = bytearray(body + temp)
		temp = os.read(fd, self.server.size)
	os.close(fd)

	ctype = "Content-type: text/html"
	clength = "Content-length: " + str(len(body)) 
	header = bytearray(http + "\r\n" + ctype + "\r\n" + clength + "\r\n\r\n", "utf8")

	respuesta = header + body	 # respuesta = self.request.sendall(enviado.upper())
	self.request.send(respuesta) # self.request.send(pickle.dumps(respuesta))

	#writer.close()

# TP3
async def handleTP3(self):
	try:
		response = {
			'200' : '200 OK',
			'400' : '400 Bad Request',
			'404' : '404 Not Found',
			'500' : '500 Internal Server Error' }

		logging.debug("Nueva Conexion: ({})".format(self.client_address))

		# TODO: usar urlparse
		# req = urlparse("http://www.algo.com")
		# req.hostname("www.algo.com")
		# req.query (parametros)

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

		# TODO: validar antes de buscar si existe el achivo que sea uno que soportemos (ej: tp3.py)
		if self.isIndexFile() == True or os.path.isfile(self.archivo) == True:
			# si es el index o existe el archivo
			http += " " + response['200']
		else:
			# si no existe el archivo pedido
			http += " " + response['404']
			self.archivo = "./error.html"

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
				# self.request.send(header)
				while temp:
					# TODO: aca podemos escribir directamente en el socket
					# respuesta = self.body
					# self.request.send(body)
					self.body = bytearray(self.body + temp)
					temp = os.read(fd, self.server.size)
				os.close(fd)

		logging.debug("Procesando respuesta...")

		ctype = "Content-type: " + self.getContentType()
		# podemos leer la long del archivo al comienzo
		clength = "Content-length: " + str(len(self.body)) 
		header = bytearray(http + "\r\n" + ctype + "\r\n" + clength + "\r\n\r\n", "utf8")

		respuesta = header + self.body	 # respuesta = self.request.sendall(enviado.upper())
		self.request.send(respuesta) 	 # self.request.send(pickle.dumps(respuesta))

		#print("Close the connection")
    	#writer.close()

	except Exception as e:
		raise e

# TP3
async def getExtensionFile(self):
''' Devuelve la extension del archivo pedido '''
	pos  = self.archivo.rfind('.', 0, len(self.archivo))+1
	ext = self.archivo[pos:len(self.archivo)]
	return ext

# TP3
async def getContentType(self):
''' Devuelve el content-type segun archivo '''
	pos  = self.archivo.rfind('.', 0, len(self.archivo))+1
	tipo = self.archivo[pos:len(self.archivo)]

	content = {
		'html': 'text/html', 
		'pdf' : 'application/pdf',
		'jpg' : 'image/jpeg',
		'ppm' : 'image/x-portable-pixmap' }

	return content[tipo]

# TP3
async def isIndexFile(self):
''' Me indica si el archivo a ser mostrado es el index '''
	pos  = self.archivo.rfind('/', 0, len(self.archivo))+1
	fileName = self.archivo[pos:len(self.archivo)]

	if (fileName == 'index.html'):
		return True
	else:
		return False

# TP3
def generateIndex(self):
''' Recorremos todos los directorios y archivos bajo un path '''
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

	generateIndex = asyncio.create_task(complementarias.mostrar_direccion(addr,directorio))

    await generateIndex

    writer.close()

	return self.body

# Intento 'aiohttp'
'''
import os
from aiohttp import web
from urllib.parse import urlparse

async def index(request):
	text = '<ul>'
	for base, dirs, files in os.walk('.'):
		for file in files:
			text += '<li>' + file + '</li>'
	text += '</ul>'
	return web.Response(text=text)

async def handle(request):
	page = request.match_info.get('name', "Anonymous")
	text = "Hello, " + page
	return web.Response(text=text)

async def wshandle(request):
	ws = web.WebSocketResponse()
	await ws.prepare(request)

	async for msg in ws:
		if msg.type == web.WSMsgType.text:
			await ws.send_str("Hello, {}".format(msg.data))
		elif msg.type == web.WSMsgType.binary:
			await ws.send_bytes(msg.data)
		elif msg.type == web.WSMsgType.close:
			break

	return ws
'''