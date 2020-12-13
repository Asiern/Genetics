#include "stdio.h"
#include "../fungg_s.c"
#include "test_functions.h"

int main(void)
{
    //TEST gendist(float, float)
    float elem1 = 0.0;
    float elem2 = 5.0;
    float elem3 = 20.0;
    printf("----- Testing gendist -----");
    testGendist(20.0, gendist(&elem1, &elem3), "0, 20");
    testGendist(15.0, gendist(&elem2, &elem3), "20, 5");
    testGendist(20.0, gendist(&elem3, &elem1), "20, 0");
    printf("\n");

    //TEST closestgroup(int, float, float, int)
    printf("\n----- Testing closestgroup -----");
    printf("\n");
    return 0;
}