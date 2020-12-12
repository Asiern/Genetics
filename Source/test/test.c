#include "stdio.h"
#include "../fungg_s.c"
#include <math.h>
#include <float.h>

/*
    Test function for gendist(float *elem1, float *elem2) returns double;
    expected => expected value to be returned by the function
    actual => value returned by the function
    testName => name of the test
*/
void testGendist(double expected, double actual, const char *testName)
{
    if (expected == actual)
    {
        printf("\n%s PASSED", testName);
    }
    else
    {
        printf("\n%s FAILED expected: %f actual: %f", testName, expected, actual);
    }
}

int main(void)
{
    //TEST gendist(float, float)
    float elem1 = 0.0;
    float elem2 = 5.0;
    float elem3 = 20.0;
    testGendist(20.0, gendist(&elem1, &elem3), "0, 20");
    testGendist(15.0, gendist(&elem2, &elem3), "20, 5");
    testGendist(20.0, gendist(&elem3, &elem1), "20, 0");

    //TEST closestgroup(int, float, float, int)
    return 0;
}