#!/usr/bin/python3

## TP4 - Cintia Ossandon ( Intento 'aiohttp' )

from aiohttp import web
import argparse
import os
import sys
import logging

# default level of WARNING
logging.basicConfig(level=logging.DEBUG)
#logging.basicConfig(filename="test.log", level=logging.DEBUG)

# /
async def index(request):
	await logconexion()

	html = '<html>'
	html += '	<head>'
	html += '		<title>Directorio WEB</title>'
	html += '		<link data-rh="true" rel="icon" href="https://cdn-static-1.medium.com/_/fp/icons/favicon-rebrand-medium.3Y6xpZ-0FSdWDnPM3hSBIA.ico" />'
	html += '	</head>'
	html += '	<body>'
	html += '		<p>Directorio:</p>'
	html += '		<ul>'
	for base, dirs, files in os.walk("."):
		for file in files:
			html += '	<li><a href="' + file + '">' + file + '</a></li>'
	html += '		</ul>'
	html += '	</body>'
	html += '</html>'
	html = bytearray(html, 'utf8')

	status = '200 OK'
	headers = {'Content-type': 'text/html', 'Status': status}

	return web.Response(body=html, headers=headers)

# /page.ext
async def handle(request):
	await logconexion()

	page = request.match_info.get('name', "Anonymous")
	size = 1000 # TODO: tomarlo de la variable

	pos  = page.rfind('.', 0, len(page))+1
	ext = page[pos:len(page)]

	# si existe el archivo
	if os.path.isfile(page) == True:
		status = '200 OK'
		if ext == 'jpg':
			# mostrar imagen
			headers = {'Content-type': 'image/jpeg', 'Status': status}
		elif ext == 'pdf':
			# mostrar documento pdf
			headers = {'Content-type': 'application/pdf', 'Status': status}
		elif ext == 'html':
			# mostrar documento html
			headers = {'Content-type': 'text/html', 'Status': status}
		elif ext == 'ppm':
			# descargar imagen ppm
			headers = {'Content-type': 'image/x-portable-pixmap', 'Status': status}
	else:
		status = '404 Not Found'
		page = "error.html"
		headers = {'Content-type': 'text/html', 'Status': status}

	fd = os.open(page, os.O_RDONLY)
	temp = os.read(fd, size)
	body = b""
	while temp:
		body = bytearray(body + temp)
		temp = os.read(fd, size)
	os.close(fd)

	return web.Response(body=body, headers=headers)

# TODO:
async def wshandle(request):
	ws = web.WebSocketResponse()
	await ws.prepare(request)

	async for msg in ws:
		print(msg.data)
		#if msg.type == web.WSMsgType.text:
		#	await ws.send_str("Hello, {}".format(msg.data))
		#elif msg.type == web.WSMsgType.binary:
		#	await ws.send_bytes(msg.data)
		#elif msg.type == web.WSMsgType.close:
		#	break

	#text = "Hello, " + page
	#return web.Response(text=text)
	return ws

async def all_handler(request):
	return web.Response(text="Hello, world")

async def logconexion():
	logging.debug("Logueando Conexion")
	# TODO: loguear conexiones
	#fd = os.open('registro', os.O_CREAT | os.O_APPEND)
	#os.write(fd, 'logueando algo...')
	#os.close(fd)

# --------------- MAIN() --------------- 

parser = argparse.ArgumentParser()
parser.add_argument('-p', '--port PORT', action="store", dest="port", metavar="puerto de conexion", type=int, required=True, help="Puerto en donde espera conexiones nuevas")
parser.add_argument('-s', '--size SIZE', action="store", dest="bytes", metavar="bloque de lectura", type=int, required=True, help="Bloque de lectura máxima para los documentos")
parser.add_argument('-d', '--document-root DOCUMENT', action="store", dest="path", metavar="directorio", type=str, required=False, help="Directorio donde estan los documentos web")

args = parser.parse_args()
size = args.bytes
port = args.port
path = ""

if (args.path != ""):
	path = args.path

app = web.Application()
app.add_routes([web.get('/', index),
				web.get('/echo', wshandle),
				#web.get('/*/path', all_handler),
				web.get('/{name}', handle)])

if __name__ == '__main__':
	web.run_app(app, port=port)