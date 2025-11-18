
/*------------------------------------------------------
* Filename: array_series.c
* Description: The program reads 15 numbers and prints the array type.
* Author: Gali Amrani
-------------------------------------------------------*/

#include <stdio.h> 


#define INCREASING 1
#define DECREASING 2
#define CONSTANT 3
#define MESSED_UP 4

/*------------------------------------------------------
* Function Name   - checks_the_number_ratio
*
* Function Purpose - Determines the relationship between two numbers
*                     and returns whether the second number is greater,
*                     smaller, or equal to the first number.
*
* Parameters      - IN previous - the first number
*                   IN current  - the second number
*
* Return Values   - INCREASING  (1) if current > previous
*                   DECREASING  (2) if current < previous
*                   CONSTANT    (3) if current == previous
*
* Author          - Gali Amrani
-------------------------------------------------------*/
int checks_the_number_ratio(int previous, int current){
    if(previous<current)
        return INCREASING;
    if(previous>current)
        return DECREASING;
    return CONSTANT;

}

int main() {
    
    int numbers[15]={0};
    int array_type=0;
    printf("Please enter 15 numbers:\n");

    for(int i=0;i<15;i++){
        scanf("%d",&numbers[i]);
        if(i!=0){   
            if(i==1){
                array_type=checks_the_number_ratio(numbers[i-1],numbers[i]);
            }
            else if(array_type==MESSED_UP){
                continue;
            }
            else{
                if(array_type != checks_the_number_ratio(numbers[i-1],numbers[i]))
                    array_type=MESSED_UP; 
            }
        }
    }
    switch (array_type){
    case INCREASING:
        printf("The array is increasing");
        break;
    case DECREASING:
        printf("The array is decreasing");
        break;
    case CONSTANT:
        printf("The array is constant");
        break;
    case MESSED_UP:
        printf("The array is messed up");
        break;
    default:
        printf("ERROR");
    }
    return 0;
}