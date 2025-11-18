#include<stdio.h>

void rotates_array(int array[26], int num_rotation){
    int new_array[26]={0};
    for(int i=0;i<26;i++){
        int j=(i-num_rotation+26)%26;
        new_array[i]=array[j];
    }

    for (int i=0;i<26;i++){
        array[i]=new_array[i];
    }
}

void prints_array(int array[26])
{
    for(int i=0;i<26;i++)
        printf("%d, ", array[i]);

    printf("\n\n\n");
}
int main(){
    int message[26]={0};
    char encryptin_message[27]="\0";

    printf("Enter the message:\n");

    for(int i=0;i<26;i++){
        scanf("%d", &message[i]);
    }

    //The first and last halves of the array are swapped.
    for(int i=0;i<13;i++){
        int temp=message[i];
        message[i]=message[13+i];
        message[13+i]=temp;
    }
    prints_array(message);


    //Each cell is reduced by the value of the cell before it (except for the first cell, which has no previous cell).
    for(int i=25;i>0;i--){
        message[i]-=message[i-1];
    }
    prints_array(message);


    //Each element is moved 5 cells forward, in a circular fashion.
    rotates_array(message, 5);
    prints_array(message);

    //Each element in an even place in the array is divided by 7
    for(int i=0;i<26;i+=2){
        message[i]/=7;
    }
    prints_array(message);

    //Each element moves 4 cells back, in a circular fashion.
    rotates_array(message,-4);

    prints_array(message);

    //Each value is reduced by 5
    for(int i=0;i<26;i++){
        message[i]-=5;
    }

    prints_array(message);

    //Each value is converted to the corresponding character.
    for(int i=0; i<26;i++)
    {
        encryptin_message[i]=message[i];
    }
    prints_array(message);

    printf("%s", encryptin_message);

    
    return 0;
}