/*------------------------------------------------------
* Filename: print_value_addr.c
* Description: The program reads 2 arrays and prints the values ​​in them next to the cell address. Printing the arrays is implemented in 2 ways: by pointers and by [].
* Author: Gali Amrani
-------------------------------------------------------*/
#include<stdio.h>
int main(){
    int int_array[8];
    char char_array[8];

    printf("Enter 8 integers:\n");
    for(int i=0;i<8;i++){
        scanf("%d",&int_array[i]);
    }

    printf("Enter 8 characters:\n");
    for(int i=0; i<8; i++){
        scanf(" %c", (char_array+i));
    }

    printf("Printing an array of integers: ");
    for(int i=0; i<8;i++){
        printf("%X: ", (int_array+i));
        if(i!=7)
            printf("%d, ", *(int_array+i));
        else
            printf("%d", *(int_array+i));
    }

    printf("\nPrinting an array of chars: ");
    for(int i=0; i<8;i++){
        printf("%X: ", &char_array[i]);
        if (i!=7)
            printf("%c, ", char_array[i]);
        else
            printf("%c", char_array[i]);
    }

    return 0;
}