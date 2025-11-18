/*------------------------------------------------------
* Filename: array_sort.c
* Description: The program reads 10 characters and puts them in an array of numbers. The program has another array of pointers that points to each cell in the previous array, and what the program does is sort it by the numbers it read.
* Author          - Gali Amrani
-------------------------------------------------------*/
#include <stdio.h>

#define ARRAY_SIZE 10 //size of the arrays

/*------------------------------------------------------
* Function Purpose - Swap the addresses between the pointers - so that each one points for what the other one points for
*
* Parameters      - 2 pointers who want to change their addresses
*
* Return Values   - nothing
*
* Author          - Gali Amrani
-------------------------------------------------------*/
void swap(int **p, int **q){
    int *temp=*p;
    *p=*q;
    *q=temp;
}

/*------------------------------------------------------
* Function Purpose - Print the addresses in each cell of the array in addition to what is in those addresses
*
* Parameters      - Array of pointers
*
* Return Values   - nothing
*
* Author          - Gali Amrani
-------------------------------------------------------*/
void prints_pointers_array(int *array[ARRAY_SIZE]){

    for(int i=0; i<ARRAY_SIZE;i++){
        printf("0x%X: ", array[i]);
        if (i!=ARRAY_SIZE-1)
            printf("%d, ", *(array[i]));
        else
            printf("%d\n", *(array[i]));
    }
}
int main(){
    int numbers[ARRAY_SIZE];
    int *pointers[ARRAY_SIZE];

    for(int i=0;i<10;i++){
        pointers[i]=(numbers+i);
    }

    printf("Enter 10 numbers: ");
    for(int i=0;i<ARRAY_SIZE;i++){
        scanf("%d", &numbers[i]);

    }


    printf("before the sort: \n");
    prints_pointers_array(pointers);


    for(int i=0;i<ARRAY_SIZE;i++){
        for(int j=0;j<ARRAY_SIZE-i-1;j++){
            if(*(pointers[j])>*(pointers[j+1])){
                swap(&(pointers[j]),&(pointers[j+1]));
            }

        }
    }

    printf("After the sort:\n");
    prints_pointers_array(pointers);

}