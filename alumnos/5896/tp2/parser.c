 #include "nieto.h"
 #include "hijo.h"
 #include "parser.h"

 
  char palabra1[50];
  char palabra2[50];
  char palabra3[50];
  char *ptr;


  int k=1;
 void palabras(char *palabras){
 char s2[4] = ",";
 
//   memset(palabra1, 0, sizeof palabra1);
//   memset(palabra2, 0, sizeof palabra2);
//   memset(palabra3, 0, sizeof palabra3);
    //  printf( "s1=%s\n", argv[2] );
 
      ptr = strtok( palabras, s2 );    // Primera llamada => Primer token
    //  printf( "%s\n", ptr );
           strcpy(palabra1,ptr);
      while( (ptr = strtok( NULL, s2 )) != NULL ){    // Posteriores llamadas
  //      printf( "%s\n", ptr );
 
           k++;
       if(k==2){
            strcpy(palabra2,ptr);
   }
 
   if(k==3){
            strcpy(palabra3,ptr);
   }
 
   }
 
   printf (" palabra1: %s \n",palabra1);
 
   printf (" palabra2: %s \n",palabra2);
   printf (" palabra3: %s \n",palabra3);
 
 
 
                 }
                                         




void filtrar()
{
//     int i;
   printf (" palabra1: %s \n",palabra1);
 
   printf (" palabra2: %s \n",palabra2);
   printf (" palabra3: %s \n",palabra3);
 
     int m,n,p;
     char filtrado[1024];
//     char palabra[1024]="hola";
    char *token;
	memset(filtrado, 0, sizeof filtrado);

     token = strtok(buff, " \n\t");
          m = strcmp(token,palabra1);
          n = strcmp(token,palabra2);
          p = strcmp(token,palabra3);
          if (m==0 || n==0 || p==0) {
                  token="****";
          }
          strcat(filtrado,token);
          strcat(filtrado," ");
          while( (token = strtok( NULL, " \n\t" )) != NULL ){
                  m = strcmp(token,palabra1);
          	  n = strcmp(token,palabra2);
          	  p = strcmp(token,palabra3);
                  if (m==0 || n==0 || p==0){
                          token="****";
                  }
                  strcat(filtrado,token);
                  strcat(filtrado," ");
          }
 
		   printf (" %s, %s, %s filtradas \n",palabra1,palabra2,palabra3);
 


                  write(hap[PIPE_WR],filtrado,strlen(filtrado));//envio al abuelo
                  close(han[PIPE_RD]);
                  close(hap[PIPE_WR]);

 }

void ROT13(){
 		  //fin de aplicado de ROT13 y enviando al padre
int c;
int e;
int j;
for (j = 0;j<leido;j++){
			 c=buff[j];

      {
          if(c >='A' && c <='Z')
          {
              if((e = c + 13) <= 'Z')
                 // putchar(e);
		buff[j]=e;
              else
              {
                     e = c - 13;
          //        putchar(e);
		buff[j]=e;
              }
          }
          else if(c >='a' && c <='z')
          {
              if((e= c + 13) <= 'z')
               //   putchar(e);
		buff[j]=e;
              else
              {
                  e = c - 13;
               //   putchar(e);
		buff[j]=e;
              }
          }
          else
            //  putchar(c);
		buff[j]=c;
     }
}


                  write(hap[PIPE_WR],buff,leido);//envio al padre
  
                  close(hap[PIPE_WR]);
                  close(pah[PIPE_RD]);


}
