/*
    Test function for gendist(float *elem1, float *elem2) returns double;
    expected => expected value to be returned by the function
    actual => value returned by the function
    testName => name of the test
*/
extern void testGendist(double expected, double actual, const char *testName);
/*
    Test function for closestgroup(int nelem, float elem[][NFEAT], float cent[][NFEAT], int *grind) returns void;
    expected => expected grind values grind[MAXELE]
    actual => obtained grind values
    testName => name of the test
*/
extern void testClosestgroup(int *expected, int *actual, const char *testName, int size);