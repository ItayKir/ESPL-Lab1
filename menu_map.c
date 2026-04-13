#include <stdlib.h>
#include <stdio.h>
#include <string.h>

FILE* infile = NULL;
FILE* outfile = NULL;

char my_get(char c);
char cxprt(char c);
char encrypt(char c);
char decrypt(char c);
char dprt(char c);

char* map(char *array, int array_length, char (*f) (char));

struct fun_desc {
    char *name;
    char index;
    char (*fun)(char);
};

void print_menu(struct fun_desc menu[]){
    int i =0;
    while(menu[i].name != NULL){
        printf("%s\n",menu[i].name);
        i++;
    }

    fputs("Enter the function index to run\n", outfile);
}

int menu(int argc, char **argv){
    infile=stdin;
    outfile=stdout;
    char arr[5] = "";
    char* carray = &arr[0];


    struct fun_desc menu[] = {
        { "<g>et String", 'g', my_get },
        { "print <d>ecimal", 'd', dprt },
        { "print char and <x>hex", 'x', cxprt },
        { "<e>ncrypt", 'e', encrypt },
        { "de<c>rypt", 'c', decrypt },
        { NULL, 0, NULL } // The required null terminator
    };

    fputs("Select operation from the following menu:\n", outfile);

    while (1==1){
        print_menu(menu);

        char buff[10000];
        fgets(buff, sizeof(buff), infile);
        if(feof(infile) || infile == NULL){
            break;
        }

        char user_index = buff[0];
        int i=0;
        while(menu[i].name != NULL){
            if(menu[i].index == user_index){
                carray = map(carray, sizeof(arr), menu[i].fun);
                break;
            }
            i++;
        }
    }
    return 0;
}