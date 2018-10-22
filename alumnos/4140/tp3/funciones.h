/*****************************************************************/
/**                         PROTOTIPOS                          **/
/*****************************************************************/

void contar_palabras(char *memo, char *mensaje);

// char *revisar_palabra(char *pal, char *reservadas[]);

int abrir_archivo(char *file_name);

void reemplazar_palabra(char *memo, char *reservadas[], sem_t *sema2);

/** TEST */
void saludo(char *mensaje);
