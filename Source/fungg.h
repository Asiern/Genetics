/*
   fungg.h
   headers of the functions used in gengroups_s.c
***************************************************************/

extern double gendist(float *elem1, float *elem2);
extern void closestgroup(int nelem, float elem[][NFEAT], float cent[][NFEAT], int *grind);
extern void compactness(float elem[][NFEAT], struct ginfo *iingrs, float *compact);
extern void diseases(struct ginfo *iingrs, float dise[][TDISEASE], struct analysis *disepro);
