#include "http_worker.h"

void *http_worker(void *sd_conn_no_cast){
	
	int leido;
	int sd_conn = *(int *)sd_conn_no_cast;

	http_req_t *req = malloc(sizeof(*req));

		

	char buffer[1024];
	memset(buffer,0,sizeof(buffer));

	char *token = NULL;

	char *extension = NULL;

	if ((leido = read(sd_conn, buffer, sizeof(buffer))) > 0){
		
		//printf("%s\n",buffer);
		

		token = strtok(buffer, "/");
		strncpy(req->method, token, sizeof (req->method));
		printf("1 - %s\n",req->method);
		token = strtok(NULL, " ");
		strncpy(req->resource, token, sizeof (req->resource));
		printf("2 - %s\n",req->resource);
		token = strtok(NULL, "\n");		
		strncpy(req->version, token, sizeof (req->version));
		printf("3 - %s\n",req->version);
		printf("----------\n");
	
		extension = archivo_extension(req->resource);

		printf("4 - %s\n",extension);
	} // fin if leido

	


	exit(0);	
} // fin funcion
