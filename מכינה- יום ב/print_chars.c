#include <stdio.h>

void prints_char(char sign, int number){
    if(number==0)
        return;
    printf("%c", sign);
    prints_char(sign, number-1);
}

void prints_square(char sign, int rows,int number){
    if(rows==0)
        return;
    prints_char(sign,number);
    printf("\n");
    prints_square(sign, rows-1,number);
}
int main(){
    float number_input=0.0;
    int number=0;
    char sign;
    printf("Enter a positive integer.");
    scanf("%f", &number_input);
    number=number_input;
    if((number_input-number)||(number_input<0)){
        printf("Bad Input!\n");
        return 0;
    }
    if(number%2==0){
        sign='*';
    }
    else if(number%3==0){
        sign='^';
    }
    else if(number%5==0){
        sign='%';
    }
    else{
        sign='@';
    }
    prints_square(sign, number, number);

}