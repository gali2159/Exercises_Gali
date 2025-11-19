/*------------------------------------------------------
* Filename: median.c
* Description: The program reads a sequence of numbers until something is entered that is not a number and prints the median of the correct numbers entered.
* Author: Gali Amrani
-------------------------------------------------------*/
#include <stdio.h>
#include<stdlib.h>
#include <string.h>

#define MAX_DIGIT_INT 11 //The maximum number of digits possible in int

/*------------------------------------------------------
* Function Purpose - The function reads a sequence of numbers until something that is not a number is entered, and inserts them into an array.

*
* Parameters      - array- The array into which we will enter the numbers
*
* Return Values   - The number of numbers in the array and -1 in case of an error.
*
* Author          - Gali Amrani
-------------------------------------------------------*/
int reads_numbers(int *array)
{
    int array_size=0;
    int reads=1;
    char input[MAX_DIGIT_INT]={'\0'};

    printf("Enter numbers: ");
    do{
        char sign='\0';
        int i=0;
        int num=0;
        int negative=0;

        scanf("%s", input);
        sign=input[i];

        //Checks if the characters are correct
        while(sign != '\0'){
            if(!((sign>='0' && sign<='9') || (sign=='-' &&  i==0 ))){
                reads=0;
                break;
            }
            i++;
            sign=input[i];
        }
        if(reads==0){
            break;
        }
        reads=1;

        //Converts to a number
        for(i=0;input[i] != '\0'; i++)
        {
            sign=input[i];
            switch(sign){
            case '-':
                negative=1;
                break;
            case '0':
                num*=10;
                break;
            case '1':
                num=num*10+1;
                break;
            case '2':
                num=num*10+2;
                break;
            case '3':
                num=num*10+3;
                break;
            case '4':
                num=num*10+4;
                break;
            case '5':
                num=num*10+5;
                break;
            case '6':
                num=num*10+6;
                break;
            case '7':
                num=num*10+7;
                break;
            case '8':
                num=num*10+8;
                break;
            case '9':
                num=num*10+9;
                break;
            default:
                printf("ERROR");
                return -1;
            }

        }
        if(negative){
            num=num*-1;
        }

        if(array_size!=0){
            array=(int*)realloc(array, (array_size+1)*sizeof(int));
            if(array==NULL){
                printf("ERROR IN REALLOC");
                return -1;
            }
        }
        //Puts in the array
        array[array_size]=num;
        array_size++;
    }while(reads);

    return array_size;

}

float calculate_the_median(int *array, int array_size){
    int *sort_array=(int*)malloc(array_size*sizeof(int));
    if(sort_array==NULL)
    {
        printf("ERROR WITH MALLOC");
        return 1;
    }
    float median=-1;
    int *success=memcpy(sort_array,array,array_size*sizeof(int));

    for(int i=0;i<array_size;i++){
        for(int j=1; j<array_size-i;j++)
        {
            if(sort_array[j-1]>sort_array[j]){
                int temp=sort_array[j];
                sort_array[j]=sort_array[j-1];
                sort_array[j-1]=temp;
            }
        }
    }

    if(array_size%2==0){
        median=(float)(sort_array[array_size/2]+sort_array[array_size/2 -1])/2;
    }
    else{
        median=sort_array[array_size/2];
    }
    free(sort_array);
    return median;
}

int main(){
    int array_size=0;
    int *array=NULL;
    float median=0.0;

    array=(int*)malloc(sizeof(int));
    if(array==NULL){
        printf("ERROR IN MALLOC");
        return 0;
    }
    array_size=reads_numbers(array);
    if(array_size==-1){
        printf("ERROR IN READ");
        return 0;
    }

    printf("The numbers is: ");
    for(int i=0; i<array_size;i++){
        printf(" %d", array[i]);
    }

    median=calculate_the_median(array,array_size);
    if(median==-1){
        printf("ERROR IN CALCUL
            ATE THE MEDIAN");
        return 0;
    }
    printf("\nThe median of the numbers is: %.2f", median);


    free(array);
   
}