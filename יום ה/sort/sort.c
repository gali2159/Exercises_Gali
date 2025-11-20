/*------------------------------------------------------
* Filename: sort.c
* Description: The program reads 5 strings and sorts them by length and alphabetically and prints the results of the 2 sorts.
* Author: Gali Amrani
-------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

#define SIZE_STRING_ARRAY 5

/*------------------------------------------------------
* Function Purpose - The function reads a line of text securely
*
* Parameters       - arg     - the array we sorted
*                  - size    - the size of the array
*                  - compare - the function with which we will perform the comparison
*
* Return Value     - nothing
*
* Author           - Gali Amrani
-------------------------------------------------------*/
void sort (void** arg, int size, int (*compare) (const void*,const void*)){
    if(arg==NULL){
        printf_s("Error- no array sent to sort function\n");
        return;
    }
    if(compare==NULL){
        printf_s("Error- no function to do compare\n");
        return;
    }
    for(int i=0; i<size; i++){
        for(int j=1; j<size-i; j++){
            if (compare(arg[j-1],arg[j])>0){
                void *temp=arg[j];
                arg[j]=arg[j-1];
                arg[j-1]=temp;
            }
        }
    }
}

/*------------------------------------------------------
* Function Purpose - The function performs an alphabetical comparison.
*
* Parameters       - param     - parameter for comparison
*                  - param2    - parameter for comparison
*
* Return Value     - -2 - Error in one of the parameters
*                  -  1 - param > parm2
*                  - -1 - param < parm2
*                  -  0 - param == parm2
*
* Author           - Gali Amrani
-------------------------------------------------------*/
int compare_alphabetical(const void* param, const void* param2){
    if(param == NULL || param2 ==NULL){
        printf_s("Error with the parameters sent to the function\n");
        return -2;
    }
    char *obj1=(char*)param;
    char *obj2=(char*)param2;
    for(int i=0; (obj1[i]!='\0') && (obj2[i]!='\0');i++){
        if (obj1[i]>obj2[i]){
            return 1;
        }
        else if(obj1[i]<obj2[i]){
            return -1;
        }
    }
    return 0;
}

/*------------------------------------------------------
* Function Purpose - The function performs a comparison by length.
*
* Parameters       - param     - parameter for comparison
*                  - param2    - parameter for comparison
*
* Return Value     - -2 - Error in one of the parameters
*                  -  1 - param > parm2
*                  - -1 - param < parm2
*                  -  0 - param == parm2
*
* Author           - Gali Amrani
-------------------------------------------------------*/
int compare_length(const void* param, const void* param2){
    if(param == NULL || param2 ==NULL){
        printf_s("Error with the parameters sent to the function\n");
        return -2;
    }
    char *obj1=(char*)param;
    char *obj2=(char*)param2;
    int size1=0;
    int size2=0;
    while(obj1[size1]!='\0'){
        size1++;
    }
    while(obj2[size2]!='\0'){
        size2++;
    }
    if(size1>size2){
        return 1;
    }
    else if(size1<size2){
        return -1;
    }
    return 0;
}

/*------------------------------------------------------
* Function Purpose - the function reads a line of text securely
*
* Parameters       - nothing
*
* Return Value     - the string that was read
*
* Author           - Gali Amrani
-------------------------------------------------------*/
char* dyn_scanf(void){
    int size=0;
    char *buff;
    //minimum memory allocation- for character and '\0'
    buff=(char*) malloc (2*sizeof(char));
    if(buff==NULL){
        printf_s("ERROR- in malloc");
        return NULL;
    }


    do{
        //If something enters the buffer, it needs to be increased, so we will increase it by 1
        if(size !=0 ){
            buff=realloc(buff,(size+1)*sizeof(char));
            if(buff==NULL){
                printf_s("ERROR- in realloc");
                return NULL;
            }
        }
        //Insert one character from the input into the buffer
        char *input=fgets(&buff[size], 2, stdin);
        if(input==NULL){
            printf_s("ERROR- in fgets");
            return NULL;
        }
        size++;
    }while(buff[size-1]!='\n');
    buff[size-1]='\0';
    buff=realloc(buff,(size)*sizeof(char));
    if(buff==NULL){
        printf_s("ERROR- in realloc2");
        return NULL;
    }
    return buff;
}

/*------------------------------------------------------
* Function Purpose - the function prints the array
*
* Parameters      - array - the array we will print
*                 - size  - the size of the array
*
* Return Value   - nothing
*
* Author          - Gali Amrani
-------------------------------------------------------*/
void prints_array(char **array, int size){
    for(int i=0;i<size;i++){
        printf_s("%s", array[i]);
        if(i!=size-1){
            printf_s(",");
        }
    }
    printf_s("\n");
}
int main(){
    char *strings[SIZE_STRING_ARRAY];
    for(int i=0; i<SIZE_STRING_ARRAY; i++){
        strings[i]=NULL;
    }

    for(int i=0; i<SIZE_STRING_ARRAY; i++){
        printf_s("Enter %d string: ", i+1);
        strings[i]=dyn_scanf();
        if(strings[i]==NULL){
            return -1;
        }
    }

    sort((void**) strings, SIZE_STRING_ARRAY, compare_length);
    prints_array(strings, SIZE_STRING_ARRAY);

    sort((void**) strings, SIZE_STRING_ARRAY, compare_alphabetical);
    prints_array(strings, SIZE_STRING_ARRAY);

    for(int i=0; i<SIZE_STRING_ARRAY;i++){
        free(strings[i]);
    }
    return 0;

}