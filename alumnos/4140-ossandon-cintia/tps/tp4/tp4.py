#!/usr/bin/python3

## TP4 - Cintia Ossandon

import asyncio 
import argparse
import functions as fun

async def main():
	parser = argparse.ArgumentParser()
	parser.add_argument('-p', '--port PORT', action="store", dest="port", metavar="puerto de conexion", type=int, required=True, help="Puerto en donde espera conexiones nuevas")
	parser.add_argument('-s', '--size SIZE', action="store", dest="bytes", metavar="bloque de lectura", type=int, required=True, help="Bloque de lectura máxima para los documentos")
	parser.add_argument('-d', '--document-root DOCUMENT', action="store", dest="path", metavar="directorio", type=str, required=False, help="Directorio donde estan los documentos web")

	args = parser.parse_args()
	size = args.bytes
	port = args.port
	host = "localhost"
	path = "/"

	if (args.path != ""):
		path = args.path

	#server = await asyncio.start_server(lambda r,w: fun.handle(reader, write, path, size), ('::','0.0.0.0'), port)
	server = await asyncio.start_server(fun.handle_echo, '127.0.0.1', port)
	addr = server.sockets[0].getsockname()

	#print(f'Serving on {addr}')

	async with server:
		#server.path = args.path
		#server.size = size
		await server.serve_forever()

if __name__ == '__main__':
	# prueba 1
	asyncio.run(main())
	
	# prueba 2
	#loop = asyncio.get_event_loop()
	#loop.run_until_complete(main())
	#loop.close()

	# prueba 3
	#loop = asyncio.get_event_loop()
	#asyncio.ensure_future(bug())
	#loop.run_forever()
	#loop.close()