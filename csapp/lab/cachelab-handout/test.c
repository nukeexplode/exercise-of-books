#include "cachelab.h"
#include <stdio.h>
#include <time.h>
#include <getopt.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    unsigned vaild;
    unsigned tag;
    clock_t time_stamp;
}cache_line;

_Bool verbose_mode = false;
void run_getopt(int argc, char **argv, int *s, int *E, int *b, char (* filename)[100]);

int main(int argc, char ** argv)
{
    int s,E,b;
    char filename[100] = "1231231231";

    run_getopt(argc, argv, &s, &E, &b, &filename);
    //test getopt
    printf("%s",filename);

    // printSummary(0, 0, 0);
    return 0;

}

void run_getopt(int argc, char **argv, int *s, int *E, int *b, char (*filename)[100])
{
    int opt;
    while ((opt = getopt(argc, argv, "hvs:E:b:t:")) != -1) {
        switch (opt) {
            case 'h':
                system("cat help.txt");
                break;
            case 'v':
                verbose_mode = true;
                break;
            case 's':
                *s = atoi(optarg);
                break;
            case 'E':
                *E = atoi(optarg);
                break;
            case 'b':
                *b = atoi(optarg);
                break;
            case 't':
                fscanf(*filename, "%s", optarg);
                break;
            default: //? situation
                fprintf(stderr, "error : %s", filename);
                system("cat help.txt");
                exit(EXIT_FAILURE);
        }
    }
}