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
    char arr1[] = {'H','E','Y','!'};
    char* arr2 = map(arr1, 4, replaceChar);
    printf("%s\n", arr2);
    free(arr2);
}
