#!/usr/bin/python3

## TP3 - Cintia Ossandon

from socketserver import *
import argparse
import functions as fun
import logging

# default level of WARNING
logging.basicConfig(level=logging.DEBUG)
# logging.basicConfig(filename="test.log", level=logging.DEBUG)

def main():
	try:
		parser = argparse.ArgumentParser()
		parser.add_argument('-p', '--port PORT', action="store", dest="port", metavar="puerto de conexion", type=int, required=True, help="Puerto en donde espera conexiones nuevas")
		parser.add_argument('-s', '--size SIZE', action="store", dest="bytes", metavar="bloque de lectura", type=int, required=True, help="Bloque de lectura máxima para los documentos")
		parser.add_argument('-d', '--document-root DOCUMENT', action="store", dest="path", metavar="directorio", type=str, required=False, help="Directorio donde estan los documentos web")

		args = parser.parse_args()
		size = args.bytes
		port = args.port
		host = "localhost"

		# escuchamos en todas las direcciones q tenga mi PC (0.0.0.0) , ip addr sho (lista las ips)
		logging.debug("Inicio Conexion: PUERTO({})".format(port))

		# solo soportamos IPv4
		ForkingTCPServer.allow_reuse_address = True
		with ForkingTCPServer((host, port), fun.MyTCPHandler) as server:
			if (args.path != ""):
				server.base_path = args.path
			server.size = size
			server.serve_forever()

	except Exception as e:
		raise e

if __name__ == "__main__":
    main()