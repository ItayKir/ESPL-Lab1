#include <stdlib.h>
#include <stdio.h>
#include <string.h>

FILE* infile = NULL;
FILE* outfile = NULL;

int main(int argc, char **argv){
    infile=stdin;
    outfile=stdout;
    fputs("Select operation from the following menu:\n", outfile);

    while (1==1){
        char buff[10000];
        fgets(buff, 100, infile);
        if(feof(infile)){
            break;
        }
    }
    return 0;
}