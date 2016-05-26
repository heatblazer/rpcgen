#include <stdio.h>
#include <stdlib.h>
#include "msg.h"

int main(int argc, char** argv) 
{


    CLIENT* clnt;
    char*   server;
    char*   message;
    int*    result;


    if (argc != 3) {
        exit(1);
    }

    server =    argv[1];
    message =   argv[2];

    clnt = clnt_create(server, MESSAGEPROG, PRINTMESSAGEVERS,
                        "visible");

    if (clnt == (CLIENT*)NULL) {
        clnt_perror(clnt, server);
        exit(1);
    }
    
    result = printmessage_1(&message, clnt);
    if (*result == 0) {
        clnt_perror(clnt, server);
        exit(1);
    }

    clnt_destroy(clnt);
    exit(0);
}


