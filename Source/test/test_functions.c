#include "stdio.h"
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

/*
    Test function for closestgroup(int nelem, float elem[][NFEAT], float cent[][NFEAT], int *grind, int size) returns void;
    expected => expected grind values grind[MAXELE]
    actual => obtained grind values
    testName => name of the test
    size => size of verctor
*/
void testClosestgroup(int *expected, int *actual, const char *testName, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (expected[i] != actual[i])
        {
            printf("\n%s FAILED expected: %d actual: %d on index %d", testName, expected[i], actual[i], i);
            break;
        }
    }
    printf("\n%s PASSED", testName);
}