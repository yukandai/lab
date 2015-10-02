#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "etc.h"
#include <sys/types.h>
#include <sys/socket.h>

int get_line (int cli_sock, char *buf, int size){

 int i = 0;
 char c = '\0';
 int n;

 while ((i < size - 1) && (c != '\n'))
 {
  n = read(cli_sock, &c, 1);
  if (n > 0)
  {
   if (c == '\r')
   {
    n = recv(cli_sock, &c, 1, MSG_PEEK);
    if ((n > 0) && (c == '\n')){
        read(cli_sock, &c, 1);
        }else{
     c = '\n';}
   }
   buf[i] = c;
   i++;
  }
  else
   c = '\n';
 }
 buf[i] = '\0';
 return(i);

}
