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
    Test function for closestgroup(int nelem, float elem[][NFEAT], float cent[][NFEAT], int *grind) returns void;
    expected => expected grind values grind[MAXELE]
    actual => obtained grind values
    testName => name of the test
*/
// void testClosestgroup(int *expected, int *actual, const char *testName)
// {
//     if (expected == actual)
//     {
//         printf("\n%s PASSED", testName);
//     }
//     else
//     {
//         //printf("\n%s FAILED expected: %f actual: %f", testName, expected, actual);
//     }
// }
//Loads elem[][NFEAT] with data
// void loadElem(float *elem[][NFEAT])
// {
// }
// //Loads cent[][NFEAT]
// void loadCent(float *cent[][NFEAT])
// {
// }