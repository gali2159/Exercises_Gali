/*------------------------------------------------------
* Filename: dynamic_struct.c
* Description: The program reads 2 times and calculates their sum.
* Author: Gali Amrani
-------------------------------------------------------*/
#include<stdio.h>
#include <stdlib.h>
typedef struct{
    int hours;
    int minutes;
    int seconds;
}time;

/*------------------------------------------------------
* Function Purpose - The function receives 2 times and connects them.
*
* Parameters      - 2 times
*
* Return Values   - the sum of the times
*
* Author          - Gali Amrani
-------------------------------------------------------*/
time* calculate_sum_times(time *time1, time *time2){
    time *sum_time=(time*) malloc(sizeof(time));
    if(sum_time==NULL){
        return NULL;
    }
    sum_time->seconds = time1->seconds+time2->seconds;
    sum_time->minutes = time1->minutes+ time2->minutes;
    sum_time->minutes += sum_time->seconds/60;
    sum_time->seconds %=60;
    sum_time->hours = time1->hours+time2->hours;
    sum_time->hours += sum_time->minutes/60;
    sum_time->minutes %= 60;
    sum_time->hours %=24;
    return sum_time;

}
int main(){
    time *times=(time*) malloc(2*sizeof(time));
    if(times==NULL)
        return -1;
    for(int i=0;i<2;i++){
        while(1){
            printf("Enter hour: ");
            scanf("%d", &(times[i].hours));
            if(times[i].hours>=0 && times[i].hours<=23){
                break;
            }
            printf("ERROR\n");
        }
        while(1){
            printf("Enter minutes: ");
            scanf("%d", &(times[i].minutes));
            if(times[i].minutes>=0 && times[i].minutes<=59){
                break;
            }
            printf("ERROR\n");
        }
        while(1){
            printf("Enter seconds: ");
            scanf("%d", &(times[i].seconds));
            if(times[i].seconds>=0 && times[i].seconds<=59){
                break;
            }
            printf("ERROR\n");
        }
    }

    printf("The sum of times is: ");
    time *newtime=calculate_sum_times(&times[0], &times[1]);
    if(newtime==NULL){
        printf("ERROR\n");
        return -1;
    }
    printf("%d:%d:%d", newtime->hours, newtime->minutes, newtime->seconds);

    free(newtime);
    free(times);
}