/*------------------------------------------------------
* Filename: dynamic_scanf.c
* Description: The program reads a line of text securely and prints what it has read.
* Author: Gali Amrani
-------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>


/*------------------------------------------------------
* Function Purpose - The function reads a line of text securely
*
* Parameters      - nothing
*
* Return Value   - the string that was read
*
* Author          - Gali Amrani
-------------------------------------------------------*/
char* dyn_scanf(void){
    int size=0;
    char *buff;
    printf("Enter a line: ");
    //minimum memory allocation- for character and '\0'
    buff=(char*) malloc (2*sizeof(char));
    if(buff==NULL){
        printf_s("ERROR");
        return NULL;
    }


    do{
        //If something enters the buffer, it needs to be increased, so we will increase it by 1
        if(size !=0 ){
            buff=realloc(buff,(size+1)*sizeof(char));
            if(buff==NULL){
                printf_s("ERROR");
                return NULL;
            }
        }
        //Insert one character from the input into the buffer
        char *input=fgets(&buff[size], 2, stdin);
        if(input==NULL){
            printf_s("ERROR");
            return NULL;
        }
        size++;
    }while(buff[size-1]!='\n');

    return buff;
}

int main(){
    char *string=dyn_scanf();
    if(string==NULL){
        return -1;
    }
    printf_s("%s", string);
    return 0;

}