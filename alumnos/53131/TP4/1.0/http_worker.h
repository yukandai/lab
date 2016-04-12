#ifndef HTTP_H_

    #define HTTP_H_

        struct size{
            int buff;
            int method_url;
            int path;
        };
        int http_worker (int,  struct sockaddr*);
        void parse_and_frac (struct size*, char *, char*, char*, char*);  
        void mensajes (int, int, char*);
        int ext_arch (int , struct size*, char*, char*, char*);

        
        

                                                        
#endif
