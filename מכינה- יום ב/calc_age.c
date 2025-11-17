/*------------------------------------------------------
* Filename: calc_age.c
* Description: The program reads 2 dates - birthday date and current date and calculates and prints how old Gary is.
* Author: Gali Amrani
-------------------------------------------------------*/

#include<stdio.h>
#define DAY_IN_MONTH 30
#define DAY_IN_YEAR 365

int main(){
    int current_day=0, current_month=0, current_year=0;
    int birth_day=0, birth_month=0, birth_year=0;
    int age_day=0;
    float age_years=0.0,age_month=0.0;
    int days_until_birthday=0;
    int days_until_now=0;
    int days=0;

    printf("Enter current date: ");
    scanf("%d/%d/%d", &current_day, &current_month, &current_year);
    days_until_now=current_year*DAY_IN_YEAR+(current_month-1)*DAY_IN_MONTH+current_day;
    printf("Enter Gary's Birthday: ");
    scanf("%d/%d/%d", &birth_day, &birth_month, &birth_year);
    days_until_birthday=birth_year*DAY_IN_YEAR+(birth_month-1)*DAY_IN_MONTH+birth_day;
    days=days_until_now-days_until_birthday;
    age_years=(float) days/DAY_IN_YEAR;
    days %=DAY_IN_YEAR;
    age_month =(float) days/DAY_IN_MONTH;
    age_day= days%DAY_IN_MONTH;
    printf("Gary's age in days %d\n", age_day);
    printf("Gary's age in months %f\n", age_month);
    printf("Gary's age in years %f\n", age_years);
    return 0;
}