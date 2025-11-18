/*------------------------------------------------------
* Filename: const_pointer.c
* Description: The program does something that is not allowed - it uses pointers to change the value of a constant variable.
* Author          - Gali Amrani
-------------------------------------------------------*/
#include<stdio.h>
int main(){
    const int channel=2;
    int new_channel=0;
    int *pointer=NULL;
    printf("the number of channel is: %d\n", channel);

    printf("Enter new channel: ");
    scanf("%d", &new_channel);

    pointer=(int*)&channel;
    *pointer=new_channel;

    printf("The new channel is: %d", channel);

    return 0;

}