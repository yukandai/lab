#include "editMessage.h"

void help(){
	char *title  = "======================================== TP 1 - Compu2 ========================================\n\n";
	char *title2 = "Opciones de compilación:\n";
	char *comp   = "\t-$ cat mensaje.txt | ./tp1 -h\n\t-$ cat mensaje.txt | ./tp1 palabrafiltrar1 palabrafiltrar2 ...\n\t-$ cat mensaje.txt | ./tp1 -o mensaje-filtrado.txt palabrafiltrar1 palabrafiltrar2 ...\n\n"; 
	char *text   = "Para ejecurtar el programa debe ingregar el nombre del archivo \nque contenga el mensaje a analizar, luego | ./tp1 para mostrar\nel resultado por consola o el nombre del archivo que contiene el \nmensaje | ./tp1 -o nombre del archivo donde lo quiere guardar.\n\n";
	char *footer = "===============================================================================================\n\n";

	write(1, title, strlen (title));
	write(1, title2, strlen (title2));
	write(1, comp, strlen (comp));
	write(1, text, strlen (text));
	write(1, footer, strlen (footer));

}
