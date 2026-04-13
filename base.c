#include <stdlib.h>
#include <stdio.h>
#include <string.h>


char replaceChar(char c){
    if(c == 'H'){
        return 'B';
    }
    if(c == 'E'){
        return 'Y';
    }
    if(c == 'Y'){
        return 'E';
    }
    return c;
}

char my_get(char c){
    return (char)fgetc(stdin);
}

char cxprt(char c){
    if(c >= 0x20 && c <= 0x7E){
        printf("%c", c);
    }
    else{
        printf(".");
    }
    printf(" %x\n", c);
    return c;
}

char encrypt(char c){
    if(c == 0x7F){
        return 0x20;
    }
    if(c>= 0x20 && c < 0x7F){
        return c+1;
    }
    return c;
}

char decrypt(char c){
    if(c == 0x20){
        return 0x7F;
    }
    if(c> 0x20 && c <= 0x7F){
        return c-1;
    }
    return c;    
}

char dprt(char c){
    printf("%d\n", c);
    return c;
}

char* map(char *array, int array_length, char (*f) (char)){
    char* mapped_array = (char*)(malloc(array_length*sizeof(char)));
    /* TODO: Complete during task 2.a */
    for(int i=0; i< array_length; i++){
        mapped_array[i] = (*f)(*(array+i));  
    }
    return mapped_array;
}
 
int main(int argc, char **argv){
  /* TODO: Test your code */
    int base_len = 5;
    char arr1[base_len];
    char* arr2 = map(arr1, base_len, my_get);
    char* arr3 = map(arr2, base_len, dprt);
    char* arr4 = map(arr3, base_len, cxprt);
    free(arr2);
    free(arr3);
    free(arr4);

    return 0;
}
