/*
   definegg.h
   Constants and structs used in files gengrops_s.c and fungg_s.c
*****************************************************************/

#define NUM_THREADS 24

#define MAXELE 230000 //number of elemts (samples)
#define NGROUPS 100   //number of clusters
#define NFEAT 40      //features of each instance
#define TDISEASE 20   //types of disease

#define DELTA 0.01 //convergence: minimum change in centroids
#define MAXIT 1000 //convergence: maximum number of iterations

struct ginfo // information about groups
{
   int members[MAXELE]; // members
   int size;            // number of elements
};

struct analysis // analysis of diseases
{
   float max, min; // maximum and minimum for each disease
   int gmax, gmin; // grous for maximums and minimums
};
