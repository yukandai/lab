/*****************************************************************/
/**                         PROTOTIPOS                          **/
/*****************************************************************/

void agregar_al_registro(char *pal, int *reg);

void armar_palabra(int *fdh);


//char *to_uppercase(char *word, char *palabra);

char *revisar_palabra(char *pal, char *reservada);

int openFile(char *file_name);

char *revisar_linea(char *line, int length, char *pal_reservada);

void reemplazar_palabra(int *fdh, char *palabra);