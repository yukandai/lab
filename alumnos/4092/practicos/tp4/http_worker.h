void http_worker(int, void *);

typedef struct DIRECCION{
	char arch[256];
	char ext[256];
	char mime[256];
	char ruta[256];
	long len;
} direccion;

direccion datosDireccion(char *);
