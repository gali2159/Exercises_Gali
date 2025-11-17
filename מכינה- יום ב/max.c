/*------------------------------------------------------
* Filename: max.c
* Description: The program initializes 2 numbers and prints the higher of them.
* Author: Gali Amrani
-------------------------------------------------------*/

#include <stdio.h>
int main(void){
    int x=5;
    int y=7;
    int z=x*(x>y)+y*(x<=y);
    printf("%d", z);
    return 0;
}