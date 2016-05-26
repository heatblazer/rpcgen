#include  <stdio.h>
#include "msg.h"


int* printmessage_1(char** msg, struct CLIENT* cli)
{
    (void)cli;
    static int result;
    FILE* f = fopen("/dev/console", "w");
    if (f == (FILE*)NULL) {
        result =0;
        return &result;
    }

    fprintf(f, "%s\n", *msg);
    fclose(f);
    result = 1;
    return &result;

}

int* printmessage_1_svc(char** msg, struct svc_req* req)
{


    (void)req;
    static int result;
    FILE* f = fopen("/dev/console", "w");
    if (f == (FILE*)NULL) {
        result =0;
        return &result;
    }

    fprintf(f, "%s\n", *msg);
    fclose(f);
    result = 1;
    return &result;
}
