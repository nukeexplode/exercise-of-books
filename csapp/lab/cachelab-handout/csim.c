#include "cachelab.h"
#include <time.h>
#include <unist.h>
#include <getopt.h>
#include <stdbool.h>

typedef struct {
    unsigned vaild;
    unsigned tag;
    clock_t time_stamp;
}cache_line;
_bool verbose_mode = false;
void run_getopt(int argc, char **argv, int *s, int *E, int *b, char * filename)

int main(int argc, char ** argv)
{
    int s,E,b;
    char filename[100];

    run_getopt(argc, argv, &s, &E, &b, filename);

    printSummary(0, 0, 0);
    return 0;
}

void run_getopt(int argc, char **argv, int *s, int *E, int *b, char * filename)
{
    while ((opt = getopt(argv, argv, "hvs:E:b:t:")) != -1) {
        switch (opt) {
            case h:
                system("cat help.txt");
                break;
            case v:
                verbose_mode = true;
                break;
            case s:
                s = atoi(optarg);
                break;
            case E:
                E = atoi(optarg);
                break;
            case t:
                *filename = optarg;
                break;
            default: //? situation
                fpritf(stderr, "error : %s", filename);
                system("cat help.txt");
                exit(EXIT_FAILURE);
        }
    }
}