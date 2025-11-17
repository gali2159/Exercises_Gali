/*------------------------------------------------------
* Filename: calc_price.c
* Description: The program will read data for a package (such as weight, length, and width) and calculate and print the package size in centimeters, the package weight in kilograms, and the package cost.
* Author: Gali Amrani
-------------------------------------------------------*/

#include<stdio.h>

#define POSTAGE 5.5
#define COST_PER_KILOGRAM 11
#define COST_PER_CENTIMETER 0.03
#define COST_SIZE_DIVIDED_BY_WEIGHT 0.01

int main(){
    int length=0, width=0;
    int weight=0;
    float cost=0.0;
    float weight_in_kilogram=0.0;
    float package_size_in_centimeter=0.0;
    printf("Enter the package length in millimeters: ");
    scanf("%d",&length);
    printf("Enter the package width in millimeters: ");
    scanf("%d",&width);
    printf("Enter the package weight in grams: ");
    scanf("%d",&weight);
    weight_in_kilogram=(float)weight/1000;
    package_size_in_centimeter=(float) length*width/100;
    cost=POSTAGE+COST_PER_KILOGRAM*weight_in_kilogram+COST_PER_CENTIMETER*package_size_in_centimeter+COST_SIZE_DIVIDED_BY_WEIGHT*package_size_in_centimeter/weight_in_kilogram;
    printf("The package size is: %.2f\n", package_size_in_centimeter);
    printf("The package weight is %.3f kilograms\n", weight_in_kilogram);
    printf("The package price is %.2f\n" , cost);
    return 0;

}